void undo(QMainWindow *window, QMenu *QMenu, QAction *action) {
    static_cast<QTextEdit*>(window -> centralWidget()) -> undo();
}

void redo(QMainWindow *window, QMenu *QMenu, QAction *action) {
    static_cast<QTextEdit*>(window -> centralWidget()) -> redo();
}

void cut(QMainWindow *window, QMenu *QMenu, QAction *action) {
    static_cast<QTextEdit*>(window -> centralWidget()) -> cut();
}

void copy(QMainWindow *window, QMenu *QMenu, QAction *action) {
    static_cast<QTextEdit*>(window -> centralWidget()) -> copy();
}

void paste(QMainWindow *window, QMenu *QMenu, QAction *action) {
    static_cast<QTextEdit*>(window -> centralWidget()) -> paste();
}

void selectAll(QMainWindow *window, QMenu *QMenu, QAction *action) {
    static_cast<QTextEdit*>(window -> centralWidget()) -> selectAll();
}

void timeDate(QMainWindow *window, QMenu *QMenu, QAction *action) {
    QString dateTime = QDateTime::currentDateTime().toString("MM/dd/yy hh:mm:ss");
    QString dateTimeString = dateTime;
    static_cast<QTextEdit*>(window -> centralWidget()) -> insertPlainText(dateTimeString);
}
