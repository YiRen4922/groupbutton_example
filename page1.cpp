#include "page1.h"
#include "ui_page1.h"

Page1::Page1(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Page1)
{
    ui->setupUi(this);
    ui->label->setText("page111111");
}

Page1::~Page1()
{
    delete ui;
}
