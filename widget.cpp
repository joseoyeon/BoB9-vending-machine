#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbMilk->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::addMoney(int diff){
    money += diff;
    ui->lcdNumber->display(money);
    if (money >= 100) {
        ui->pbCoffee->setEnabled(true);
    }
    if (money >= 150) {
        ui->pbTea->setEnabled(true);
    }
    if (money >= 200) {
            ui->pbMilk->setEnabled(true);
    }
}
void Widget::subMoney(int diff){
    money -= diff;
    ui->lcdNumber->display(money);
    if (money <= 100) {
        ui->pbCoffee->setEnabled(false);
    }
    if (money <= 150) {
        ui->pbTea->setEnabled(false);
    }
    if (money <= 200) {
            ui->pbMilk->setEnabled(false);
    }
}
void Widget::resetMoney() {
    money =0;
    ui->lcdNumber->display(0);
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbMilk->setEnabled(false);
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
