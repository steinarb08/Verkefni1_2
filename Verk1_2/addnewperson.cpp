#include "addnewperson.h"
#include "ui_addnewperson.h"
#include "QMessageBox"

// Default constructor for add new Person
addNewPerson::addNewPerson(QWidget *parent, DomainLayer &dom, PersonScreen *perScreen) :
    QDialog(parent),
    ui(new Ui::addNewPerson)
{
    ui->setupUi(this);
    d1 = dom;
    ps1 = perScreen;
}

addNewPerson::~addNewPerson()
{
    delete ui;
}


void addNewPerson::on_Button_Cancel_NewScientist_clicked()
{
    this->close();
}

// Only one box is allowed to be checked
void addNewPerson::on_checkBox_male_clicked()
{
    ui->checkBox_male->setChecked(true);
    ui->checkBox_female->setChecked(false);
}

// Only one box is allowed to be checked
void addNewPerson::on_checkBox_female_clicked()
{
    ui->checkBox_female->setChecked(true);
    ui->checkBox_male->setChecked(false);
}

// Adds scientist to data base.
void addNewPerson::on_Button_ADD_NewScientist_clicked()
{
    string name = ui->textEdit_New_name->toPlainText().toStdString();
    name = d1.fixName(name);
    int birthYear = ui->textEdit_New_Byear->toPlainText().toInt();
    int deathYear = ui->textEdit_new_Dyear->toPlainText().toInt();
    string gender = "";
    bool success = true;

    if(name.empty())
    {
        ui->labelError->setText("<span style='color: red'>Empty name</span>");
        success = false;
    }
    else if (birthYear == 0)
    {
        ui->labelError->setText("<span style='color: red'>Empty Birthyear</span>");
        success = false;
    }
    else if (birthYear > 2016)
    {
        ui->labelError->setText("<span style='color: red'>Invalid year of birth</span>");
        success = false;
    }
    else if (deathYear == 0)
    {
        ui->labelError->setText("<span style='color: red'>Deathyear empty</span>");
        success = false;
    }
    else if (birthYear > deathYear && !(deathYear == -1))
    {
        ui->labelError->setText("<span style='color: red'>Invalid year of death</span>");
        success = false;
    }
    else
    {
        if(ui->checkBox_male->isChecked())
        {
            gender = "Male" ;
        }
        else if (ui->checkBox_female->isChecked())
        {
            gender = "Female";
        }
        else if (!(ui->checkBox_female->isChecked()) && !(ui->checkBox_male->isChecked()))
        {   // If neither boxes are checked.
            ui->labelError->setText("<span style='color: red'>Boxes for gender are empty</span>");
            success = false;
        }

        // if there is no error, then add scientist
        if(success)
        {
            int answer = QMessageBox::question(this, "Confirm", "Are you sure?");
            if(answer == QMessageBox::No)
            {
                return;
            }

            Person p1(name, gender, birthYear, deathYear);
            d1.addPersonToDB(p1);
            ps1->updateValues();
            this->close();
        }
    }
}

