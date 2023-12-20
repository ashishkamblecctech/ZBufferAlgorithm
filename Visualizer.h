#pragma once

#include <QtWidgets/QMainWindow>
#include "Visualizer.h"
#include "Point3D.h"
#include <vector>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include "Triangle.h"
#include "Z_Buffer.h"


class OpenGLWindow;

class Visualizer : public QMainWindow, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    Visualizer(QWindow* parent = nullptr);
    ~Visualizer();
    void reader();
    void writer();

private:
    void setupUi();
    void clearListAndPoints();

private slots:
    void addPoints();
    void addHermite();
    void addBezier();
    void addBSpline();

private:
    QWidget* mCentralWidget;
    QWidget* mGridLayoutWidget;
    QGridLayout* mGridLayout;

    QHBoxLayout* mHorizontalLayout1;
    QHBoxLayout* mHorizontalLayout2;
    QHBoxLayout* mHorizontalLayout3;
    QHBoxLayout* mHorizontalLayout4;
    QHBoxLayout* mHorizontalLayout5;
    QHBoxLayout* mHorizontalLayout6;

    QPushButton* mPushButton1;
    QPushButton* mPushButton2;
    QPushButton* mPushButton3;
    QPushButton* mPushButton4;
    QPushButton* mPushButton5;
    QPushButton* mPushButton6;

    
    QVBoxLayout* mVerticalLayout1;
    
    QDoubleSpinBox* mDoubleSpinBox1;
    QDoubleSpinBox* mDoubleSpinBox2;
    
    QListWidget* mListWidget1;
    OpenGLWindow* mOpenGLWidget;
    QTabWidget* mTabWidget;
    QListWidget* mListWidget3;

    QWidget* mTab1;
    QWidget* mTab2;
    QWidget* mTab3;
    QWidget* mTab4;

    std::vector<Point3D> mPoints;
    std::vector <Triangle> triangles;
    std::vector <float> myColorVector;
    std::vector <float> inputPoints;
};
