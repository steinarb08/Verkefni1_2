#include "editcomputer.h"
#include "ui_editcomputer.h"

EditComputer::EditComputer(QWidget *parent,DomainLayer &dom, Computer com) :
    QMainWindow(parent),
    ui(new Ui::EditComputer)
{
    ui->setupUi(this);
    d1 = dom;
    c1 = com;
}

EditComputer::~EditComputer()
{
    delete ui;
}

void EditComputer::on_btnCancelEditC_clicked()
{
    this->close();
}
