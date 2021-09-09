#include "QTextEdit.h"
#include "ui_QTextEdit.h"

QTextEditClass::QTextEditClass(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::QTextEditClass)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);

    connect(ui->actionNew, &QAction::triggered, this, &QTextEditClass::newDocument);
    connect(ui->actionOpen, &QAction::triggered, this, &QTextEditClass::Open);
    connect(ui->actionSave, &QAction::triggered, this, &QTextEditClass::saveDoc);
    connect(ui->actionSave_as, &QAction::triggered, this, &QTextEditClass::saveAs);
    connect(ui->actionPrint, &QAction::triggered, this, &QTextEditClass::Print);
    connect(ui->actionExit, &QAction::triggered, this, &QTextEditClass::Exit);
  
}

QTextEditClass::~QTextEditClass()
{
    delete ui;
}

void QTextEditClass::newDocument()
{
    currentFile.clear();
    ui->textEdit->setText(QString());
}


void QTextEditClass::Open()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
    QFile file(fileName);
    currentFile = fileName;

    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        return;
    }

    setWindowTitle(fileName);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}

void QTextEditClass::saveDoc()
{

}

void QTextEditClass::saveAs()
{
}

void QTextEditClass::Print()
{
}

void QTextEditClass::Exit()
{
}

void QTextEditClass::Copy()
{
}

void QTextEditClass::Cut()
{
}

void QTextEditClass::Paste()
{
}

void QTextEditClass::undo()
{
}

void QTextEditClass::rado()
{
}

void QTextEditClass::selectFont()
{
}

void QTextEditClass::setFontBold(bool bold)
{
}

void QTextEditClass::setFontUnderline(bool underline)
{
}

void QTextEditClass::setFontItalic(bool italic)
{
}

void QTextEditClass::about()
{
}


