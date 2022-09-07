void findAndReplace(QMainWindow *window, QMenu *QMenu, QAction *action) {
    FakeModal *findWindow = new FakeModal();
    findWindow -> setWindowTitle("Find and Replace");
    findWindow -> setStyleSheet("background: #f7f7f7;");

    QLabel *findName = new QLabel("Find");
    findName -> setContentsMargins(0, 6, 2, 0);
    findName -> setFixedWidth(75);

    QLabel *replaceName = new QLabel("Replace");
    replaceName -> setContentsMargins(0, 12, 2, 0);
    replaceName -> setFixedWidth(75);

    QHBoxLayout *findLayout = new QHBoxLayout();

    LineEdit *findText = new LineEdit();
    findText -> setFixedWidth(350);

    PushButton *backButton = new PushButton("^");
    backButton -> setType(ButtonType::SecondaryIcon);

    PushButton *nextButton = new PushButton("v");
    nextButton -> setType(ButtonType::SecondaryIcon);

    LineEdit *replaceText = new LineEdit();
    replaceText -> setFixedWidth(420);

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

    PushButton *findButton = new PushButton("Find");
    findButton -> setType(ButtonType::Primary);

    PushButton *replaceButton = new PushButton("Replace");
    PushButton *replaceAllButton = new PushButton("Replace All");

    findButton -> connect(findButton, SIGNAL(clicked()), findWindow, SLOT(close()));

    QHBoxLayout *findTextLayout = new QHBoxLayout();

    QVBoxLayout *labelArea = new QVBoxLayout();
    labelArea -> addWidget(findName);
    labelArea -> addWidget(replaceName);
    labelArea -> addStretch();
    findName -> setAlignment(Qt::AlignRight | Qt::AlignTop);
    replaceName -> setAlignment(Qt::AlignRight | Qt::AlignTop);

    QVBoxLayout *dataArea = new QVBoxLayout();

    QVBoxLayout *layout = new QVBoxLayout();

    QGridLayout *checkButtons = new QGridLayout();
    checkButtons -> setContentsMargins(0, 4, 0, 8);
    checkButtons -> addWidget(matchCase, 2, 0);
    checkButtons -> addWidget(wholeWord, 2, 1);
    checkButtons -> addWidget(useRegex, 3, 0);

    QHBoxLayout *buttonArea = new QHBoxLayout();
    buttonArea -> addStretch();
    buttonArea -> addWidget(replaceAllButton);
    buttonArea -> addWidget(replaceButton);
    buttonArea -> addWidget(findButton);
    
    layout -> addLayout(checkButtons);
    layout -> addLayout(buttonArea);

    findTextLayout -> addWidget(findText);
    findTextLayout -> addWidget(backButton);
    findTextLayout -> addWidget(nextButton);


    dataArea -> addLayout(findTextLayout);
    dataArea -> addWidget(replaceText);
    dataArea -> addLayout(layout);

    findLayout -> addLayout(labelArea);
    findLayout -> addLayout(dataArea);

    findWindow -> setModalLayout(findLayout);
    findWindow -> setWindowModality(Qt::NonModal);

    findWindow -> setFixedSize(findWindow -> sizeHint());

    findWindow -> show();
}
