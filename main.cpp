#include "mainlm.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainLM w;
    w.show();
    return a.exec();
}
