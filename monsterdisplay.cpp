#include "monsterdisplay.h"
#include "ui_monsterdisplay.h"

MonsterDisplay::MonsterDisplay(Profile *pr, Monster *mon, Task t, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MonsterDisplay),
    profile{ pr },
    monster{ mon },
    task{ t }

{
    ui->setupUi(this);

    setAttribute(Qt::WA_DeleteOnClose);

    ui->imageLabel->setPixmap(monster->getImage());

    ui->nameLabel->setText(monster->getName());
    //TODO Stars & Awakened

    ui->prioritySpinBox->setValue(monster->getPriority());
    ui->levelSpinBox->setValue(monster->getLevel());
    ui->hpSpinBox->setValue(monster->getHp());
    ui->defenseSpinBox->setValue(monster->getDefense());
    ui->attackSpinBox->setValue(monster->getAttack());
    ui->speedSpinBox->setValue(monster->getSpeed());
    ui->critRateSpinBox->setValue(monster->getCritRate());
    ui->critDamageSpinBox->setValue(monster->getCritDamage());
    ui->accuracySpinBox->setValue(monster->getAccuracy());
    ui->resistanceSpinBox->setValue(monster->getResistance());
    ui->descriptionEdit->setText(monster->getDescription());

    switch (task)
    {
    case MonsterDisplay::DELETE:
        ui->doButton->setText("Delete");
        connect(ui->doButton, &QPushButton::released, this, &MonsterDisplay::onDeleteReleased);
        break;
    case MonsterDisplay::ADD:
        ui->doButton->setText("Add");
        break;
    }
}

MonsterDisplay::~MonsterDisplay()
{
    delete ui;
}

void MonsterDisplay::onDeleteReleased()
{
    emit deleteReleased(monster->getIndex());
    close();
}

void MonsterDisplay::on_editButton_released()
{
    monster->setPriority(ui->prioritySpinBox->value());
    monster->setLevel(ui->levelSpinBox->value());
    monster->setHp(ui->hpSpinBox->value());
    monster->setDefense(ui->defenseSpinBox->value());
    monster->setAttack(ui->attackSpinBox->value());
    monster->setSpeed(ui->speedSpinBox->value());
    monster->setCritRate(ui->critRateSpinBox->value());
    monster->setCritDamage(ui->critDamageSpinBox->value());
    monster->setAccuracy(ui->accuracySpinBox->value());
    monster->setResistance(ui->resistanceSpinBox->value());
    monster->setDescription(ui->descriptionEdit->toPlainText());
}
