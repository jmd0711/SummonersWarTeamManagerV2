#include "team.h"

Team::Team(const QJsonObject &newTeam)
{
    battle_m = newTeam["battle"].toString();
    teamName_m = newTeam["name"].toString();
    teamDescription_m = newTeam["description"].toString();

    QJsonArray indexes = newTeam["indexes"].toArray();
    foreach (const QJsonValue &value, indexes)
    {
        monsterIndexes.push_back(value.toInt());
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
    monsterIndexes.push_back(monsterIndex);
}

void Team::removeIndex(int monsterIndex)
{
    monsterIndexes.erase(std::remove(monsterIndexes.begin(), monsterIndexes.end(), monsterIndex), monsterIndexes.end());
}
