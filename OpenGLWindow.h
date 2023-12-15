#pragma once
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include "Point3D.h"
#include "Triangle.h"
#include "Triangulation.h"

class QOpenGLTexture;
class QOpenGLShader;
class QOpenGLShaderProgram;

class QOpenGLPaintDevice;

class OpenGLWindow :public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

signals:
    void dataUpdate();
public:
    OpenGLWindow(const QColor& background, QWidget* parent);
    OpenGLWindow();
    ~OpenGLWindow();

    void addTrianglePoints(QVector<GLfloat> p, QVector<GLfloat> c);
    
protected:
    void paintGL() override;
    void initializeGL() override;
    void setAnimating(bool animating);
    void addPoints(QVector<GLfloat>& add);

private:
    void createGeometry();
    void quad(qreal x1, qreal y1, qreal x2, qreal y2, qreal x3, qreal y3, qreal x4, qreal y4);
    void extrude(qreal x1, qreal y1, qreal x2, qreal y2);
    void reset();

private:
    bool mAnimating = true;
    QOpenGLContext* mContext = nullptr;
    QOpenGLPaintDevice* mDevice = nullptr;

    QOpenGLShader* mVshader = nullptr;
    QOpenGLShader* mFshader = nullptr;
    QOpenGLShaderProgram* mProgram = nullptr;

    QList<QVector3D> mVertices;
    QList<QVector3D> mNormals;
    QOpenGLBuffer mVbo;
    int mVertexAttr;
    int mNormalAttr;
    int mMatrixUniform;
    QColor mBackground;
    QMetaObject::Connection mContextWatchConnection;

    GLint m_posAttr = 0;
    GLint m_colAttr = 0;
    GLint m_matrixUniform = 0;

    QVector <GLfloat> myColorVector;
    QVector <GLfloat> inputPoints;
};
