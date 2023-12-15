#include "stdafx.h"
#include "Visualizer.h"
#include <QtWidgets/QApplication>
#include "Reader.h"
#include "OpenGLWindow.h"
#include <QApplication>
#include <QLabel>
#include <QSurfaceFormat>

#ifndef QT_NO_OPENGL
#include "mainwidget.h"
#endif

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QCoreApplication::setApplicationName("Qt QOpenGLWidget Stereoscopic Rendering Example");
    QCoreApplication::setOrganizationName("QtProject");
    QCoreApplication::setApplicationVersion(QT_VERSION_STR);

    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    format.setStencilBufferSize(8);

    // Enable stereoscopic rendering support
    format.setStereo(true);

    QSurfaceFormat::setDefaultFormat(format);

    Visualizer mw;
    mw.show();


    //QSurfaceFormat format;
    //format.setDepthBufferSize(24);
    //QSurfaceFormat::setDefaultFormat(format);

    /*a.setApplicationName("cube");
    a.setApplicationVersion("0.1");
#ifndef QT_NO_OPENGL
    MainWidget widget;
    widget.show();
#else
    QLabel note("OpenGL Support required");
    note.show();
#endif*/
    return a.exec();

  
}
