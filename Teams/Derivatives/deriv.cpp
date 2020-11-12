#include "derivative.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    derivative w;
    w.show();
    return a.exec();
}
