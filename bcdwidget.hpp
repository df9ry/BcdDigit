#ifndef BCDWIDGET_HPP
#define BCDWIDGET_HPP

#include <QWidget>
#if 0
#include <QtCore/QtGlobal>

#if defined BCDDIGIT_IMPLEMENTATION
#  define QDESIGNER_WIDGET_EXPORT Q_DECL_EXPORT
#else
#  define QDESIGNER_WIDGET_EXPORT Q_DECL_IMPORT
#endif
#else
#  define QDESIGNER_WIDGET_EXPORT
#endif

class QLineEdit;
class QPushButton;

class QDESIGNER_WIDGET_EXPORT BcdWidget : public QWidget
{
    Q_OBJECT

    Q_ENUMS( Mode )
    Q_PROPERTY( Mode mode READ mode WRITE setMode )
    Q_PROPERTY( int value READ value WRITE setValue )

public:
    enum Mode { DEC, HEX };

    BcdWidget(QWidget *parent = nullptr, enum Mode mode = DEC);

    Mode mode() const;
    int value() const;

public slots:
    void setMode(Mode mode);
    void setValue(int value);

signals:
    void valueChanged(int value);

private:
    Mode         m_mode;
    QLineEdit   *field{nullptr};
    QPushButton *upButton{nullptr};
    QPushButton *downButton{nullptr};
    int          m_value{0};
    bool         m_enabled{true};
};

#endif // BCDWIDGET_HPP
