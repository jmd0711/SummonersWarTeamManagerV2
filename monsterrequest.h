#ifndef MONSTERREQUEST_H
#define MONSTERREQUEST_H

#include <QDialog>
#include <QDesktopWidget>

#include "profile.h"
#include "monsterlistview.h"

namespace Ui {
class MonsterRequest;
}

class MonsterRequest : public QDialog
{
    Q_OBJECT

public:
    explicit MonsterRequest(Profile *pr, QString battle, int indexFiltered, QWidget *parent = nullptr);
    ~MonsterRequest();

private:
    Ui::MonsterRequest *ui;

    Profile *profile;

    MonsterListView *monsterListWidget;

    QString battleName;
    int teamIndex;
};

#endif // MONSTERREQUEST_H
