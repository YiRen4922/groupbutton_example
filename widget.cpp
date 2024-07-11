#include "widget.h"
#include "./ui_widget.h"
#include "page1.h"
#include "page2.h"
#include <QButtonGroup>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , page1(new Page1)
    , page2(new Page2)
{
    ui->setupUi(this);
    ui->stackedWidget->insertWidget(1,page1);
    ui->stackedWidget->insertWidget(2,page2);

    // 设置默认显示页面（如果需要）
    ui->stackedWidget->setCurrentIndex(1);

    buttonGroup = new QButtonGroup(this);
    buttonGroup->addButton(ui->pushButton, 1);
    buttonGroup->addButton(ui->pushButton_2, 2);
    buttonGroup->setExclusive(true);


    // 连接按钮信号和槽
    // connect(ui->pushButton, &QPushButton::clicked, this, &Widget::on_pushButton_clicked);
    // connect(ui->pushButton_2, &QPushButton::clicked, this, &Widget::on_pushButton_2_clicked);
    connect(buttonGroup, &QButtonGroup::idPressed, this, &Widget::slot_pushButton_pressed);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::slot_pushButton_pressed(int id)
{
    ui->stackedWidget->setCurrentIndex(id);
}
