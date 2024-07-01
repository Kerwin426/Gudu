#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);//编写一个qt的图形化界面程序，一定要有QApplication对象,有且只有一个
    a.setQuitOnLastWindowClosed(false);
    MainWindow w;//以 MainWindow类创建一个窗口
    w.show();
    return a.exec();//exec函数表示让程序跑起来
}
