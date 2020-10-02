#include "teamdisplay.h"
#include "ui_teamdisplay.h"

TeamDisplay::TeamDisplay(Profile *pr, QString battleName, int indexFiltered, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TeamDisplay),
    profile{ pr },
    team{ profile->getTeam(battleName, indexFiltered) }
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);

    ui->lineEdit->setText(team->getTeamName());
    ui->textEdit->setText(team->getTeamDescription());
}

TeamDisplay::~TeamDisplay()
{
    delete ui;
}

void TeamDisplay::on_pushButton_released()
{
    team->setTeamName(ui->lineEdit->text());
    team->setTeamDescription(ui->textEdit->toPlainText());
}
