#include <iostream>

#include "populateMenus.h"

// editor can be moved out of the global scope
// after the main function is converted to a class
TextEdit *editor;

int main (int argc, char *argv[]) {
    QApplication app(argc, argv);

    app.setFont(QFont("Ubuntu"));

    QMainWindow *window = new QMainWindow();
    window -> setMinimumSize(320, 180);
    window -> resize(640, 480);
    window -> setWindowTitle("Untitled Document");
    
    MenuBar *menubar = new MenuBar;
    populateMenus(menubar, window, editor);
    window -> setMenuBar(menubar);

    StatusBar *statusbar = new StatusBar;

    QLabel *cursorPos = new QLabel();
    cursorPos -> setFixedWidth(125);

    QLabel *charCount = new QLabel();
    QLabel *insMode = new QLabel("INS  "); 

    statusbar -> addWidget(cursorPos);
    statusbar -> addWidget(charCount);
    statusbar -> addPermanentWidget(insMode);

    window -> setStatusBar(statusbar);

    editor = new TextEdit("editor");
    // #############################################################################
    // SYNTAX HIGHLIGHTING AND LINE NUMBERING HERE SOMETIME IN THE FUTURE !!!
    // #############################################################################
    editor -> getDetails(cursorPos, charCount, insMode);
    editor -> onCursorPositionChanged(cursorPos, charCount, insMode);
    editor -> onSelectionChanged(cursorPos, charCount, insMode);

    window -> setCentralWidget(editor);
    window -> show();

    return app.exec();
}

// handle keypresses
void QWidget::keyPressEvent(QKeyEvent *event) {
    if (event -> key() == Qt::Key_Insert) {
        if (editor -> overwriteMode()) {
            printf("insert mode set\n");
            editor -> setOverwriteMode(false);
            editor -> setCursorWidth(1);
        } else {
            printf("overwrite mode set\n");
            editor -> setOverwriteMode(true);

            QString currentChar = editor -> toPlainText().mid(editor -> textCursor().position(), 1);
            if (currentChar == "") {
                editor -> setCursorWidth(1);
            } else {
                int size = editor -> fontMetrics().horizontalAdvance(currentChar);
                editor -> setCursorWidth(size);                           
            }
        }
    }
}
