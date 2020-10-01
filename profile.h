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

    int getTeamsCount(QString battleName);

    Monster* getMonster(int index);

private:
    void deleteMonster(int index);

    QVector<Team *> getTeamsFiltered(QString battleName);

    void deleteTeam(QString battleName, int indexFilteredByTeam);

public slots:
    void onMonsterDeleteReleased(int index);
    void onTeamDeleteReleased(QString battleName, int indexFilteredByTeam);

private slots:
    void onImport(QNetworkReply *reply);
    void onMonsterUpdated(int index);

signals:
    void monsterAdded();
    void monsterDeleted(int index);
    void monsterUpdated(int index);
    void teamAdded(QString battle);
    void teamDeleted(QString battle);

private:
    QVector<Monster *> monsters_m;
    QVector<Team *> teams_m;
};

#endif // PROFILE_H
