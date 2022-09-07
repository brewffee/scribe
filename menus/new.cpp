#include "save.cpp"

void newFile(QMainWindow *window, QMenu *QMenu, QAction *action) {
    printf ("newFile\n");
    QTextEdit *centralWidget = static_cast<QTextEdit*>(window -> centralWidget());

    // hold up! might wanna save first
    if (!centralWidget -> toPlainText().isEmpty()) {
        FakeModal *newWindow = new FakeModal();
        newWindow -> setWindowTitle("\t ");
        newWindow -> setStyleSheet("background: #f7f7f7;");

        QLabel *title = new QLabel();
        title -> setText(QString("Save changes to %1").arg("Untitled") + "?");
        title -> setContentsMargins(36, 0, 36, 6);
        title -> setAlignment(Qt::AlignCenter | Qt::AlignTop);
        
        QFont titleFont = title -> font();
        titleFont.setPointSize(20);
        titleFont.setBold(true);

        title -> setFont(titleFont);

        QLabel *message = new QLabel();
        message -> setText("If you don't save, all changes will be lost.");
        message -> setContentsMargins(36, 0, 36, 18);
        message -> setAlignment(Qt::AlignCenter);

        QFont messageFont = message -> font();
        messageFont.setPointSize(18);
        messageFont.setBold(true);

        // buttons
        PushButton *cancelButton = new PushButton("Cancel");
        cancelButton -> setFixedWidth(150);
        cancelButton -> connect(cancelButton, SIGNAL(clicked()), newWindow, SLOT(close()));

        PushButton *discardButton = new PushButton("Discard");
        discardButton -> setFixedWidth(150);
        QObject::connect(discardButton, &PushButton::pressed, [newWindow, centralWidget]() {
            printf ("discarded document\n");
            newWindow -> close();
            centralWidget -> setPlainText(""); 
        });

        PushButton *saveButton = new PushButton("Save");
        saveButton -> setFixedWidth(150);
        saveButton -> setType(ButtonType::Primary);
        QObject::connect(saveButton, &PushButton::pressed, [window, newWindow]() {
            newWindow -> close();
            saveFile(window, nullptr, nullptr);
        });

        // layout
        QVBoxLayout *layout = new QVBoxLayout();
        layout -> addWidget(title);
        layout -> addWidget(message);

        QHBoxLayout *buttonLayout = new QHBoxLayout();
        buttonLayout -> addWidget(cancelButton);
        buttonLayout -> addWidget(discardButton);
        buttonLayout -> addWidget(saveButton);

        layout -> addLayout(buttonLayout);

        newWindow -> setModalLayout(layout);
        newWindow -> show();
    }
}
