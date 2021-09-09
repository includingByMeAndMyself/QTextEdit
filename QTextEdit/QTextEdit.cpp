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

#if !defined(QT_PRINTSUPPORT_LIB) || !QT_CONFIG(printer)
    ui->actionPrint->setEnabled(true);
#endif
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
    QString fileName;
    if (currentFile.isEmpty()) {
        fileName = QFileDialog::getSaveFileName(this, "Save");
        currentFile = fileName;
    }
    else {
        fileName = currentFile;
    }
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }

    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();
}

void QTextEditClass::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save as");
    QFile file(fileName);

    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }
    currentFile = fileName;
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();
}

void QTextEditClass::Print()
{
#if defined(QT_PRINTSUPPORT_LIB) && QT_CONFIG(printer)
    QPrinter printDev;
#if QT_CONFIG(printdialog)
    QPrintDialog dialog(&printDev, this);
    if (dialog.exec() == QDialog::Rejected)
        return;
#endif // QT_CONFIG(printdialog)
    ui->textEdit->print(&printDev);
#endif // QT_CONFIG(printer)
}

void QTextEditClass::Exit()
{
    QCoreApplication::quit();
}




