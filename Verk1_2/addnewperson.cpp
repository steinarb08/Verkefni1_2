#include "addnewperson.h"
#include "ui_addnewperson.h"

addNewPerson::addNewPerson(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addNewPerson)
{
    ui->setupUi(this);
}

addNewPerson::~addNewPerson()
{
    delete ui;
}
