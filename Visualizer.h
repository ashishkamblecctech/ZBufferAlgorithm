#pragma once

#include <QtWidgets/QMainWindow>
#include "Visualizer.h"
#include "Triangle.h"
#include "OpenGLWindow.h"

class OpenGLWindow;

class Visualizer : public QMainWindow
{
    Q_OBJECT


public:
    Visualizer(QWindow* parent = nullptr);
    ~Visualizer();

    public slots:
        void reader();
        void writer();


private:
    void setupUi();

private:
  /*  QMenuBar*   mMenuBar;
    QToolBar*   mMainToolBar;
    QWidget*    mCentralWidget;
    QStatusBar* mStatusBar;
    OpenGLWindow*   mRenderer;*/
    QWidget* centralWidget;
    OpenGLWindow* openGLWidget;
    QWidget* widget;
    QHBoxLayout* horizontalLayout;
    QPushButton* pushButton;
    QPushButton* pushButton_2;
    QMenuBar* menuBar;
    QToolBar* mainToolBar;
    QStatusBar* statusBar;

    QVector <Triangle> triangles;
    QVector <GLfloat> myColorVector;
    QVector <GLfloat> inputPoints;

};