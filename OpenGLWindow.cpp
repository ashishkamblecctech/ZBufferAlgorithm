#include "stdafx.h"
#include "OpenGLWindow.h"

#include <QOpenGLContext>
#include <QOpenGLPaintDevice>
#include <QOpenGLShaderProgram>
#include <QPainter>
#include <QColorDialog>

#include "HermiteCurve.h"
#include "BezierCurve.h"
#include "Z_Buffer.h"
#include "BezierCurve.h"
#include "BSplineCurve.h"

OpenGLWindow::OpenGLWindow(const QColor& background, QWidget* parent) :
    mBackground(background),mClippingPolygon({}), mirrorEnabled_X(false), mirrorEnabled_Y(false)
{
    setParent(parent);
    setMinimumSize(300, 250);
    const QStringList list = {"vertexShader.glsl", "fragmentShader.glsl"};
    mShaderWatcher = new QFileSystemWatcher(list, this);    
    connect(mShaderWatcher, &QFileSystemWatcher::fileChanged, this, &OpenGLWindow::shaderWatcher);
}
OpenGLWindow::~OpenGLWindow()
{
    reset();
}

void OpenGLWindow::reset()
{
    makeCurrent();
    delete mProgram;
    mProgram = nullptr;
    delete mVshader;
    mVshader = nullptr;
    delete mFshader;
    mFshader = nullptr;
    mVbo.destroy();
    doneCurrent();

    QObject::disconnect(mContextWatchConnection);
}

void OpenGLWindow::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    mProgram->bind();

    QMatrix4x4 matrix;
    matrix.perspective(140.0f, 4.0f / 3.0f, 0.1f, 100.0f);
    matrix.translate(0, 0, -2);
    matrix.rotate(rotationAngle);

    if (num == 1) {
        mProgram->setUniformValue("mirrorEnabled_X", mirrorEnabled_X);
    }
    else if (num == 2) {
        mProgram->setUniformValue("mirrorEnabled_Y", mirrorEnabled_Y);
    }

    mProgram->setUniformValue(m_matrixUniform, matrix);
    mProgram->setUniformValue("r", r);
    mProgram->setUniformValue("g", g);
    mProgram->setUniformValue("b", b);

    addPoints();
    glVertexAttribPointer(m_posAttr,number, GL_FLOAT, GL_FALSE, 0, vertices.data());
    glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, colors.data());

    glEnableVertexAttribArray(m_posAttr);
    glEnableVertexAttribArray(m_colAttr);

    glDrawArrays(str, 0, vertices.size() / number);

    glDisableVertexAttribArray(m_posAttr);
    glDisableVertexAttribArray(m_colAttr);
}

void OpenGLWindow::addBezierCurve(std::vector<Point3D> points)
{
    BezierCurve bs(points);
    std::vector<Point3D> bezierPoints = bs.calculateBezier();

    // Ensure that there are at leabezierpoints in the B-spline curve
    if (bezierPoints.size() < 2) {
        // Handle the case where there are not enough points
        return;
    }

    // Create lines from the B-spline curve points
    for (int i = 0; i < bezierPoints.size() - 1; i++) {
        mLines.push_back(Line(bezierPoints[i], bezierPoints[i + 1]));
    }
    emit shapesUpdated();
}

void OpenGLWindow::addHermiteCurve(std::vector<Point3D> points)
{
    HermiteCurve bs(points);
    std::vector<Point3D> hermitePoints = bs.calculateHermite();

    // Ensure that there are at least two points in the B-spline curve
    if (hermitePoints.size() < 2) {
        // Handle the case where there are not enough points
        return;
    }

    // Create lines from the B-spline curve points
    for (int i = 0; i < hermitePoints.size() - 1; i++) {
        mLines.push_back(Line(hermitePoints[i], hermitePoints[i + 1]));
    }

    emit shapesUpdated();
}

void OpenGLWindow::initializeGL()
{
    QString vertexShaderSource = readShader("vertexShader.glsl");
    QString fragmentShaderSource = readShader("fragmentShader.glsl");

    initializeOpenGLFunctions();

    mProgram = new QOpenGLShaderProgram(this);
    mProgram->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
    mProgram->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);
    mProgram->link();
    m_posAttr = mProgram->attributeLocation("posAttr");
    Q_ASSERT(m_posAttr != -1);
    m_colAttr = mProgram->attributeLocation("colAttr");
   Q_ASSERT(m_colAttr != -1);
    m_matrixUniform = mProgram->uniformLocation("matrix");
    Q_ASSERT(m_matrixUniform != -1);
}

void OpenGLWindow::addTrianglePoints(std::vector<float>& p, std::vector<float>& c)
{
    for (int i = 0; i < p.size(); i++) {
        vertices.push_back(p[i]);
    }
    for (int i = 0; i < c.size(); i++) {
        colors.push_back(c[i]);
    }
    str = GL_POLYGON;
    number = 3;
    emit shapesUpdated();
}


void OpenGLWindow::addBSplineCurve(std::vector<Point3D>& points)
{
    BSplineCurve bs(3);
    std::vector<Point3D> bsplinePoints = bs.evaluate(points, 100);

    if (bsplinePoints.size() < 2) {
        return;
    }
    addCurveLines(bsplinePoints);
    emit shapesUpdated();
}


void OpenGLWindow::addCurveLines(const std::vector<Point3D>& points)
{
    for (int i = 0; i < points.size() - 1; i++) {
        mLines.push_back(Line(points[i], points[i + 1]));
    }
    emit shapesUpdated();
}

void OpenGLWindow::mouseMoveEvent(QMouseEvent* event) {
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();

    if (event->buttons() & Qt::LeftButton) {
        QQuaternion rotX = QQuaternion::fromAxisAndAngle(0.0f, 1.0f, 0.0f, 0.5f * dx);
        QQuaternion rotY = QQuaternion::fromAxisAndAngle(1.0f, 0.0f, 0.0f, 0.5f * dy);

        rotationAngle = rotX * rotY * rotationAngle;
        update();
    }
    lastPos = event->pos();
}

QString OpenGLWindow::readShader(QString filepath) {
    QFile file(filepath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return "Invalid Path";

    QTextStream stream(&file);
    QString line = stream.readLine();
    while (!stream.atEnd()) {
        line.append(stream.readLine());
    }
    file.close();
    return line;
}

void OpenGLWindow::shaderWatcher() {
    QString fragmentShaderSource = readShader("fragmentShader.glsl");
    QString vertexShaderSource = readShader("vertexShader.glsl");

    mProgram->release();
    mProgram->removeAllShaders();
    mProgram = new QOpenGLShaderProgram(this);
    mProgram->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
    mProgram->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);
    mProgram->link();
}

void OpenGLWindow::addPoints() {
    for (int j = 0; j < mLines.size(); j++) {
        vertices.push_back(mLines.at(j).p1().x());
        vertices.push_back(mLines.at(j).p1().y());
        vertices.push_back(mLines.at(j).p2().x());
        vertices.push_back(mLines.at(j).p2().y());
        float currentR = r;
        float currentG = g;
        float currentB = b;

        colors.push_back(currentR);
        colors.push_back(currentG);
        colors.push_back(currentB);

        colors.push_back(currentR);
        colors.push_back(currentG);
        colors.push_back(currentB);
}
}

void OpenGLWindow::toggleMirrorEffect_X()
{
    mirrorEnabled_X = !mirrorEnabled_X;
    num = 1;
    update();  // Trigger repaint
}

void OpenGLWindow::toggleMirrorEffect_Y()
{
    mirrorEnabled_Y = !mirrorEnabled_Y;
    num = 2;
    update();  // Trigger repaint
}

void OpenGLWindow::colorChanger()
{
    QColorDialog colorDialog(this);
    QColor selectedColor = colorDialog.getColor();

    if (selectedColor.isValid()) {
        // Set the selected color to the curves or store it for later use
        r = selectedColor.redF();
        g = selectedColor.greenF();
        b = selectedColor.blueF();
        emit shapesUpdated();  // Trigger an update to redraw the curves with the new color
    }
}