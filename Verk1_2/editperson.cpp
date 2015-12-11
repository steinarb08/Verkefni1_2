#include "editperson.h"
#include "ui_editperson.h"

editPerson::editPerson(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editPerson)
{
    ui->setupUi(this);
}

editPerson::~editPerson()
{
    delete ui;
}
//Þarf að laga.
void editPerson::on_lineEditNewName_textChanged(const QString &arg1)
{
    ui->lineEditNewName->setText("etsdf");
}
