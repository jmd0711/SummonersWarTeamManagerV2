#include "monsterrequest.h"
#include "ui_monsterrequest.h"

MonsterRequest::MonsterRequest(Profile *pr, QString battle, int indexFiltered, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MonsterRequest),
    profile(pr),
    battleName{ battle },
    teamIndex{ indexFiltered }
{
    ui->setupUi(this);
    resize(QDesktopWidget().availableGeometry(this).size() * 0.6);
    setAttribute(Qt::WA_DeleteOnClose);

    monsterListWidget = new MonsterListView(profile, MonsterListView::REQUEST, this);

    //  TODO could remove member variables and just pass arguments
    monsterListWidget->setBattleName(battleName);
    monsterListWidget->setTeamIndex(teamIndex);

    ui->scrollArea->setWidgetResizable(true);
    ui->scrollArea->setWidget(monsterListWidget);
}

MonsterRequest::~MonsterRequest()
{
    delete ui;
}
