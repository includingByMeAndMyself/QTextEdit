#include "QTextEdit.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication EditorApp(argc, argv);
    QTextEdit Editor;
    Editor.show();
    return EditorApp.exec();
}
