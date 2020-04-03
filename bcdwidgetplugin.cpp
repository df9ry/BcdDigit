#include "bcdwidget.hpp"
#include "bcdwidgetplugin.hpp"

#include <QtPlugin>

BcdWidgetPlugin::BcdWidgetPlugin(QObject *parent)
    : QObject(parent)
{
}

void BcdWidgetPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;
    // Add extension registrations, etc. here
    m_initialized = true;
}

bool BcdWidgetPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *BcdWidgetPlugin::createWidget(QWidget *parent)
{
    return new BcdWidget(parent);
}

QString BcdWidgetPlugin::name() const
{
    return QLatin1String("BcdWidget");
}

QString BcdWidgetPlugin::group() const
{
    return QLatin1String("BCD Widget [Custom]");
}

QIcon BcdWidgetPlugin::icon() const
{
    return QIcon();
}

QString BcdWidgetPlugin::toolTip() const
{
    return QLatin1String("");
}

QString BcdWidgetPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool BcdWidgetPlugin::isContainer() const
{
    return false;
}

QString BcdWidgetPlugin::domXml() const
{
    return QLatin1String("<ui language=\"c++\">\n"
                         " <widget class=\"BcdWidget\" name=\"bcdWidget\">\n"
                         "  <property name=\"geometry\">\n"
                         "   <rect>\n"
                         "    <x>0</x>\n"
                         "    <y>0</y>\n"
                         "    <width>24</width>\n"
                         "    <height>64</height>\n"
                         "   </rect>\n"
                         "  </property>\n"
                         "  <property name=\"toolTip\">\n"
                         "   <string>A simple BCD digit widget.</string>\n"
                         "  </property>\n"
                         "  <property name=\"whatsThis\">\n"
                         "   <string>A simple BCD digit.</string>\n"
                         "  </property>\n"
                         " </widget>\n"
                         "</ui>\n");
}

QString BcdWidgetPlugin::includeFile() const
{
    return QLatin1String("bcdwidget.hpp");
}
