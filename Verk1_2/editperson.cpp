#include "editperson.h"
#include "ui_editperson.h"

editPerson::editPerson(QWidget *parent, DomainLayer &dom, Person &per):
    QDialog(parent),
    ui(new Ui::editPerson)
{
    ui->setupUi(this);
    d1 = dom;
    p1 = per;


    ui->textEditNewName->setText(QString::fromStdString(p1.getName()));
    ui->textEditBirthYear->setText(QString::number(p1.getBirthYear()));
    ui->textEditDeathYear->setText(QString::number(p1.getDeathYear()));
    if(p1.getGender() == "Male")
    {
        ui->checkBoxMale->setChecked(true);
    }
    else
    {
        ui->checkBoxFemale->setChecked(true);
    }
}

editPerson::~editPerson()
{
    delete ui;
}

void editPerson::on_lineEditNewName_textChanged(const QString &arg1)
{

}

void editPerson::on_btnCancelEdit_clicked()
{
    this->close();
}

void editPerson::on_btnSaveEdit_clicked()
{
    string name = ui->textEditNewName->toPlainText().toStdString();
    int deathYear = ui->textEditDeathYear->toPlainText().toInt();
    int birthYear = ui->textEditBirthYear->toPlainText().toInt();
    string gender = "";

    if(ui->checkBoxMale->isChecked())
    {
        gender = "Male";
    }
    else if(ui->checkBoxFemale->isChecked())
    {
        gender = "Female";
    }
    else
    {
        //Some error message!
    }

    //personList.at(i).setName(name);

    //d1.updateDbPerson(personList.at(i));

}
/*
void editPerson::on_checkBoxMale_clicked()
{
    ui->checkBoxMale->isChecked(true);
    ui->checkBoxFemale->isChecked(false);
}

void editPerson::on_checkBoxFemale_clicked()
{
    ui->checkBoxFemale->isChecked(true);
    ui->checkBoxMale->isChecked(false);
}
*/
