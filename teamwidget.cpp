#include "teamwidget.h"
#include "ui_teamwidget.h"

TeamWidget::TeamWidget(Profile *pr, QString battle, int index, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TeamWidget),
    profile{ pr },
    battleName{ battle },
    teamIndex{ index }
{
    ui->setupUi(this);
    ui->monstersLayout->setAlignment(Qt::AlignLeft);
    setAttribute(Qt::WA_DeleteOnClose);
}

TeamWidget::~TeamWidget()
{
    delete ui;
}

void TeamWidget::on_deleteButton_released()
{
    emit deleteReleased(battleName, teamIndex);
}
