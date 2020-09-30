#ifndef TEAMLISTVIEW_H
#define TEAMLISTVIEW_H

#include <QWidget>
#include <QVBoxLayout>

#include "profile.h"

namespace Ui {
class TeamListView;
}

class TeamListView : public QWidget
{
    Q_OBJECT

public:
    explicit TeamListView(Profile *pr, QWidget *parent = nullptr);
    ~TeamListView();

private:
    Ui::TeamListView *ui;

    Profile *profile;

    QVBoxLayout *layout;
};

#endif // TEAMLISTVIEW_H
