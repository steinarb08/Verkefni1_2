#include "editcomputer.h"
#include "ui_editcomputer.h"

EditComputer::EditComputer(QWidget *parent,DomainLayer &dom, Computer &com) :
    QMainWindow(parent),
    ui(new Ui::EditComputer)
{
    ui->setupUi(this);
    d1 = dom;
    c1 = com;
    ui->lineEditName->setText(QString::fromStdString(c1.getName()));
    ui->lineEditBuiltYear->setText(QString::number(c1.getBuiltYear()));
    ui->lineEditType->setText(QString::fromStdString(c1.getType()));

}

EditComputer::~EditComputer()
{
    delete ui;
}

void EditComputer::on_btnCancelEditC_clicked()
{
    this->close();
}
