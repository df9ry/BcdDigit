#include "bcdwidget.hpp"

#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include <QDebug>

static const QString rgStr[16] {
    "0", "1", "2", "3", "4", "5", "6", "7",
    "8", "9", "A", "B", "C", "D", "E", "F"
};

BcdWidget::BcdWidget(QWidget *parent, Mode _md) :
    QWidget(parent), m_mode{_md}
{
    this->setMinimumSize(12, 32);
    this->setGeometry(0, 0, 24, 64);

    QVBoxLayout *layout = new QVBoxLayout(parent);
    layout->setMargin(0);
    layout->setSpacing(0);

    upButton = new QPushButton("^", parent);
    connect(upButton, &QPushButton::clicked, [this]() {
        m_value += 1;
        switch (m_mode) {
        case DEC:
            m_value %= 10;
            break;
        case HEX:
            m_value %= 16;
            break;
        } // end switch //
        field->setText(rgStr[m_value]);
        emit valueChanged(m_value);
    });

    field = new QLineEdit("0", parent);
    field->setMaxLength(1);
    field->setInputMask("9");
    field->setAlignment(Qt::AlignHCenter);
    connect(field, &QLineEdit::textEdited, [this](const QString &_text) {
        QString text{_text.toLower()};
        QString pattern{(m_mode == DEC) ? "0123456789" : "0123456789abcdef"};
        int index{pattern.indexOf(text)};
        if (index >= 0) {
            m_value = index;
            if (index != m_value) {
                m_value = index;
                emit valueChanged(m_value);
            }
        } else {
            field->undo();
        }
        field->setText(rgStr[m_value]);
    });

    downButton = new QPushButton("v", parent);
    connect(downButton, &QPushButton::clicked, [this]() {
        m_value -= 1;
        if (m_value < 0) {
            switch (m_mode) {
            case DEC:
                m_value = 9;
                break;
            case HEX:
                m_value = 15;
                break;
            } // end switch //
        }
        field->setText(rgStr[m_value]);
        emit valueChanged(m_value);
    });

    layout->addWidget(upButton);
    layout->addWidget(field);
    layout->addWidget(downButton);
    setFocusProxy(field);
    setLayout(layout);
}

BcdWidget::Mode BcdWidget::mode() const
{
    return m_mode;
}

void BcdWidget::setMode(Mode mode)
{
    switch (mode) {
    case DEC:
        m_mode = DEC;
        if (m_value >= 10) {
            m_value = 0;
            field->setText("0");
        }
        field->setInputMask("9");
        break;
    case HEX:
        m_mode = HEX;
        field->setInputMask("H");
        break;
    } // end switch //
}

int BcdWidget::value() const
{
    return m_value;
}

void BcdWidget::setValue(int value)
{
    if (value < 0) {
        m_value = 0;
    } else {
    switch (m_mode) {
        case DEC:
            m_value = value % 10;
            break;
        case HEX:
            m_value = value % 16;
            break;
        } // end switch //
    }
    field->setText(rgStr[m_value]);
}
