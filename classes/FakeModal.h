#ifndef FAKEMODAL_H
#define FAKEMODAL_H
#endif

#include "qt.h"

// Emulate a modal without the limitations imposed by QDialog
class FakeModal: public QMainWindow {
    Q_OBJECT

    public:
        void setModalLayout(QLayout *layout) {
            setCentralWidget((new QWidget()));
            centralWidget() -> setLayout(layout);
            setWindowModality(Qt::ApplicationModal);
            setWindowFlags(Qt::Dialog | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint);
            //setFixedSize(this -> sizeHint());
        }
};
