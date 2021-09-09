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
  

private:
    Ui::QTextEditClass *ui;
    QString currentFile;
};
