#include <QApplication>

#include "bcdwidget.hpp"

int main( int argc, char ** argv )
{
    QApplication a( argc, argv );
    BcdWidget *widget = new BcdWidget();
    widget->show();
    return a.exec();
}
