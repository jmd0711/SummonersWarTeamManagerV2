#ifndef TEAMLISTVIEW_H
#define TEAMLISTVIEW_H

#include <QWidget>

namespace Ui {
class TeamListView;
}

class TeamListView : public QWidget
{
    Q_OBJECT

public:
    explicit TeamListView(QWidget *parent = nullptr);
    ~TeamListView();

private:
    Ui::TeamListView *ui;
};

#endif // TEAMLISTVIEW_H
