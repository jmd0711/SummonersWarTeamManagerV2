#ifndef TEAMDISPLAY_H
#define TEAMDISPLAY_H

#include <QDialog>

#include "profile.h"

namespace Ui {
class TeamDisplay;
}

class TeamDisplay : public QDialog
{
    Q_OBJECT

public:
    explicit TeamDisplay(Profile *pr, QString battleName, int indexFiltered, QWidget *parent = nullptr);
    ~TeamDisplay();

private slots:
    void on_pushButton_released();

private:
    Ui::TeamDisplay *ui;

    Profile *profile;
    Team *team;
};

#endif // TEAMDISPLAY_H
