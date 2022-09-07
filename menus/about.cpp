void about(QMainWindow *window, QMenu *QMenu, QAction *action) {
    printf("about");
    FakeModal *aboutWindow = new FakeModal();
    aboutWindow -> setWindowTitle("About Scribe");   
    aboutWindow -> setStyleSheet("background: #f7f7f7;");

    QHBoxLayout *appDetailLayout = new QHBoxLayout();

    // insert logo
    QPixmap logo("menus/icons8-copybook-96.png");
    QLabel *logoLabel = new QLabel();
    logoLabel -> setPixmap(logo);
    logoLabel -> setAlignment(Qt::AlignTop);
    logoLabel -> setContentsMargins(0, 32, 12, 0);

    QVBoxLayout *titleLayout = new QVBoxLayout();
    titleLayout -> setSpacing(0);
    titleLayout -> setContentsMargins(0, 32, 0, 0);

    QLabel *title = new QLabel("Scribe");
    title -> setFont(QFont("Ubuntu", 36, QFont::Bold));
    title -> setAlignment(Qt::AlignTop | Qt::AlignLeft);
    title -> setFixedHeight(54);

    QLabel *description = new QLabel("Text Editor");
    description -> setFont(QFont("Ubuntu", 18, QFont::Normal));
    description -> setFixedHeight(28);
    description -> setAlignment(Qt::AlignTop | Qt::AlignLeft);

    titleLayout -> addWidget(title);
    titleLayout -> addWidget(description);
    titleLayout -> addStretch();

    QString version = "development-master| Qt ";

    QLabel *versionLabel = new QLabel(version.append(QT_VERSION_STR));
    versionLabel -> setFont(QFont("Ubuntu", 12, QFont::Normal));
    versionLabel -> setAlignment(Qt::AlignCenter);
    versionLabel -> setStyleSheet("color: #8c8c8c;");
    versionLabel -> setContentsMargins(0, 12, 0, 0);

    appDetailLayout -> addStretch();
    appDetailLayout -> addWidget(logoLabel);
    appDetailLayout -> addLayout(titleLayout);
    appDetailLayout -> addStretch();

    QVBoxLayout *aboutLayout = new QVBoxLayout();
    aboutLayout -> addLayout(appDetailLayout);
    aboutLayout -> addWidget(versionLabel);
    aboutLayout -> addStretch();

    aboutWindow -> setModalLayout(aboutLayout);
    aboutWindow -> setFixedSize(400, 200);

    aboutWindow -> show();
}

void aboutQt(QMainWindow *window, QMenu *QMenu, QAction *action) {
    printf("about QT");
}
