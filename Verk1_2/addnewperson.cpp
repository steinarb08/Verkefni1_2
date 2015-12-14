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


void addNewPerson::on_Button_Cancel_NewScientist_clicked()
{
    this->close();

}

void addNewPerson::on_checkBox_male_clicked()
{
    ui->checkBox_male->setChecked(true);
    ui->checkBox_female->setChecked(false);
}


void addNewPerson::on_checkBox_female_clicked()
{
    ui->checkBox_female->setChecked(true);
    ui->checkBox_male->setChecked(false);
}

void addNewPerson::on_Button_ADD_NewScientist_clicked()
{
   string name = ui->textEdit_New_name->toPlainText().toStdString();
   name = d1.fixName(name);
   int birthYear = ui->textEdit_New_Byear->toPlainText().toInt();
   int deathYear = ui->textEdit_new_Dyear->toPlainText().toInt();
   string gender = "";
   if(ui->checkBox_male->isChecked())
   {
       gender = "Male" ;
   }
   else if (ui->checkBox_female->isChecked())
   {
       gender = "Female";
   }
   else
   {

   }
   Person p1(name, gender, birthYear, deathYear);
   d1.addPersonToDB(p1);

   this->close();
}


