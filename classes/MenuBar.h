#ifndef MENUBAR_H
#define MENUBAR_H
#endif

#include "qt.h"

// Defaults for a menu bar and its children
class MenuBar: public QMenuBar {
    Q_OBJECT

    public:
        MenuBar(QWidget *parent = 0) : QMenuBar(parent) {
            setStyleSheet(" \
                QMenuBar { background: #f7f7f7; border-bottom: 1px solid #e5e5e5; } \
                QMenuBar::item:selected { background-color: #dadada; margin-bottom: 1px; } \
            ");
        }
        QMenu *addMenu(const char * title) {
            QMenu *menu = QMenuBar::addMenu(title);
            menu -> setStyleSheet(" \
                QMenu { background: white; border: 1px solid #ddd; border-radius: 6px; padding: 6px; } \
                QMenu::item { padding: 4px 18px; } \
                QMenu::item:selected { background: #f7f7f7; border-radius: 6px; } \
                QMenu::separator { height: 1px; background: #ddd; margin: 8px 0; } \
            ");

            menu -> setAttribute(Qt::WA_TranslucentBackground);
            return menu;
        } 
};
