#include "protree.h"
#include "ui_protree.h"

ProTree::ProTree(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProTree)
{
    ui->setupUi(this);
    this->setMinimumWidth(300);
    this->setMaximumWidth(300);

}

ProTree::~ProTree()
{
    delete ui;
}

QTreeWidget *ProTree::GetTreeWidget()
{
    return ui->treeWidget;
}

void ProTree::AddProTree(const QString name, const QString path)
{
    ui->treeWidget->AddProTree(name, path);
}
