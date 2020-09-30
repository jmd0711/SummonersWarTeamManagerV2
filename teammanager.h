#ifndef TEAMMANAGER_H
#define TEAMMANAGER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class TeamManager; }
QT_END_NAMESPACE

class TeamManager : public QMainWindow
{
    Q_OBJECT

public:
    TeamManager(QWidget *parent = nullptr);
    ~TeamManager();

private:
    Ui::TeamManager *ui;
};
#endif // TEAMMANAGER_H
