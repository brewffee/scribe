#include "menus_.h"

void createActions(QMenu *menu, QMainWindow *mainWindow, QString name, QString shortcut, QString statusTip, void (*function)(QMainWindow *, QMenu *, QAction *)) {    
    // compensating for the lack of spacing between items and sequences
    QAction *newAction = menu -> addAction(name.append("        "));
    if (shortcut != "none") newAction -> setShortcut(QKeySequence(shortcut));

    QObject::connect(newAction, &QAction::hovered, [mainWindow, statusTip, newAction]() {
        // StatusTips and other strings will be moved to a separate file eventually,
        // where they can be easily translated (if ever gotten around to)

        newAction -> setStatusTip(statusTip);
        mainWindow -> statusBar() -> showMessage(statusTip);
    });

    QObject::connect(newAction, &QAction::triggered, [mainWindow, menu, newAction, function]() {
        function(mainWindow, menu, newAction); 
    });

    return;
}

void populateMenus(MenuBar *menuBar, QMainWindow *mainWindow, TextEdit *editor) {
    QMenu *fileMenu = menuBar -> addMenu("File");
    QMenu *editMenu = menuBar -> addMenu("Edit");
    QMenu *formatMenu = menuBar -> addMenu("Format");
    QMenu *viewMenu = menuBar -> addMenu("View");
    QMenu *helpMenu = menuBar -> addMenu("Help");

    // we'll likely need to move these to a separate file 
    createActions(fileMenu, mainWindow, "New", "Ctrl+N", " Create a new file", newFile);
    createActions(fileMenu, mainWindow, "New Window", "Ctrl+Shift+N", " Create a new window", newWindow);
    createActions(fileMenu, mainWindow, "Open...", "Ctrl+O", " Open a file", openFile);
    createActions(fileMenu, mainWindow, "Save", "Ctrl+S", " Save the current file", saveFile);
    createActions(fileMenu, mainWindow, "Save As", "Ctrl+Shift+S", " Save as a new file", saveAs);
    fileMenu -> addSeparator();
    createActions(fileMenu, mainWindow, "Quit", "none", " Quit the application", quit);

    createActions(editMenu, mainWindow, "Undo", "Ctrl+Z", " Undo the last action", undo);
    createActions(editMenu, mainWindow, "Redo", "Ctrl+Y", " Redo the last action", redo);
    editMenu -> addSeparator();
    createActions(editMenu, mainWindow, "Cut", "Ctrl+X", " Cut the selected text", cut);
    createActions(editMenu, mainWindow, "Copy", "Ctrl+C", " Copy the selected text", copy);
    createActions(editMenu, mainWindow, "Paste", "Ctrl+V", " Paste the clipboard", paste);
    editMenu -> addSeparator();
    createActions(editMenu, mainWindow, "Find...", "Ctrl+F", " Find text", find);
    createActions(editMenu, mainWindow, "Replace...", "Ctrl+H", " Replace text", findAndReplace);
    editMenu -> addSeparator();
    createActions(editMenu, mainWindow, "Select All", "Ctrl+A", " Select all text", selectAll);
    createActions(editMenu, mainWindow, "Time/Date", "F5", " Insert the current time and date", timeDate);

    createActions(formatMenu, mainWindow, "Word Wrap", "none", " Toggle word wrap", toggleWordWrap);
    createActions(formatMenu, mainWindow, "Font...", "none", " Change the font", manageFont);

    createActions(viewMenu, mainWindow, "Status Bar", "F3", " Show the status bar", toggleStatusBar);

    createActions(helpMenu, mainWindow, "About", "none", " About the application", about);
    createActions(helpMenu, mainWindow, "About Qt", "none", " About Qt", aboutQt);

    return;
}
