#ifndef TEXTEDIT_H
#define TEXTEDIT_H
#endif

#include "qt.h"

// Apply styling, including line coloring
class TextEdit: public QTextEdit {
    Q_OBJECT

    public:
        TextEdit(QString type, QWidget *parent = 0) : QTextEdit(parent) {
            setStyleSheet(" \
                QTextEdit { border: none; padding: 4px 2px 4px 4px; background: white; selection-background-color: lightgray; selection-color: #000; } \
            ");

            if (type == "editor") {
                setLineWrapMode(QTextEdit::NoWrap); // depend on settings later
                setAcceptRichText(false);
                setFont(QFont("Monospace"));
                setTabStopDistance(32);
                document() -> setDocumentMargin(0);
            }

            // style the scrollbars (they arent initialized by default, so we cant do this in its own constructor)
            QString styleSheet = " \
                QScrollBar { border: none; background: transparent; width: 8px; } \
                QScrollBar::handle { background: rgba(0,0,0,0.1); border: none; border-radius: 4px; } \
                QScrollBar::handle:hover { background: rgba(0,0,0,0.15); } \
                QScrollBar::handle:pressed { background: rgba(0,0,0,0.2); } \
                QScrollBar::add-line, QScrollBar::sub-line { background: none; } \
                QScrollBar::add-page, QScrollBar::sub-page { background: none; } \
            ";
            
            verticalScrollBar() -> setStyleSheet(styleSheet);
            horizontalScrollBar() -> setStyleSheet(styleSheet);

            // Style the context menu
            QMenu *contextMenu = new QMenu(this);
            contextMenu -> setStyleSheet(" \
                QMenu { background: #fff; border: 1px solid #ddd; border-radius: 6px; } \
                QMenu::item { padding: 4px 8px 4px 8px; } \
                QMenu::item:selected { background: #f7f7f7; } \
                QMenu::separator { height: 1px; background: #ddd; margin: 4px 0; } \
            ");
        }

        void getDetails(QLabel *posLabel, QLabel *countLabel, QLabel *insLabel) {
            int line = textCursor().blockNumber();
            int column = textCursor().columnNumber();
            int charCount = toPlainText().length();
            bool isOverwrite = overwriteMode();

            posLabel -> setText(QString("  Ln %1, Col %2").arg(line).arg(column));
            countLabel -> setText(QString("Characters: %1").arg(charCount));

            if (isOverwrite) insLabel -> setText("OVR  ");
            else insLabel -> setText("INS  ");
        }

        void onCursorPositionChanged(QLabel *cursorPos, QLabel *charCount, QLabel *insMode) {
            // colors the current line
            QObject::connect(this, &TextEdit::cursorPositionChanged, [this, cursorPos, charCount, insMode]() {
                getDetails(cursorPos, charCount, insMode);

                // get the current selection
                QList<QTextEdit::ExtraSelection> extraSelections;
                QTextEdit::ExtraSelection selection;

                selection.format.setBackground(QColor(245, 245, 245));
                selection.format.setProperty(QTextFormat::FullWidthSelection, true);
                selection.cursor = textCursor();
                selection.cursor.clearSelection();
                extraSelections.append(selection);

                setExtraSelections(extraSelections);

                if (overwriteMode()) {
                    // get char and adjust cursor size accordingly
                    QString currentChar = toPlainText().mid(textCursor().position(), 1);
                    if (currentChar == "") {
                        setCursorWidth(1);
                    } else {
                        int size = fontMetrics().horizontalAdvance(currentChar);
                        setCursorWidth(size);                           
                    }
                }
            });
        }
        
        void onSelectionChanged(QLabel *cursorPos, QLabel *charCount, QLabel *insMode) {
            printf("selectionChanged\n");
            if (textCursor().hasSelection()) {
                setCursorWidth(1);
            } else if (overwriteMode()) {
                // maybe lets make it its own function
                QString currentChar = toPlainText().mid(textCursor().position(), 1);
                if (currentChar == "") {
                    setCursorWidth(1);
                } else {
                    int size = fontMetrics().horizontalAdvance(currentChar);
                    setCursorWidth(size);                           
                }
            }
        }

        // edit context menu
        void contextMenuEvent(QContextMenuEvent *event) {
            QMenu *contextMenu = createStandardContextMenu();

            // style the menu 
            contextMenu -> setStyleSheet(" \
                QMenu { background: white; border: 1px solid #ddd; border-radius: 6px; padding: 6px; } \
                QMenu::item { padding: 4px 18px; } \
                QMenu::item:selected { background: #f7f7f7; border-radius: 6px; } \
                QMenu::separator { height: 1px; background: #ddd; margin: 8px 0; } \
            ");
            contextMenu -> setMinimumWidth(200);
            contextMenu -> setAttribute(Qt::WA_TranslucentBackground);

            // remove 9 default actions
            for (int i = 0; i < 9; i++) {
                contextMenu -> removeAction(contextMenu -> actions().at(0));
            }

            // add the new actions
            contextMenu -> addAction("Undo", this, SLOT(undo())) -> setShortcut(QKeySequence::Undo);
            contextMenu -> addAction("Redo", this, SLOT(redo())) -> setShortcut(QKeySequence("CTRL+Y"));
            contextMenu -> addSeparator();
            contextMenu -> addAction("Cut", this, SLOT(cut())) -> setShortcut(QKeySequence::Cut);
            contextMenu -> addAction("Copy", this, SLOT(copy())) -> setShortcut(QKeySequence::Copy);
            contextMenu -> addAction("Paste", this, SLOT(paste())) -> setShortcut(QKeySequence::Paste);
            contextMenu -> addSeparator();
            contextMenu -> addAction("Select All", this, SLOT(selectAll())) -> setShortcut(QKeySequence::SelectAll);
            // contextMenu -> addSeparator();
            // contextMenu -> addAction("Spell Check");   

            // activate or deactivate the actions based upon the current state of the text edit
            // if the document is empty, disable undo 
            if (toPlainText().isEmpty()) contextMenu -> actions().at(0) -> setDisabled(true);
            // redo

            // if nothing is selected, disable cut, and copy
            if (textCursor().hasSelection() == false) {
                contextMenu -> actions().at(3) -> setDisabled(true);
                contextMenu -> actions().at(4) -> setDisabled(true);
                contextMenu -> actions().at(6) -> setDisabled(true);
            }

            // if clipboard is empty or doesn't contain text, disable paste
            if (QApplication::clipboard() -> text().isEmpty()) {
                contextMenu -> actions().at(5) -> setDisabled(true);
            }

            contextMenu -> exec(event -> globalPos());
            delete contextMenu;
        }
};
