#include "monster.h"

Monster::Monster(const QJsonObject &newMonster, Source src)
{
    switch (src)
    {
    case Source::IMPORT:
        id_m = newMonster["monster"].toInt();

        requestData();

        description_m = "";
        priority_m = 0;
        stars_m = newMonster["stars"].toInt();
        level_m = newMonster["level"].toInt();
        hp_m = newMonster["base_hp"].toInt() + newMonster["rune_hp"].toInt();
        attack_m = newMonster["base_attack"].toInt() + newMonster["rune_attack"].toInt();
        defense_m = newMonster["base_defense"].toInt() + newMonster["rune_defense"].toInt();
        speed_m = newMonster["base_speed"].toInt() + newMonster["rune_speed"].toInt();
        critRate_m = newMonster["base_crit_rate"].toInt() + newMonster["rune_crit_rate"].toInt();
        critDamage_m = newMonster["base_crit_damage"].toInt() + newMonster["rune_crit_damage"].toInt();
        resistance_m = newMonster["base_resistance"].toInt() + newMonster["rune_resistance"].toInt();
        accuracy_m = newMonster["base_accuracy"].toInt() + newMonster["rune_accuracy"].toInt();
        break;
    case Source::PROFILE:
        name_m = newMonster["name"].toString();
        imagePath_m = newMonster["imagePath"].toString();

        requestImage();
        element_m = newMonster["element"].toString();
        description_m = newMonster["description"].toString();
        awakened_m = newMonster["awakened"].toBool();
        id_m = newMonster["id"].toInt();
        stars_m = newMonster["stars"].toInt();
        level_m = newMonster["level"].toInt();
        hp_m = newMonster["hp"].toInt();
        attack_m = newMonster["attack"].toInt();
        defense_m = newMonster["defense"].toInt();
        speed_m = newMonster["speed"].toInt();
        critRate_m = newMonster["criticalRate"].toInt();
        critDamage_m = newMonster["criticalDamage"].toInt();
        resistance_m = newMonster["resistance"].toInt();
        accuracy_m = newMonster["accuracy"].toInt();
        priority_m = newMonster["priority"].toInt();
        break;
    }
}

QString Monster::getName() const
{
    return name_m;
}

QString Monster::getImagePath() const
{
    return imagePath_m;
}

QString Monster::getElement() const
{
    return element_m;
}

QString Monster::getDescription() const
{
    return description_m;
}

void Monster::setDescription(const QString &value)
{
    description_m = value;
}

bool Monster::isAwakened() const
{
    return awakened_m;
}

int Monster::getId() const
{
    return id_m;
}

int Monster::getStars() const
{
    return stars_m;
}

void Monster::setStars(int value)
{
    stars_m = value;
}

int Monster::getLevel() const
{
    return level_m;
}

void Monster::setLevel(int value)
{
    level_m = value;
}

int Monster::getHp() const
{
    return hp_m;
}

void Monster::setHp(int value)
{
    hp_m = value;
}

int Monster::getAttack() const
{
    return attack_m;
}

void Monster::setAttack(int value)
{
    attack_m = value;
}

int Monster::getDefense() const
{
    return defense_m;
}

void Monster::setDefense(int value)
{
    defense_m = value;
}

int Monster::getSpeed() const
{
    return speed_m;
}

void Monster::setSpeed(int value)
{
    speed_m = value;
}

int Monster::getCritRate() const
{
    return critRate_m;
}

void Monster::setCritRate(int value)
{
    critRate_m = value;
}

int Monster::getCritDamage() const
{
    return critDamage_m;
}

void Monster::setCritDamage(int value)
{
    critDamage_m = value;
}

int Monster::getResistance() const
{
    return resistance_m;
}

void Monster::setResistance(int value)
{
    resistance_m = value;
}

int Monster::getAccuracy() const
{
    return accuracy_m;
}

void Monster::setAccuracy(int value)
{
    accuracy_m = value;
}

int Monster::getPriority() const
{
    return priority_m;
}

void Monster::setPriority(int value)
{
    priority_m = value;
}

int Monster::getIndex() const
{
    return index_m;
}

void Monster::setIndex(int value)
{
    index_m = value;
}

void Monster::requestData()
{
    QNetworkRequest request;
    QNetworkAccessManager *networkManager = new QNetworkAccessManager();
    QUrl url = QUrl("https://swarfarm.com/api/v2/monsters/");
    url.setPath(QString("%1%2/").arg(url.path()).arg(id_m));
    request.setUrl(url);
    connect(networkManager, &QNetworkAccessManager::finished, this, &Monster::onDataReceived);
    networkManager->get(request);
}

void Monster::requestImage()
{
    QNetworkRequest request;
    QNetworkAccessManager *networkManager = new QNetworkAccessManager();
    QUrl url = QUrl(QString("https://swarfarm.com/static/herders/images/monsters/"));
    url.setPath(QString("%1%2").arg(url.path()).arg(imagePath_m));
    request.setUrl(url);
    connect(networkManager, &QNetworkAccessManager::finished, this, &Monster::onImageReceived);
    networkManager->get(request);
}

void Monster::onDataReceived(QNetworkReply *reply)
{
    QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
    QJsonObject monData = doc.object();

    name_m = monData["name"].toString();
    imagePath_m = monData["image_filename"].toString();
    element_m = monData["element"].toString();
    awakened_m = monData["awaken_level"].toInt();
    reply->close();

    requestImage();
}

void Monster::onImageReceived(QNetworkReply *reply)
{
    QByteArray bytes = reply->readAll();
    image_m.loadFromData(bytes);
    emit updated(index_m);
}

QPixmap Monster::getImage() const
{
    return image_m;
}
