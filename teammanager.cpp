#include "teammanager.h"
#include "ui_teammanager.h"

TeamManager::TeamManager(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TeamManager)
{
    ui->setupUi(this);
}

TeamManager::~TeamManager()
{
    delete ui;
}

