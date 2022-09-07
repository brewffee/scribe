#ifndef LINEEDIT_H
#define LINEEDIT_H
#endif

#include "qt.h"

// Defaults for a text entry (one ljne)
class LineEdit: public QLineEdit {
    Q_OBJECT 

    public: 
        LineEdit(QWidget *parent = 0): QLineEdit(parent) {
            setStyleSheet(" \
                QLineEdit { background: #fff; border: 1px solid #ddd; border-radius: 6px; padding: 4px 6px } \
                QLineEdit:focus { border: 2px solid #3584e4; } \
            ");
        }
};