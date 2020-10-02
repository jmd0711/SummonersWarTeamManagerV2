#ifndef TEAMWIDGET_H
#define TEAMWIDGET_H

#include <QWidget>

#include "profile.h"
#include "team.h"
#include "monsterrequest.h"
#include "monsterdisplay.h"
#include "teamdisplay.h"

namespace Ui {
class TeamWidget;
}

class TeamWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TeamWidget(Profile *pr, QString battle, int index, int initialCount = 0, QWidget *parent = nullptr);
    ~TeamWidget();

    int getTeamIndex() const;
    void setTeamIndex(int value);

    QString getBattleName() const;

    void setMonsterCount(int value);

private:
    void removeMonster(int monsterIndex);

private slots:
    void on_deleteButton_released();

    void on_addMonsterButton_released();

    void onMonsterAddedToTeam(QString battle, int indexFiltered, int monsterIndex);

    void onMonsterRemovedFromTeam(QString battle, int indexFiltered, int monsterIndex);

    void onMonsterButtonReleased();

    void onMonsterDeleted(int monsterIndex);

    void onMonsterUpdated(int monsterIndex);

    void on_teamButton_released();

signals:
    void deleteReleased(QString battle, int indexFilteredByTeam);

private:
    Ui::TeamWidget *ui;

    Profile *profile;
    QString battleName;
    int teamIndex;
    int monsterCount;
};

#endif // TEAMWIDGET_H
