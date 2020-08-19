#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setButton(0);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::setButton(int money){
    ui->pbCoffee->setEnabled(money >= 100);
    ui->pbTea->setEnabled(money >= 150);
    ui->pbMilk->setEnabled(money >= 200);
}

void Widget::addMoney(int diff){
    money += diff;
    ui->lcdNumber->display(money);
    setButton(money);
}
void Widget::subMoney(int diff){
    money -= diff;
    ui->lcdNumber->display(money);
    setButton(money);
}
void Widget::resetMoney() {
    money =0;
    ui->lcdNumber->display(0);
    setButton(money);
}
void Widget::on_pb10_clicked()
{
    addMoney(10);
}

void Widget::on_pb50_clicked()
{
    addMoney(50);
}

void Widget::on_pb100_clicked()
{
    addMoney(100);
}

void Widget::on_pb500_clicked()
{
    addMoney(500);
}

void Widget::on_pbCoffee_clicked()
{
    subMoney(100);
}

void Widget::on_pbTea_clicked()
{
     subMoney(150);
}

void Widget::on_pbMilk_clicked()
{
      subMoney(500);
}

void Widget::on_pushButton_clicked()
{
    QMessageBox m;
    int moneyCount[4]={};
    int moneyTag[4] = {500,100,50,10};
    for(int i =0; i<4; i++){
        moneyCount[i]= money/moneyTag[i];
        money = money%moneyTag[i];
    }
    m.information(nullptr, "Left Money", QString("500 : %1\n100 : %2\n50 : %3\n10 : %4").arg(moneyCount[0]).arg(moneyCount[1]).arg(moneyCount[2]).arg(moneyCount[3]));
    resetMoney();
}
