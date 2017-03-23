#-------------------------------------------------
#
# Project created by QtCreator 2017-03-03T10:15:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MazeAlgorithmGame
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    commonuse.cpp \
    qlabelmap.cpp \
    statusmanager.cpp \
    mypushbutton.cpp \
    player.cpp \
    position.cpp \
    distinguishdirection.cpp \
    target.cpp

HEADERS  += mainwindow.h \
    commonuse.h \
    qlabelmap.h \
    statusmanager.h \
    mypushbutton.h \
    player.h \
    position.h \
    distinguishdirection.h \
    target.h

FORMS    += mainwindow.ui
INCLUDEPATH += $$quote(D:\opencv310_x64_vs2015\include)\
               $$quote(D:\opencv310_x64_vs2015\include\opencv2)

OPENCVLIB += $$quote(D:\opencv310_x64_vs2015\x64\vc14\lib)
CONFIG(debug, debug|release){
LIBS+= $$OPENCVLIB/opencv_core310d.lib\
       $$OPENCVLIB/opencv_highgui310d.lib\
       $$OPENCVLIB/opencv_imgcodecs310d.lib\
       $$OPENCVLIB/opencv_imgproc310d.lib\
       $$OPENCVLIB/opencv_videoio310d.lib\

}

CONFIG(release, debug|release){

LIBS+= $$OPENCVLIB/opencv_core310.lib\
       $$OPENCVLIB/opencv_highgui310.lib\
       $$OPENCVLIB/opencv_imgcodecs310.lib\
       $$OPENCVLIB/opencv_imgproc310.lib\
       $$OPENCVLIB/opencv_videoio310.lib\

}
