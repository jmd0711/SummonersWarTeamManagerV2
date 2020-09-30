#ifndef MONSTERLISTVIEW_H
#define MONSTERLISTVIEW_H

#include <QWidget>
#include <QGridLayout>
#include <QToolButton>

#include "profile.h"

namespace Ui {
class MonsterListView;
}

class MonsterListView : public QWidget
{
    Q_OBJECT

public:
    enum Purpose
    {
        BOX,
        REQUEST,
    };

    explicit MonsterListView(Profile *pr, Purpose pu, QWidget *parent = nullptr);
    ~MonsterListView();

public slots:


private:
    void addButton();

    void deleteButton();

    void updateButton(int index);

private slots:
    void onMonsterAdded();

    void onMonsterDeleted(int index);

    void onMonsterUpdated(int index);

private:
    Ui::MonsterListView *ui;

    QGridLayout *layout;

    Profile *profile;

    Purpose purpose;

    int maxColumns = 10;
    int buttonCount = 0;
};

#endif // MONSTERLISTVIEW_H
