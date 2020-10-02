#ifndef PROFILE_H
#define PROFILE_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QPixmap>
#include <QFile>

#include "monster.h"
#include "team.h"

class Profile : public QObject
{
    Q_OBJECT
public:
    Profile();

    void importFromSFProfile(QString profileName);

    QJsonDocument getJsonProfile();

    void loadProfile(QJsonDocument &doc);

    void clear();

    void addMonster(Monster *mon);

    void addTeam(Team *team);

    int getMonsterCount();

    int getMonsterCount(QString battleName, int indexFiltered);

    int getTeamsCount(QString battleName);

    Monster* getMonster(int index);

    Team* getTeam(QString battleName, int indexFiltered);

    bool teamExists(QString battleName, int indexFiltered);

    bool existsInTeam(QString battleName, int indexFiltered, int monsterIndex);

    QVector<int> getMonsterIndexes(QString battleName, int indexFiltered);

private:
    void deleteMonster(int index);

    QVector<Team *> getTeamsFiltered(QString battleName);

    void deleteTeam(QString battleName, int indexFilteredByTeam);

public slots:
    void onMonsterDeleteReleased(int index);
    void onMonsterAddReleased(QString battleName, int indexFiltered, int monsterIndex);
    void onMonsterRemoveReleased(QString battleName, int indexFiltered, int monsterIndex);
    void onTeamDeleteReleased(QString battleName, int indexFilteredByTeam);

private slots:
    void onImport(QNetworkReply *reply);
    void onMonsterUpdated(int index);

signals:
    void monsterAdded();
    void monsterDeleted(int index);
    void monsterUpdated(int index);
    void teamAdded(QString battle);
    void teamDeleted(int indexFiltered, QString battle);
    void monsterAddedToTeam(QString battle, int indexFiltered, int monsterIndex);
    void monsterRemovedFromTeam(QString battle, int indexFiltered, int monsterIndex);

private:
    QVector<Monster *> monsters_m;
    QVector<Team *> teams_m;
};

#endif // PROFILE_H
