#ifndef SAVE_CPP
#define SAVE_CPP
#endif // required by 2 files

void saveAs(QMainWindow *window, QMenu *QMenu, QAction *action) {
    printf ("saveAs\n");
    //  open file picker
}

void saveFile(QMainWindow *window, QMenu *QMenu, QAction *action) {
    printf ("saveFile\n");
    // check if its already been saved before
    // if (exists) { ... }
    // else { saveAs(); }
}
