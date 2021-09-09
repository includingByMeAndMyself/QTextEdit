#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QTextEdit.h"

class QTextEdit : public QMainWindow
{
    Q_OBJECT

public:
    QTextEdit(QWidget *parent = Q_NULLPTR);
    ~QTextEdit();

private slots:
    
    void newDoc();
    void Open();
    void saveDoc();
    void saveAs();
    void Print();
    void Exit();
    void Copy();
    void Cut();
    void Paste();
    void undo();
    void rado();


    void selectFont();

    void setFontBold(bool bold);
    void setFontUnderline(bool underline);
    void setFontItalic(bool italic);

    void about();




private:
    Ui::QTextEditClass ui;
    QString currentFile;S
};
