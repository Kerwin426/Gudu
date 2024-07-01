#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "QMenu"
#include "QAction"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //setWindowTitle("孤独摇滚");
    //设置应用到托盘
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(QIcon("://gudu/shan.png"));//之前一直不行是因为路径错误了

    //创建托盘菜单
    traymenu = new QMenu(this);

    //创建动作
    quitAction = new QAction("退出",this);
    traymenu->addAction(quitAction);
    trayIcon->setContextMenu(traymenu);
    trayIcon->setToolTip("孤独摇滚!");//图标提示
    connect(quitAction,&QAction::triggered,this,&MainWindow::close);
    //closeTrayIcon(quitAction);

    setWindowFlag(Qt::FramelessWindowHint);
    setWindowFlags(windowFlags()|Qt::WindowStaysOnTopHint);
    //setAttribute(Qt::WA_TranslucentBackground);

    this->m_Yamada_Ryo = new Yamada_Ryo;
    this->m_Yamada_Ryo->setParent(this);
    this->m_Yamada_Ryo->running();

    connect(this->m_Yamada_Ryo,&Yamada_Ryo::changePix,[=](){
        update();
    });

    trayIcon->show();
}
void MainWindow::closeTrayIcon(QAction *quitaction){
    connect(quitaction,&QAction::triggered,this,&MainWindow::close);
}

void MainWindow::closeEvent(QCloseEvent *event){
    if(trayIcon->isVisible()){
        trayIcon->hide();
        trayIcon->deleteLater();
    }

}
void MainWindow::mousePressEvent(QMouseEvent *event)
{

}
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{

}
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{

}

MainWindow::~MainWindow()
{
    delete ui;
}
