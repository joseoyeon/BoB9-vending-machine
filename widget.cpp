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
    m.information(nullptr, "Left Money", QString("Left Money: %1").arg(money));
    resetMoney();
}
