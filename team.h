#ifndef TEAM_H
#define TEAM_H

#include <QObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

class Team : public QObject
{
    Q_OBJECT
public:
    Team(const QJsonObject &newTeam);
    Team(QString battleName);

    QString getBattle() const;

    QString getTeamName() const;
    void setTeamName(const QString &value);

    QString getTeamDescription() const;
    void setTeamDescription(const QString &value);

    void addIndex(int monsterIndex);

    void removeIndex(int monsterIndex);

private:
    QString battle_m;
    QString teamName_m;
    QString teamDescription_m;
    QVector<int> monsterIndexes;
};

#endif // TEAM_H
