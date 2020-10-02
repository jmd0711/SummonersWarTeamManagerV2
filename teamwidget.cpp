#include "teamwidget.h"
#include "ui_teamwidget.h"

TeamWidget::TeamWidget(Profile *pr, QString battle, int index, int initialCount, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TeamWidget),
    profile{ pr },
    battleName{ battle },
    teamIndex{ index },
    monsterCount{ initialCount }
{
    ui->setupUi(this);
    ui->monstersLayout->setAlignment(Qt::AlignLeft);
    setAttribute(Qt::WA_DeleteOnClose);



    if (initialCount > 0)
    {
        ui->teamButton->setText(profile->getTeam(battleName, teamIndex)->getTeamName());
        QVector<int> indexes = profile->getMonsterIndexes(battleName, teamIndex);
        for (int i = 0; i < indexes.count(); i++)
        {
            int monsterIndex = indexes[i];
            QToolButton *button = new QToolButton(this);
            button->setText(QString::number(monsterIndex));
            QSizePolicy policy(QSizePolicy::Fixed, QSizePolicy::Fixed);
            button->setMinimumSize(QSize(150, 150));
            policy.setHeightForWidth(true);
            button->setSizePolicy(policy);
            button->setIconSize(QSize(145, 145));
            button->setIcon(profile->getMonster(monsterIndex)->getImage());

            connect(button, &QToolButton::released, this, &TeamWidget::onMonsterButtonReleased);

            ui->monstersLayout->insertWidget(ui->monstersLayout->count() - 1, button);
        }
    }
    else
        ui->teamButton->setText("New Team");

    connect(profile, &Profile::monsterAddedToTeam, this, &TeamWidget::onMonsterAddedToTeam);
    connect(profile, &Profile::monsterRemovedFromTeam, this, &TeamWidget::onMonsterRemovedFromTeam);
    connect(profile, &Profile::monsterDeleted, this, &TeamWidget::onMonsterDeleted);
    connect(profile, &Profile::monsterUpdated, this, &TeamWidget::onMonsterUpdated);
}

TeamWidget::~TeamWidget()
{
    delete ui;
}

void TeamWidget::on_deleteButton_released()
{
    emit deleteReleased(battleName, teamIndex);
}

void TeamWidget::on_addMonsterButton_released()
{
    MonsterRequest *request = new MonsterRequest(profile, battleName, teamIndex, this);
    //connect
    request->show();
}

void TeamWidget::onMonsterAddedToTeam(QString battle, int indexFiltered, int monsterIndex)
{
    if (battle == battleName && indexFiltered == teamIndex)
    {
        QToolButton *button = new QToolButton(this);
        button->setText(QString::number(monsterIndex));
        QSizePolicy policy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        button->setMinimumSize(QSize(150, 150));
        policy.setHeightForWidth(true);
        button->setSizePolicy(policy);
        button->setIconSize(QSize(145, 145));
        button->setIcon(profile->getMonster(monsterIndex)->getImage());

        connect(button, &QToolButton::released, this, &TeamWidget::onMonsterButtonReleased);

        ui->monstersLayout->insertWidget(ui->monstersLayout->count() - 1, button);
        monsterCount++;
    }
}

void TeamWidget::onMonsterRemovedFromTeam(QString battle, int indexFiltered, int monsterIndex)
{
    if (battle == battleName && indexFiltered == teamIndex)
    {
        removeMonster(monsterIndex);
    }
}

void TeamWidget::onMonsterButtonReleased()
{
    int monsterIndex = dynamic_cast<QToolButton *>(sender())->text().toInt();
    MonsterDisplay *disp = new MonsterDisplay(profile, profile->getMonster(monsterIndex), MonsterDisplay::REMOVE, this);
    connect(disp, &MonsterDisplay::removeReleased, profile, &Profile::onMonsterRemoveReleased);
    disp->show();
}

void TeamWidget::onMonsterDeleted(int monsterIndex)
{
    for (int i = 0; i < monsterCount; i++)
    {
        QLayoutItem *item = ui->monstersLayout->itemAt(i);
        QWidget *widget = item->widget();
        QToolButton *button = dynamic_cast<QToolButton *>(widget);
        if (button->text().toInt() > monsterIndex)
            button->setText(QString::number(button->text().toInt() - 1));
    }
}

void TeamWidget::onMonsterUpdated(int monsterIndex)
{
    for (int i = 0; i < monsterCount; i++)
    {
        QLayoutItem *item = ui->monstersLayout->itemAt(i);
        QWidget *widget = item->widget();
        QToolButton *button = dynamic_cast<QToolButton *>(widget);
        if (button->text().toInt() == monsterIndex)
            button->setIcon(profile->getMonster(monsterIndex)->getImage());
    }
}

void TeamWidget::setMonsterCount(int value)
{
    monsterCount = value;
}

QString TeamWidget::getBattleName() const
{
    return battleName;
}

void TeamWidget::removeMonster(int monsterIndex)
{
    if (monsterCount == 0 || profile->existsInTeam(battleName, teamIndex, monsterIndex))
        return;
    monsterCount--;

    QLayoutItem *item = ui->monstersLayout->itemAt(monsterCount);
    QWidget *widget = item->widget();
    QToolButton *button = dynamic_cast<QToolButton *>(widget);

    //  Update all buttons from position of "monsterIndex" to second to last
    //  Start at second to last monster button (last will be deleted)
    int i = monsterCount - 1;
    int lastMonsterIndex = button->text().toInt();
    while (lastMonsterIndex != monsterIndex && i >= 0)
    {
        QLayoutItem *cItem = ui->monstersLayout->itemAt(i);
        QWidget *cWidget = cItem->widget();
        QToolButton *cButton = dynamic_cast<QToolButton *>(cWidget);

        QString temp = cButton->text();
        cButton->setText(QString::number(lastMonsterIndex));
        cButton->setIcon(profile->getMonster(lastMonsterIndex)->getImage());
        lastMonsterIndex = temp.toInt();
        i--;
    }

    button->close();
    ui->monstersLayout->removeWidget(widget);
}

int TeamWidget::getTeamIndex() const
{
    return teamIndex;
}

void TeamWidget::setTeamIndex(int value)
{
    teamIndex = value;
}

void TeamWidget::on_teamButton_released()
{
    TeamDisplay *disp = new TeamDisplay(profile, battleName, teamIndex, this);
    disp->show();
}
