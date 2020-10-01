#ifndef TEAMWIDGET_H
#define TEAMWIDGET_H

#include <QWidget>

#include "profile.h"
#include "team.h"

namespace Ui {
class TeamWidget;
}

class TeamWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TeamWidget(Profile *pr, QString battle, int index, QWidget *parent = nullptr);
    ~TeamWidget();

private slots:
    void on_deleteButton_released();

signals:
    void deleteReleased(QString battle, int indexFilteredByTeam);

private:
    Ui::TeamWidget *ui;

    Profile *profile;
    QString battleName;
    int teamIndex;
};

#endif // TEAMWIDGET_H
