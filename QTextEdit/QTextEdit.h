#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QTextEdit.h"

class QTextEdit : public QMainWindow
{
    Q_OBJECT

public:
    QTextEdit(QWidget *parent = Q_NULLPTR);

private:
    Ui::QTextEditClass ui;
};
