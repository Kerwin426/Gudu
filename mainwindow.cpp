#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "QMenu"
#include "QAction"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("孤独摇滚");
    //设置应用到托盘
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(QIcon("://gudu/shan.png"));//之前一直不行是因为路径错误了
    setWindowIcon(QIcon("://gudu/shan.png"));
    //trayIcon->setIcon(QIcon("://gudu/1.png"));
    //创建托盘菜单
    traymenu = new QMenu(this);

    //创建动作
    quitAction = new QAction("退出",this);
    traymenu->addAction(quitAction);
    trayIcon->setContextMenu(traymenu);
    trayIcon->setToolTip("孤独摇滚!");//图标提示
    connect(quitAction,&QAction::triggered,this,&MainWindow::close);
    //closeTrayIcon(quitAction);

    //setAttribute(Qt::WA_TranslucentBackground);

    this->m_Yamada_Ryo = new Yamada_Ryo;
    this->m_Yamada_Ryo->setParent(this);
    this->m_Yamada_Ryo->running();

    this->setWindowFlags(this->windowFlags()|Qt::WindowStaysOnTopHint);

    setWindowFlag(Qt::FramelessWindowHint);//窗口无边框
    setWindowFlags(windowFlags()|Qt::WindowStaysOnTopHint);//窗口置顶
    setAttribute(Qt::WA_TranslucentBackground);//窗口保持透明
    this->setFixedSize(200,200);//设定窗口大小为200*200

    connect(this->m_Yamada_Ryo,&Yamada_Ryo::changePix,[=](){
        update();//渲染主窗口图片
    });

    trayIcon->show();
}
void MainWindow::closeTrayIcon(QAction *quitaction){
    connect(quitaction,&QAction::triggered,this,&MainWindow::close);
}//这没用

void MainWindow::closeEvent(QCloseEvent *event){
    if(trayIcon->isVisible()){
        trayIcon->hide();
        trayIcon->deleteLater();

    }//这里进程退出的时候，线程退出的顺序有问题，表现为关闭窗口,但是exe还存在

}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    diff_ = event->globalPos()-this->pos();
}
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    diff_ = QPoint();
}
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    this->move(event->globalPos()-this->diff_);
}

void MainWindow::paintEvent(QPaintEvent *){
    QPainter painters(this);
    QPixmap pixmap = this->m_Yamada_Ryo->Yamada_Ryo_pix;
    if(!pixmap.isNull()){
        QSize windowSize = this->size();
        QPixmap scalePixmap = pixmap.scaled(windowSize,Qt::KeepAspectRatio,Qt::SmoothTransformation);
        int x = (windowSize.width()-scalePixmap.width())/2;
        int y = (windowSize.height()-scalePixmap.height())/2;
        painters.drawPixmap(x,y,scalePixmap);
    }

}
MainWindow::~MainWindow()
{
    delete ui;
}
