#ifndef MONSTERDISPLAY_H
#define MONSTERDISPLAY_H

#include <QDialog>

#include "monster.h"
#include "profile.h"

namespace Ui {
class MonsterDisplay;
}

class MonsterDisplay : public QDialog
{
    Q_OBJECT

public:
    enum Task
    {
        DELETE,
        ADD,
    };
    explicit MonsterDisplay(Profile *pr, Monster *monster, Task t, QWidget *parent = nullptr);
    ~MonsterDisplay();

private slots:
    void onDeleteReleased();

    void on_editButton_released();

signals:
    void deleteReleased(int index);

private:
    Ui::MonsterDisplay *ui;

    Profile *profile;
    Monster *monster;

    Task task;
};

#endif // MONSTERDISPLAY_H
