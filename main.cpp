
#include "mainwindow.h"
#include <QFile>
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile qss(":/style/style.qss");
    if(qss.open(QFile::ReadOnly)){
        qDebug("open qss sucessfully");
        QString style = QLatin1String(qss.readAll());
        a.setStyleSheet(style);
        qss.close();
    }
    else {
        qDebug("qss load failed");
        return 0;
    }
    MainWindow w;
    w.setWindowTitle("Album");
    w.showMaximized();
//    w.show();
    return a.exec();
}
