void toggleStatusBar(QMainWindow *window, QMenu *QMenu, QAction *action) {
    window -> statusBar() -> setVisible(!window -> statusBar() -> isVisible());
}
