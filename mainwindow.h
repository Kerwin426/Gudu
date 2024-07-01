#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "QSystemTrayIcon"
#include <QMainWindow>
#include "yamada_ryo.h"
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT// Qt信号和槽机制

public:
    MainWindow(QWidget *parent = nullptr);//
    ~MainWindow();
    Yamada_Ryo *m_Yamada_Ryo;
    void paintEvent(QPaintEvent*);

private:
    Ui::MainWindow *ui;
    QSystemTrayIcon *trayIcon;
    QMenu *traymenu;
    QAction *quitAction;
private:
    void closeTrayIcon(QAction * quitaction);
    void closeEvent(QCloseEvent* event);//重写关闭窗口事件，使得窗口关闭后，隐藏并删除托盘图标
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

};
#endif // MAINWINDOW_H
