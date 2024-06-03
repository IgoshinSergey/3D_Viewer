QT       += core gui opengl widgets printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(QtGifImage/src/gifimage/qtgifimage.pri)

SOURCES += \
    main.cpp \
    opengl.cpp \
    view.cpp \
    ../manipulation/manipulation.cpp \
    ../object/object.cpp \
    ../parser/parser.cpp \
    ../transformation/transformation.cpp \

HEADERS += \
    opengl.h \
    view.h \
    ../controller/controller.h \
    ../manipulation/manipulation.hpp \
    ../object/object.hpp \
    ../parser/parser.hpp \
    ../transformation/transformation.hpp \

FORMS += \
    view.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../temp.obj
