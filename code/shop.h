
#ifndef SHOP_H
#define SHOP_H

#include <QMainWindow>
#include <QWidget>
#include<QLabel>
#include<QGridLayout>
#include<QStringList>
#include<QPixmap>


QT_BEGIN_NAMESPACE
namespace Ui { class shop; }
QT_END_NAMESPACE

class shop : public QWidget
{
    Q_OBJECT

private:
    Ui::shop *ui;
    QStringList name = {"力量饮料","钟表","合金缆绳","四叶草","宝石上光剂","炸弹"};
    QList<int> price = {100,200,300,400,500,600};
    QLabel* good[7];


public:

    int mymoney;
    int cost[6]={300,600,450,300,750,150};
    int addtime = 0;
    bool isbought[6]={0,0,0,0,0,0};
    shop(QWidget *parent = nullptr);
    ~shop();
    //void paintEvent(QPaintEvent* event);
private slots:
    void cannotbuy();
    void on_pushButton_clicked();
    void handlepurchasebutton();

    void on_pushButton_2_clicked();
    void handlepurchasebutton2();

    void on_pushButton_3_clicked();
    void handlepurchasebutton3();

    void on_pushButton_4_clicked();
    void handlepurchasebutton4();

    void on_pushButton_5_clicked();
    void handlepurchasebutton5();

    void on_pushButton_6_clicked();
    void handlepurchasebutton6();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void mdisplay();


    void on_toolButton_display_clicked();
};
#endif // MAINWINDOW_H
