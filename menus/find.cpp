void find(QMainWindow *window, QMenu *QMenu, QAction *action) {
    FakeModal *findWindow = new FakeModal();
    findWindow -> setWindowTitle("Find");
    findWindow -> setStyleSheet("background: #f7f7f7;");

    QLabel *findName = new QLabel("Find");
    findName -> setContentsMargins(0, 6, 2, 0);
    findName -> setFixedWidth(50);

    QLineEdit *findText = new QLineEdit();
    findText -> setFixedWidth(420);
    findText -> setStyleSheet(" \
        QLineEdit { background: #fff; border: 1px solid #ddd; border-radius: 6px; padding: 4px 6px } \
        QLineEdit:focus { border: 2px solid #3584e4; } \
    ");

    QCheckBox *matchCase = new QCheckBox("Match case");
    matchCase -> setStyleSheet(" \
        QCheckBox { spacing: 6px; width: 13px; height: 13px; } \
        QCheckBox:indicator { padding: 4px; border-radius: 4px; background: white; border: 1px solid #ddd; } \
        QCheckBox:indicator:unchecked { width: 13px; height: 13px; } \
        QCheckBox:indicator:checked { width: 13px; height: 13px; background: #3584e4; } \
    ");

    QCheckBox *wholeWord = new QCheckBox("Whole word");
    wholeWord -> setStyleSheet(" \
        QCheckBox { spacing: 6px; width: 13px; height: 13px; } \
        QCheckBox:indicator { padding: 4px; border-radius: 4px; background: white; border: 1px solid #ddd; } \
        QCheckBox:indicator:unchecked { width: 13px; height: 13px; } \
        QCheckBox:indicator:checked { width: 13px; height: 13px; background: #3584e4; } \
    ");

    QCheckBox *useRegex = new QCheckBox("Use regex");
    useRegex -> setStyleSheet(" \
        QCheckBox { spacing: 6px; width: 13px; height: 13px; } \
        QCheckBox:indicator { padding: 4px; border-radius: 4px; background: white; border: 1px solid #ddd; } \
        QCheckBox:indicator:unchecked { width: 13px; height: 13px; } \
        QCheckBox:indicator:checked { width: 13px; height: 13px; background: #3584e4; } \
    ");

    QPushButton *findButton = new QPushButton("Find");
    findButton -> setFixedHeight(36);
    findButton -> setFixedWidth(80);
    findButton -> setStyleSheet(" \
        QPushButton { background: #3584e4; color: #fff; border-radius: 6px; font-weight: bold; } \
        QPushButton:hover { background: #3584e4; } \
        QPushButton:pressed { background: #3584e4; } \
        QPushButton:focus { outline: 2px solid #8cbcf8; } \
    ");

    findButton -> connect(findButton, SIGNAL(clicked()), findWindow, SLOT(close()));

    QHBoxLayout *findLayout = new QHBoxLayout();

    QVBoxLayout *labelArea = new QVBoxLayout();
    labelArea -> addWidget(findName);
    labelArea -> addStretch();
    findName -> setAlignment(Qt::AlignRight | Qt::AlignTop);

    QVBoxLayout *dataArea = new QVBoxLayout();

    QHBoxLayout *layout = new QHBoxLayout();

    QGridLayout *checkButtons = new QGridLayout();
    checkButtons -> setContentsMargins(0, 4, 0, 8);
    checkButtons -> addWidget(matchCase, 2, 0);
    checkButtons -> addWidget(wholeWord, 2, 1);
    checkButtons -> addWidget(useRegex, 3, 0);

    QVBoxLayout *buttonArea = new QVBoxLayout();
    buttonArea -> addStretch();
    buttonArea -> addWidget(findButton);

    layout -> addLayout(checkButtons);
    layout -> addLayout(buttonArea);

    dataArea -> addWidget(findText);
    dataArea -> addLayout(layout);

    findLayout -> addLayout(labelArea);
    findLayout -> addLayout(dataArea);

    findWindow -> setModalLayout(findLayout);
    findWindow -> setWindowModality(Qt::NonModal);

    findWindow -> setFixedSize(findWindow -> sizeHint());

    findWindow -> show();
}
