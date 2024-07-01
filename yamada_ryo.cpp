#include "yamada_ryo.h"

Yamada_Ryo::Yamada_Ryo(QWidget *parent):QWidget(parent) {

    for(int i=0;i<=this->max;i++)//加载Yamada_Ryo的图像资源
    {
        QString str = QString("://gudu/%1.png").arg(i+1);
        this->Yamada_Ryo_pix.load(str);
    }

    this->timer = new QTimer(this);

    connect(timer,&QTimer::timeout,[=](){
        QString str = QString("://gudu/%1.png").arg(this->min++);
        this->Yamada_Ryo_pix.load(str);

        if(this->min>this->max)
        {
            this->min = 1;
        }

        emit changePix();
    });//利用Lambda表达式来连接定时器和timeout信号，动态加载信号，并更新min值

}
void Yamada_Ryo::running()
{
    this->timer->start(50);

}
