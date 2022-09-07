#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H    
#endif

#include "qt.h"

enum ButtonType {

    // Button priority
    Primary = 100,
    Secondary = 0,

    // Types of grouped buttons
    Start = 1,
    Middle = 2,
    End = 3,

    // Special types wherein different stylesheets may be required
    Icon = 4,
    Hybrid = 5,
    QtDefault = 6,

    // Special cases
    PrimaryIcon = 104,
    SecondaryIcon = 4,
    PrimaryHybrid = 105,
    SecondaryHybrid = 5,

};

// Defaults for buttons, as well as additional button types
class PushButton: public QPushButton { 
    Q_OBJECT

    public: 
        PushButton(const QString &text, QWidget *parent = nullptr): QPushButton(parent) {
            setStyleSheet(" \
                QPushButton { background: #fff; border: 1px solid #ddd; border-radius: 6px; font-weight: bold; } \
                QPushButton:hover { background: #f7f7f7; } \
                QPushButton:pressed { background: #d5d5d5; } \
                QPushButton:focus { outline: 2px solid #3584e4; } \
            ");
            setText(text);
            setFixedSize(sizeHint() + QSize(48, 16));
        }

        void setType(ButtonType type) {
            switch (type) {
                case ButtonType::Primary:
                    setStyleSheet(" \
                        QPushButton { background: #3584e4; color: #fff; border-radius: 6px; font-weight: bold; } \
                        QPushButton:hover { background: #3584e4; } \
                        QPushButton:pressed { background: #3584e4; } \
                        QPushButton:focus { outline: 2px solid #8cbcf8; } \
                    ");
                    break;
                case ButtonType::Secondary:
                    // Revert to default style
                    setStyleSheet(" \
                        QPushButton { background: #fff; border: 1px solid #ddd; border-radius: 6px; font-weight: bold; } \
                        QPushButton:hover { background: #f7f7f7; } \
                        QPushButton:pressed { background: #d5d5d5; } \
                        QPushButton:focus { outline: 2px solid #3584e4; } \
                    ");
                    break;
                case ButtonType::Start: // Left button
                    setStyleSheet(" \
                        QPushButton { background: #fff; border: 1px solid #ddd; border-radius: 6px 0px 0px 6px; font-weight: bold; } \
                        QPushButton:hover { background: #f7f7f7; } \
                        QPushButton:pressed { background: #d5d5d5; } \
                        QPushButton:focus { outline: 2px solid #3584e4; } \
                        QPushButton:first-child { margin-left: 0; } \
                    ");
                    break;
                case ButtonType::Middle: // Optional middle button
                    setStyleSheet(" \
                        QPushButton { background: #fff; border: 1px solid #ddd; border-radius: 0px; font-weight: bold; } \
                        QPushButton:hover { background: #f7f7f7; } \
                        QPushButton:pressed { background: #d5d5d5; } \
                        QPushButton:focus { outline: 2px solid #3584e4; } \
                        QPushButton:first-child { margin-left: 0; } \
                    ");
                    break;
                case ButtonType::End: // Right button
                    setStyleSheet(" \
                        QPushButton { background: #fff; border: 1px solid #ddd; border-radius: 0px 6px 6px 0px; font-weight: bold; } \
                        QPushButton:hover { background: #f7f7f7; } \
                        QPushButton:pressed { background: #d5d5d5; } \
                        QPushButton:focus { outline: 2px solid #3584e4; } \
                        QPushButton:last-child { margin-right: 0; } \
                    ");
                    break;
                case ButtonType::PrimaryIcon:
                case ButtonType::SecondaryIcon:
                case ButtonType::PrimaryHybrid:
                case ButtonType::SecondaryHybrid:
                    printf("Warning: Button type %d not supported\n", type);
                    break;
                case ButtonType::QtDefault:
                    // Remove any additional styles
                    setStyleSheet("");
                    setFixedSize(sizeHint());
                    break;
            }
        }
};