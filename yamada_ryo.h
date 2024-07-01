#ifndef YAMADA_RYO_H
#define YAMADA_RYO_H
#include<QWidget>
#include<QTimer>

class Yamada_Ryo :public QWidget
{
    Q_OBJECT
public:
    explicit Yamada_Ryo(QWidget *parent =0);

    int min =1, max = 7;//图片序号标识

    QPixmap Yamada_Ryo_pix;

    QTimer *timer;

    void running();


signals:
    void changePix();//一开始以为是信号要实现，但其实是要重新构建(.h文件没有生成相应的moc文件，导致signal/slot 关联不到)
};

#endif // YAMADA_RYO_H
