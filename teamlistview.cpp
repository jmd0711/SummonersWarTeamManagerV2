#include "teamlistview.h"
#include "ui_teamlistview.h"

TeamListView::TeamListView(Profile *pr, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TeamListView),
    profile{ pr }
{
    ui->setupUi(this);

    layout = new QVBoxLayout();
    this->setLayout(layout);
}

TeamListView::~TeamListView()
{
    delete ui;
}
