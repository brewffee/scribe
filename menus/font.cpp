void toggleWordWrap(QMainWindow *window, QMenu *QMenu, QAction *action) {
    QTextEdit *textEdit = static_cast<QTextEdit*>(window -> centralWidget());
    textEdit -> setLineWrapMode(textEdit -> lineWrapMode() == QTextEdit::NoWrap ? QTextEdit::WidgetWidth : QTextEdit::NoWrap);
    // add a checkbox to the action
}

void manageFont(QMainWindow *window, QMenu *QMenu, QAction *action) {}
