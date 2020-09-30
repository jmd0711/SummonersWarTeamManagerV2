#include "teammenu.h"
#include "ui_teammenu.h"

TeamMenu::TeamMenu(QString name, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TeamMenu)
{
    ui->setupUi(this);
    ui->label->setText(name);
}

TeamMenu::~TeamMenu()
{
    delete ui;
}
