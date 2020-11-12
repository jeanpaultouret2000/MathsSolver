#include "mainwindow.h"
#include <QApplication>
#include <QWidget>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.resize(2000, 1400);
    w.setWindowTitle("Handwritten Math Solver");
    w.setWindowIcon(QIcon("iconcse201.png"));
    w.show();
    return a.exec();
}
