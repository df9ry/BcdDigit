QT          += widgets designer
CONFIG      += ui_plugin
TEMPLATE    = lib
TARGET      = $$qtLibraryTarget($$TARGET)
target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS    += target

HEADERS     = bcdwidgetplugin.hpp
SOURCES     = bcdwidgetplugin.cpp
RESOURCES   = icons.qrc
OTHER_FILES += bcdwidget.json

include(bcdwidget.pri)

DISTFILES += \
    bcdwidget.json
