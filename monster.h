#ifndef MONSTER_H
#define MONSTER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QPixmap>
#include <QFile>

class Monster : public QObject
{
    Q_OBJECT
public:
    enum Source
    {
        IMPORT,
        PROFILE,
    };
    Monster(const QJsonObject &newMonster, Source src);

    QString getName() const;

    QString getImagePath() const;

    QString getElement() const;

    QString getDescription() const;
    void setDescription(const QString &value);

    bool isAwakened() const;

    int getId() const;

    int getStars() const;
    void setStars(int value);

    int getLevel() const;
    void setLevel(int value);

    int getHp() const;
    void setHp(int value);

    int getAttack() const;
    void setAttack(int value);

    int getDefense() const;
    void setDefense(int value);

    int getSpeed() const;
    void setSpeed(int value);

    int getCritRate() const;
    void setCritRate(int value);

    int getCritDamage() const;
    void setCritDamage(int value);

    int getResistance() const;
    void setResistance(int value);

    int getAccuracy() const;
    void setAccuracy(int value);

    int getPriority() const;
    void setPriority(int value);

    int getIndex() const;
    void setIndex(int value);

    QPixmap getImage() const;

private:
    void requestData();

    void requestImage();

private slots:
    void onDataReceived(QNetworkReply *reply);

    void onImageReceived(QNetworkReply *reply);

signals:
    void updated(int index);

private:
    QString name_m;
    QString imagePath_m;
    QString element_m;
    QString description_m;
    bool awakened_m;
    int id_m;
    int stars_m;
    int level_m;
    int hp_m;
    int attack_m;
    int defense_m;
    int speed_m;
    int critRate_m;
    int critDamage_m;
    int resistance_m;
    int accuracy_m;
    int priority_m;

    int index_m;
    QPixmap image_m;
};

#endif // MONSTER_H
