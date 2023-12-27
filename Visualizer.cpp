#include "stdafx.h"
#include "Visualizer.h"
#include "OpenGLWindow.h"
#include "Geometry.h"

Visualizer::Visualizer(QWindow* parent) : QMainWindow(nullptr)
{
    setupUi();
    connect(mOpenGLWidget, SIGNAL(shapesUpdated()), mOpenGLWidget, SLOT(update()));
    connect(mPushButton1, &QPushButton::clicked, this, &Visualizer::addPoints);
    connect(mPushButton2, &QPushButton::clicked, this, &Visualizer::addBezier);
    connect(mPushButton3, &QPushButton::clicked, this, &Visualizer::addHermite);
    connect(mPushButton4, &QPushButton::clicked, this, &Visualizer::reader);
    connect(mPushButton5, &QPushButton::clicked, this, &Visualizer::writer);
    connect(mPushButton6, &QPushButton::clicked, this, &Visualizer::addBSpline);
    connect(mPushButton7, &QPushButton::clicked, this, &Visualizer::mirror_X);
    connect(mPushButton8, &QPushButton::clicked, this, &Visualizer::mirror_Y);
    connect(mPushButton9, &QPushButton::clicked, this, &Visualizer::colorChange);
}

Visualizer::~Visualizer()
{}

void Visualizer::setupUi()
{
    resize(867, 702);
    mCentralWidget = new QWidget(this);
    mGridLayoutWidget = new QWidget(mCentralWidget);
    mGridLayoutWidget->setGeometry(QRect(0, 0, 861, 621));
    mGridLayout = new QGridLayout(mGridLayoutWidget);
    mGridLayout->setSpacing(6);
    mGridLayout->setContentsMargins(11, 11, 11, 11);
    mGridLayout->setContentsMargins(0, 0, 0, 0);

    // First, show mHorizontalLayout9
    QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    sizePolicy2.setHorizontalStretch(0);
    sizePolicy2.setVerticalStretch(0);

    mOpenGLWidget = new OpenGLWindow(QColor(0,0,0), mCentralWidget);
    sizePolicy2.setHeightForWidth(mOpenGLWidget->sizePolicy().hasHeightForWidth());
    mOpenGLWidget->setSizePolicy(sizePolicy2);

    mGridLayout->addWidget(mOpenGLWidget, 1, 0, 1, 1);

    // Third, show mHorizontalLayout5
    mHorizontalLayout5 = new QHBoxLayout();
    mHorizontalLayout5->setSpacing(6);

    // Rest of your existing code for mHorizontalLayout10 continues here

    mVerticalLayout1 = new QVBoxLayout();
    mVerticalLayout1->setSpacing(6);
    mHorizontalLayout1 = new QHBoxLayout();
    mHorizontalLayout1->setSpacing(6);

    QLabel* label_4 = new QLabel("Point3D Input ->", mGridLayoutWidget);
    mHorizontalLayout1->addWidget(label_4);

    QLabel* label_7 = new QLabel("X", mGridLayoutWidget);
    QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
    label_7->setSizePolicy(sizePolicy);
    label_7->setAlignment(Qt::AlignRight | Qt::AlignTrailing | Qt::AlignVCenter);

    mHorizontalLayout1->addWidget(label_7);

    mDoubleSpinBox1 = new QDoubleSpinBox(mGridLayoutWidget);
    mDoubleSpinBox1->setMinimum(-100.000000000000000);
    mDoubleSpinBox1->setMaximum(100.000000000000000);
    mHorizontalLayout1->addWidget(mDoubleSpinBox1);

    QLabel* label_8 = new QLabel("Y", mGridLayoutWidget);
    sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
    label_8->setSizePolicy(sizePolicy);
    label_8->setAlignment(Qt::AlignRight | Qt::AlignTrailing | Qt::AlignVCenter);

    mHorizontalLayout1->addWidget(label_8);

    mDoubleSpinBox2 = new QDoubleSpinBox(mGridLayoutWidget);
    mDoubleSpinBox2->setMinimum(-100.000000000000000);
    mDoubleSpinBox2->setMaximum(100.000000000000000);
    mHorizontalLayout1->addWidget(mDoubleSpinBox2);

    mPushButton1 = new QPushButton("ADD", mGridLayoutWidget);

    mHorizontalLayout1->addWidget(mPushButton1);

    mVerticalLayout1->addLayout(mHorizontalLayout1);

    mListWidget1 = new QListWidget(mGridLayoutWidget);
    QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Minimum);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(mListWidget1->sizePolicy().hasHeightForWidth());
    mListWidget1->setSizePolicy(sizePolicy1);

    mVerticalLayout1->addWidget(mListWidget1);

    mHorizontalLayout5->addLayout(mVerticalLayout1);

    mGridLayout->addLayout(mHorizontalLayout5, 2, 0, 1, 1);

    mTabWidget = new QTabWidget(mGridLayoutWidget);
    mHorizontalLayout5->addLayout(mVerticalLayout1);
    mGridLayout->addWidget(mTabWidget, 10, 0, 1, 1);

    mTab1 = new QWidget();
    mTabWidget->addTab(mTab1, "Bezier");

    mTab2 = new QWidget();
    mTabWidget->addTab(mTab2, "Hermite");

    mTab3 = new QWidget();
    mTabWidget->addTab(mTab3, "Z-Buffer");
    
    mTab4 = new QWidget();
    mTabWidget->addTab(mTab4, "B-Spline");

    mTab5 = new QWidget();
    mTabWidget->addTab(mTab5, "Mirror");

    mTab6 = new QWidget();
    mTabWidget->addTab(mTab6, "Color");

    mHorizontalLayout2 = new QHBoxLayout(mTab1);
    mPushButton2 = new QPushButton("Bezier Curve", mGridLayoutWidget);
    mHorizontalLayout2->addWidget(mPushButton2);
    mGridLayout->addLayout(mHorizontalLayout2, 3, 0, 1, 1);

    mHorizontalLayout3 = new QHBoxLayout(mTab2);
    mPushButton3 = new QPushButton("Hermite Curve", mGridLayoutWidget);
    mHorizontalLayout3->addWidget(mPushButton3);
    mGridLayout->addLayout(mHorizontalLayout3, 4, 0, 1, 1);

    mHorizontalLayout4 = new QHBoxLayout(mTab3);
    mPushButton4 = new QPushButton("Read STL File", mGridLayoutWidget);
    mHorizontalLayout4->addWidget(mPushButton4);
    mPushButton5 = new QPushButton("Show STL File", mGridLayoutWidget);
    mHorizontalLayout4->addWidget(mPushButton5);
    mGridLayout->addLayout(mHorizontalLayout4, 5, 0, 1, 1);

    mHorizontalLayout6 = new QHBoxLayout(mTab4);
    mPushButton6 = new QPushButton("BSplineCurve Curve", mGridLayoutWidget);
    mHorizontalLayout6->addWidget(mPushButton6);
    mGridLayout->addLayout(mHorizontalLayout6, 6, 0, 1, 1);

    mHorizontalLayout7 = new QHBoxLayout(mTab5);
    mPushButton8 = new QPushButton("Mirror about X-axis", mGridLayoutWidget);
    mHorizontalLayout7->addWidget(mPushButton8);
    mPushButton7 = new QPushButton("Mirror about Y-axis", mGridLayoutWidget);
    mHorizontalLayout7->addWidget(mPushButton7);
    mGridLayout->addLayout(mHorizontalLayout7, 7, 0, 1, 1);

    mHorizontalLayout8 = new QHBoxLayout(mTab6);
    mPushButton9 = new QPushButton("Color", mGridLayoutWidget);
    mHorizontalLayout8->addWidget(mPushButton9);
    mGridLayout->addLayout(mHorizontalLayout8, 8, 0, 1, 1);

    QLabel* label = new QLabel("Algorithms", mGridLayoutWidget);
    label->setAlignment(Qt::AlignLeading | Qt::AlignHCenter | Qt::AlignVCenter);
    mGridLayout->addWidget(label, 0, 0, 1, 1);

    setCentralWidget(mCentralWidget);
}

void Visualizer::mirror_X() {
    mOpenGLWidget->toggleMirrorEffect_X();
}
void Visualizer::mirror_Y() {
    mOpenGLWidget->toggleMirrorEffect_Y();
}

void Visualizer::colorChange() {
    mOpenGLWidget->colorChanger();
}

void Visualizer::addPoints()
{
    double xValue = mDoubleSpinBox1->value();
    double yValue = mDoubleSpinBox2->value();

    // Create a string representation of the values
    QString itemText = QString("X: %1, Y: %2").arg(xValue).arg(yValue);
    Point3D p(xValue, yValue);
    mPoints.push_back(p);

    // Add the item to the QListWidget
    QListWidgetItem* newItem = new QListWidgetItem(itemText);
    mListWidget1->addItem(newItem);
}

void Visualizer::addHermite()
{
    if (mPoints.size() != 4) {
        // At least three points are needed to create a polygon
        QMessageBox::warning(this, "Error", "Four points are needed to create a Hermite.");
        return;
    }
    mOpenGLWidget->addHermiteCurve(mPoints);

    mListWidget1->clear();
    mPoints.clear();
}

void Visualizer::addBezier()
{
    if (mPoints.size() != 4) {
        // At least three points are needed to create a polygon
        QMessageBox::warning(this, "Error", "Four points are needed to create a Bezier.");
        return;
    }
    mOpenGLWidget->addBezierCurve(mPoints);

    mListWidget1->clear();
    mPoints.clear();
}

void Visualizer::reader() {
    Z_Buffer reader;
    reader.reader(triangles, myColorVector);
}

void Visualizer::writer() {
    Z_Buffer writer;
    writer.write(triangles, inputPoints);
    mOpenGLWidget->addTrianglePoints(inputPoints, myColorVector);
}


void Visualizer::addBSpline()
{
    // Add a Bezier curve to the OpenGL window
    if (mPoints.size() != 4) {
        QMessageBox::warning(this, "Error", "Four points are needed to create a BSpline curve.");
        return;
    }

    // Add Bezier curve to the OpenGL window
    mOpenGLWidget->addBSplineCurve(mPoints);
}
