#include "teamlistview.h"
#include "ui_teamlistview.h"

TeamListView::TeamListView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TeamListView)
{
    ui->setupUi(this);
}

TeamListView::~TeamListView()
{
    delete ui;
}
