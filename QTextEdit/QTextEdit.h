#pragma once

#include <QtWidgets/QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

#include "ui_QTextEdit.h"

namespace Ui {
    class QTextEditClass;
}

class QTextEditClass : public QMainWindow
{
    Q_OBJECT

public:
    QTextEditClass(QWidget *parent = Q_NULLPTR);
    ~QTextEditClass();

private slots:
    
    void newDocument();
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
    Ui::QTextEditClass *ui;
    QString currentFile;
};
