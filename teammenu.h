#ifndef TEAMMENU_H
#define TEAMMENU_H

#include <QWidget>

namespace Ui {
class TeamMenu;
}

class TeamMenu : public QWidget
{
    Q_OBJECT

public:
    explicit TeamMenu(QString name, QWidget *parent = nullptr);
    ~TeamMenu();

private:
    Ui::TeamMenu *ui;
};

#endif // TEAMMENU_H
