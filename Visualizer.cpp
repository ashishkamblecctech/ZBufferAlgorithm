#include "stdafx.h"
#include "Visualizer.h"
#include "OpenGLWindow.h"
#include "Reader.h"
#include "Writer.h"

Visualizer::Visualizer(QWindow *parent)  : QMainWindow(nullptr)
{
    setupUi();
    connect(openGLWidget, SIGNAL(dataUpdate()), openGLWidget, SLOT(update()));
}

Visualizer::~Visualizer()
{}

void Visualizer::setupUi() {
   /* resize(600, 400);
    mMenuBar = new QMenuBar(this);
    mMenuBar->setObjectName("menuBar");
    setMenuBar(mMenuBar);
    mMainToolBar = new QToolBar(this);
    mMainToolBar->setObjectName("mainToolBar");
    addToolBar(mMainToolBar);
    mStatusBar = new QStatusBar(this);
    mStatusBar->setObjectName("statusBar");
    setStatusBar(mStatusBar);
    mRenderer = new OpenGLWindow(QColor(0,0,0), this);
    setCentralWidget(mRenderer);
    


    setWindowTitle(QCoreApplication::translate("Z-Buffer", "Z-Buffer", nullptr));*/
    resize(600, 400);
    centralWidget = new QWidget(this);
    centralWidget->setObjectName("centralWidget");
    openGLWidget = new OpenGLWindow(QColor(0,0,0),centralWidget);
    openGLWidget->setObjectName("openGLWidget");
    openGLWidget->setGeometry(QRect(19, 49, 571, 311));
    widget = new QWidget(centralWidget);
    widget->setObjectName("widget");
    widget->setGeometry(QRect(190, 10, 158, 26));
    horizontalLayout = new QHBoxLayout(widget);
    horizontalLayout->setSpacing(6);
    horizontalLayout->setContentsMargins(11, 11, 11, 11);
    horizontalLayout->setObjectName("horizontalLayout");
    horizontalLayout->setContentsMargins(0, 0, 0, 0);
    pushButton = new QPushButton("ReadFile",widget);
    pushButton->setObjectName("pushButton");

    horizontalLayout->addWidget(pushButton);

    pushButton_2 = new QPushButton("WriteFile",widget);
    pushButton_2->setObjectName("pushButton_2");

    horizontalLayout->addWidget(pushButton_2);

    setCentralWidget(centralWidget);
    menuBar = new QMenuBar(this);
    menuBar->setObjectName("menuBar");
    menuBar->setGeometry(QRect(0, 0, 600, 22));
    setMenuBar(menuBar);
    mainToolBar = new QToolBar(this);
    mainToolBar->setObjectName("mainToolBar");
    addToolBar(Qt::TopToolBarArea, mainToolBar);
    statusBar = new QStatusBar(this);
    statusBar->setObjectName("statusBar");
    setStatusBar(statusBar);

    connect(pushButton, &QPushButton::clicked, this, &Visualizer::reader);
    connect(pushButton_2, &QPushButton::clicked, this, &Visualizer::writer);

    QMetaObject::connectSlotsByName(this);

    
}

void Visualizer::reader() {
    Reader reader;
    reader.reader(triangles, myColorVector);
}

void Visualizer::writer() {
    Writer writer;
    writer.write(triangles, inputPoints);
    openGLWidget->addTrianglePoints(inputPoints,myColorVector);
}