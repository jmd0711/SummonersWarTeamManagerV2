#include "team.h"

Team::Team(const QJsonObject &newTeam)
{
    battle_m = newTeam["battle"].toString();
    teamName_m = newTeam["name"].toString();
    teamDescription_m = newTeam["description"].toString();

    QJsonArray indexes = newTeam["indexes"].toArray();
    foreach (const QJsonValue &value, indexes)
    {
        monsterIndexes_m.push_back(value.toInt());
    }
}

Team::Team(QString battleName) :
    battle_m{ battleName }
{
    teamName_m = "New Team";
    teamDescription_m = "";
}

QString Team::getBattle() const
{
    return battle_m;
}

QString Team::getTeamName() const
{
    return teamName_m;
}

void Team::setTeamName(const QString &value)
{
    teamName_m = value;
}

QString Team::getTeamDescription() const
{
    return teamDescription_m;
}

void Team::setTeamDescription(const QString &value)
{
    teamDescription_m = value;
}

void Team::addIndex(int monsterIndex)
{
    monsterIndexes_m.push_back(monsterIndex);
}

void Team::removeIndex(int monsterIndex)
{
    monsterIndexes_m.erase(std::remove(monsterIndexes_m.begin(), monsterIndexes_m.end(), monsterIndex), monsterIndexes_m.end());
}

bool Team::exists(int monsterIndex)
{
    return (std::find(monsterIndexes_m.begin(), monsterIndexes_m.end(), monsterIndex) != monsterIndexes_m.end());
}

QVector<int> Team::getMonsterIndexes() const
{
    return monsterIndexes_m;
}
