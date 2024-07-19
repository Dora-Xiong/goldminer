#include "shop.h"
#include "ui_shop.h"
//#include "mainwindow.h"
#include<QPainter>
#include<QPaintEvent>
#include<QMessageBox>
#include <QPushButton>

shop::shop(QWidget *parent)
    : QWidget(parent),
      ui(new Ui::shop)
{
    ui->setupUi(this);
    this->setWindowTitle("GameStore");
    this->setFixedSize(700,600);

    QPalette pa(this->palette());

    QPixmap pixmap(":/newimages/IMG_0397.PNG");
    QCursor cursor= QCursor(pixmap,-1,-1);
    setCursor(cursor);//设置光标图案


    QPixmap Images(":/shop_image/shop_image/background.jpeg");
    Images=Images.scaled(this->size());


    QBrush *pic = new QBrush(Images);

    pa.setBrush(QPalette::Window,*pic);

    this->setAutoFillBackground(true);
    this->setPalette(pa);

    ui->money_sum->setVisible(true);
    QString moneystring = "             $" + QString::number(mymoney,10);
    ui->money_sum->setText(moneystring);


}

void shop::cannotbuy(){
    QMessageBox msgBox;
    msgBox.setText("对不起～努力赚更多金币吧");
    msgBox.exec();
}

shop::~shop()
{
    delete ui;
}

void shop::on_pushButton_clicked()
{
    QWidget *new_win = new QWidget();
    new_win->resize(200,200);
    new_win->setWindowTitle("力量饮料");

    QPixmap bk(":/shop_image/background.jpeg");
    bk.scaled(new_win->size());
    QPalette palette;
    palette.setBrush(new_win->backgroundRole(),QBrush(bk));
    new_win->setPalette(palette);
    new_win->setAutoFillBackground(true);

    QLabel* label=new QLabel("可以加快下一关中矿工提升的速度\n一次性使用，购买即生效。");
    QPushButton* button=new QPushButton(new_win);
    button->setText("确定购买");
    QVBoxLayout* layout=new QVBoxLayout();
    layout->addWidget(label);
    layout->addWidget(button);
    new_win->setLayout(layout);
    new_win->show();
    QObject::connect(button, &QPushButton::clicked, this, [new_win,this](){
        new_win->close();
        if(mymoney>=cost[0]){
        handlepurchasebutton();
        isbought[0] = 1;
        mymoney-=cost[0];
        shop::ui->label->setVisible(false);
        shop::ui->pushButton->setVisible(false);
        QString moneystring = "             $" + QString::number(mymoney,10);
        ui->money_sum->setText(moneystring);
        }
        else{
            cannotbuy();
        }


    });
}

void shop::handlepurchasebutton(){
    QMessageBox msgBox;
    msgBox.setText("购买成功～");

    msgBox.exec();

}


void shop::on_pushButton_2_clicked()
{
    QWidget *new_win = new QWidget();
    new_win->resize(200,200);
    new_win->setWindowTitle("时钟");

    QPixmap bk(":/shop_image/background.jpeg");
    bk.scaled(new_win->size());
    QPalette palette;
    palette.setBrush(new_win->backgroundRole(),QBrush(bk));
    new_win->setPalette(palette);
    new_win->setAutoFillBackground(true);

    QLabel* label=new QLabel("可以延长下一关的时间限制\n一次性使用，购买即生效。");
    QPushButton* button=new QPushButton(new_win);
    button->setText("确定购买");
    QVBoxLayout* layout=new QVBoxLayout();
    layout->addWidget(label);
    layout->addWidget(button);
    new_win->setLayout(layout);
    new_win->show();
    QObject::connect(button, &QPushButton::clicked, this, [new_win,this](){
        new_win->close();
        if(mymoney>=cost[1]){
        handlepurchasebutton2();
        isbought[1] = 1;
        mymoney-=cost[1];
        shop::ui->label_2->setVisible(false);
        shop::ui->pushButton_2->setVisible(false);
        QString moneystring = "          $" + QString::number(mymoney,10);
        ui->money_sum->setText(moneystring);
        }
        else{
            cannotbuy();
        }


        addtime+=10;
    });
}

void shop::handlepurchasebutton2(){
    QMessageBox msgBox;
    msgBox.setText("购买成功～");
    msgBox.exec();
}



void shop::on_pushButton_3_clicked()
{
    QWidget *new_win = new QWidget();
    new_win->resize(200,200);
    new_win->setWindowTitle("合金缆绳");

    QPixmap bk(":/shop_image/background.jpeg");
    bk.scaled(new_win->size());
    QPalette palette;
    palette.setBrush(new_win->backgroundRole(),QBrush(bk));
    new_win->setPalette(palette);
    new_win->setAutoFillBackground(true);

    QLabel* label=new QLabel("在下一关中能够提升更重的物品\n一次性使用，购买即生效。");
    QPushButton* button=new QPushButton(new_win);
    button->setText("确定购买");
    QVBoxLayout* layout=new QVBoxLayout();
    layout->addWidget(label);
    layout->addWidget(button);
    new_win->setLayout(layout);
    new_win->show();
    QObject::connect(button, &QPushButton::clicked, this, [new_win,this](){
        new_win->close();
        if(mymoney>=cost[2]){
        handlepurchasebutton3();
        isbought[2] = 1;
        mymoney-=cost[2];
        shop::ui->label_3->setVisible(false);
        shop::ui->pushButton_3->setVisible(false);
        QString moneystring = "              $" + QString::number(mymoney,10);
        ui->money_sum->setText(moneystring);
        }
        else{
            cannotbuy();
        }


    });
}

void shop::handlepurchasebutton3(){
    QMessageBox msgBox;
    msgBox.setText("购买成功～");
    msgBox.exec();
}

void shop::on_pushButton_4_clicked()
{
    QWidget *new_win = new QWidget();
    new_win->resize(200,200);
    new_win->setWindowTitle("三叶草");

    QPixmap bk(":/shop_image/background.jpeg");
    bk.scaled(new_win->size());
    QPalette palette;
    palette.setBrush(new_win->backgroundRole(),QBrush(bk));
    new_win->setPalette(palette);
    new_win->setAutoFillBackground(true);

    QLabel* label=new QLabel("提高神秘袋子的奖励价值\n一次性使用，购买即生效。");
    QPushButton* button=new QPushButton(new_win);
    button->setText("确定购买");
    QVBoxLayout* layout=new QVBoxLayout();
    layout->addWidget(label);
    layout->addWidget(button);
    new_win->setLayout(layout);
    new_win->show();
    QObject::connect(button, &QPushButton::clicked, this, [new_win,this](){
        new_win->close();
        if(mymoney>=cost[3]){
        handlepurchasebutton4();
        shop::ui->pushButton_4->setVisible(false);
        mymoney-=cost[3];
        isbought[3] = 1;
        QString moneystring = "             $" + QString::number(mymoney,10);
        ui->money_sum->setText(moneystring);
        }
        else{
            cannotbuy();
        }


    });
}

void shop::handlepurchasebutton4(){
    QMessageBox msgBox;
    msgBox.setText("购买成功～");
    msgBox.exec();
}

void shop::on_pushButton_5_clicked()
{
    QWidget *new_win = new QWidget();
    new_win->resize(200,200);
    new_win->setWindowTitle("宝石上光剂");

    QPixmap bk(":/shop_image/background.jpeg");
    bk.scaled(new_win->size());
    QPalette palette;
    palette.setBrush(new_win->backgroundRole(),QBrush(bk));
    new_win->setPalette(palette);
    new_win->setAutoFillBackground(true);

    QLabel* label=new QLabel("在下一关中钻石的价值更高\n一次性使用，购买即生效。");
    QPushButton* button=new QPushButton(new_win);
    button->setText("确定购买");
    QVBoxLayout* layout=new QVBoxLayout();
    layout->addWidget(label);
    layout->addWidget(button);
    new_win->setLayout(layout);
    new_win->show();
    QObject::connect(button, &QPushButton::clicked, this, [new_win,this](){
        new_win->close();
        if(mymoney>=cost[4]){
        handlepurchasebutton5();
        mymoney-=cost[4];
        isbought[4] = 1;
        QString moneystring = "             $" + QString::number(mymoney,10);
        ui->money_sum->setText(moneystring);
        shop::ui->label_5->setVisible(false);
        shop::ui->pushButton_5->setVisible(false);
        }
        else{
            cannotbuy();
        }

    });
}

void shop::handlepurchasebutton5(){
    QMessageBox msgBox;
    msgBox.setText("购买成功～");
    msgBox.exec();
}

void shop::on_pushButton_6_clicked()
{
    QWidget *new_win = new QWidget();
    new_win->resize(200,200);
    new_win->setWindowTitle("炸药");

    QPixmap bk(":/shop_image/background.jpeg");
    bk.scaled(new_win->size());
    QPalette palette;
    palette.setBrush(new_win->backgroundRole(),QBrush(bk));
    new_win->setPalette(palette);
    new_win->setAutoFillBackground(true);

    QLabel* label=new QLabel("炸掉钩子上的物品\n一次性使用，但可以存储。");//使用炸药应该判断是否有物品
    QPushButton* button=new QPushButton(new_win);
    button->setText("确定购买");
    QVBoxLayout* layout=new QVBoxLayout();
    layout->addWidget(label);
    layout->addWidget(button);
    new_win->setLayout(layout);
    new_win->show();
    QObject::connect(button, &QPushButton::clicked, this, [new_win,this](){
        new_win->close();
        if(mymoney>=cost[5]){
        mymoney-=cost[5];
        isbought[5] = 1;
        handlepurchasebutton6();
        QString moneystring = "             $" + QString::number(mymoney,10);
        ui->money_sum->setText(moneystring);
        shop::ui->label_6->setVisible(false);
        shop::ui->pushButton_6->setVisible(false);
        }
        else{
            cannotbuy();
        }

    });
}

void shop::handlepurchasebutton6(){
    QMessageBox msgBox;
    msgBox.setText("购买成功～");
    msgBox.exec();
}

void shop::on_pushButton_7_clicked()
{
    this->close();

}


void shop::on_pushButton_8_clicked()
{
    qApp->quit();
}

void shop::mdisplay(){
    QString moneystring = "           $" + QString::number(mymoney);
    ui->money_sum->setText(moneystring);
}


void shop::on_toolButton_display_clicked()
{
    QString moneystring = "           $" + QString::number(mymoney);
        ui->money_sum->setText(moneystring);
}

