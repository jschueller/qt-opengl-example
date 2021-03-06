/*
    2010-2014
    Guillaume Belz
    http://guillaumebelz.wordpress.com/
    http://guillaume.belz.free.fr/

    This is free and unencumbered software released into the public domain.

    Anyone is free to copy, modify, publish, use, compile, sell, or
    distribute this software, either in source code form or as a compiled
    binary, for any purpose, commercial or non-commercial, and by any
    means.

    In jurisdictions that recognize copyright laws, the author or authors
    of this software dedicate any and all copyright interest in the
    software to the public domain. We make this dedication for the benefit
    of the public at large and to the detriment of our heirs and
    successors. We intend this dedication to be an overt act of
    relinquishment in perpetuity of all present and future rights to this
    software under copyright law.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
    IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
    OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
    ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
    OTHER DEALINGS IN THE SOFTWARE.

    For more information, please refer to <http://unlicense.org>
*/

#include <QGuiApplication>
#include "heightmapwidget.h"
#include <QTimer>
#include <iostream>
#include <QOpenGLFunctions_3_2_Core>
#include <QOpenGLFunctions>

static bool SupportsOpenGL_3_2()
{
  QSurfaceFormat requestedFormat;

  requestedFormat.setRenderableType(QSurfaceFormat::OpenGL);
  requestedFormat.setProfile(QSurfaceFormat::CoreProfile);

  requestedFormat.setVersion(3, 2);
  QOpenGLContext context;
  context.setFormat(requestedFormat);
  if (!context.create())
  {
    std::cout << "no context"<<std::endl;
    return false;
  }
  std::cout << "context valid="<<context.isValid()<<std::endl;
  std::cout << "context version="<<context.format().majorVersion()<<"."<<context.format().minorVersion() << std::endl;

  return context.versionFunctions<QOpenGLFunctions_3_2_Core>();
}

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);
    bool ok = SupportsOpenGL_3_2();
    std::cout << "ok=" << ok<<std::endl;

    HeightmapWidget hmw;
    hmw.show();

    QTimer *timer = new QTimer;
    QObject::connect(timer, SIGNAL(timeout()), &hmw, SLOT(close()));
    timer->start(10000);
    
    return a.exec();
}
