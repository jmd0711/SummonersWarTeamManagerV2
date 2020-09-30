#include "profile.h"

Profile::Profile()
{
}

void Profile::importFromSFProfile(QString profileName)
{
    QNetworkAccessManager *networkManager;
    QNetworkRequest request;
    networkManager = new QNetworkAccessManager(this);
    connect(networkManager, &QNetworkAccessManager::finished, this, &Profile::onImport);
    QUrl url = QUrl("https://swarfarm.com/api/v2/profiles/");
    url.setPath(QString("%1%2/monsters/").arg(url.path()).arg(profileName));
    request.setUrl(url);
    networkManager->get(request);
}

QJsonDocument Profile::getJsonProfile()
{
    QJsonObject saveObject;

    QJsonArray monstersJsonArray;
    foreach (Monster* mon, monsters_m)
    {
        QJsonObject monsterJson;
        monsterJson.insert("name", mon->getName());
        monsterJson.insert("imagePath", mon->getImagePath());
        monsterJson.insert("element", mon->getElement());
        monsterJson.insert("awakened", mon->isAwakened());
        monsterJson.insert("description", mon->getDescription());
        monsterJson.insert("id", mon->getId());
        monsterJson.insert("stars", mon->getStars());
        monsterJson.insert("level", mon->getLevel());
        monsterJson.insert("hp", mon->getHp());
        monsterJson.insert("attack", mon->getAttack());
        monsterJson.insert("defense", mon->getDefense());
        monsterJson.insert("speed", mon->getSpeed());
        monsterJson.insert("criticalRate", mon->getCritRate());
        monsterJson.insert("criticalDamage", mon->getCritDamage());
        monsterJson.insert("accuracy", mon->getAccuracy());
        monsterJson.insert("resistance", mon->getResistance());
        monsterJson.insert("priority", mon->getPriority());
        monstersJsonArray.push_back(monsterJson);
    }
    saveObject.insert("monsters", monstersJsonArray);

    //  TODO TEAMS
    QJsonDocument doc(saveObject);
    return doc;
}

void Profile::loadProfile(QJsonDocument &doc)
{
    QJsonObject obj = doc.object();
    QJsonArray monArray = obj["monsters"].toArray();
    foreach (const QJsonValue &value, monArray)
    {
        Monster *mon = new Monster(value.toObject(), Monster::PROFILE);
        addMonster(mon);
    }
    //  TODO TEAMS

    QJsonArray teamsArray = obj["teams"].toArray();
    foreach (const QJsonValue &value, teamsArray)
    {
        Team *team = new Team(value.toObject());
        addTeam(team);
    }
}

void Profile::clear()
{
    while (monsters_m.count() > 0)
    {
        delete monsters_m[0];
        monsters_m.pop_front();
    }

    while (teams_m.count() > 0)
    {
        delete teams_m[0];
        teams_m.pop_front();
    }
}

void Profile::addMonster(Monster *mon)
{
    int currentIndex = monsters_m.size();
    monsters_m.push_back(mon);
    mon->setIndex(currentIndex);

    connect(mon, &Monster::updated, this, &Profile::onMonsterUpdated);
    //connect(mon, &Monster::monsterDeleted, this, &MonsterData::onMonsterDeleted);
    emit monsterAdded();
}

void Profile::addTeam(Team *team)
{
    teams_m.push_back(team);
    emit teamAdded(team->getBattle());
}

int Profile::getMonsterCount()
{
    return monsters_m.count();
}

const Monster* Profile::getMonster(int index) const
{
    return monsters_m[index];
}

void Profile::onImport(QNetworkReply *reply)
{
    // ADD Error Check Here
    QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
    QJsonObject obj = doc.object();
    QJsonArray array = obj["results"].toArray();

    foreach (const QJsonValue &value, array)
    {
        Monster *mon = new Monster(value.toObject(), Monster::IMPORT);
        addMonster(mon);
    }
    reply->close();
}

void Profile::onMonsterUpdated(int index)
{
    emit monsterUpdated(index);
}
