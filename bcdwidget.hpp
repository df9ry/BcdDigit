#ifndef BCDWIDGET_HPP
#define BCDWIDGET_HPP

#include <QWidget>

class QLineEdit;
class QPushButton;

class BcdWidget : public QWidget
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
