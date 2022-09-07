#ifndef STATUSBAR_H
#define STATUSBAR_H
#endif

#include "qt.h"

// Defaults for a status bar element
class StatusBar: public QStatusBar {
    Q_OBJECT

    public:
        StatusBar(QWidget *parent = 0) : QStatusBar(parent) {
            setStyleSheet(" \
                QStatusBar { background: #f7f7f7; border-top: 1px solid #e5e5e5; color: gray;} \
                QLabel { color: gray; } \
            ");
            setFixedHeight(32);
            setSizeGripEnabled(false);
        }
};
