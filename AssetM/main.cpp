#include "assetmmainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AssetMMainWindow w;
    w.show();
    return a.exec();
}
