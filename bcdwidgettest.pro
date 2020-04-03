TEMPLATE = app
LANGUAGE = C++
TARGET   = bcdwidgettest
QT += widgets

SOURCES += bcdwidget.cpp main.cpp
HEADERS += bcdwidget.hpp
CONFIG  += qt warn_on release
DBFILE  = bcdwidget.db
DEFINES += BCDWIDGET_IS_WIDGET
