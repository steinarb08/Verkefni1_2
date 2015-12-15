#include "editperson.h"
#include "ui_editperson.h"
#include <QMessageBox>

editPerson::editPerson(QWidget *parent, DomainLayer &dom, Person &per,PersonScreen *perScreen):
    QDialog(parent),
    ui(new Ui::editPerson)
{
    ui->setupUi(this);
    d1 = dom;
    p1 = per;
    ps1 = perScreen;


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
//Cancel button.
void editPerson::on_btnCancelEdit_clicked()
{
    this->close();
}
//Saves edited scientists. Error checkers.
void editPerson::on_btnSaveEdit_clicked()
{
    string name = ui->textEditNewName->toPlainText().toStdString();
    int deathYear = ui->textEditDeathYear->toPlainText().toInt();
    int birthYear = ui->textEditBirthYear->toPlainText().toInt();
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
        if(ui->checkBoxMale->isChecked())
        {
            gender = "Male";
        }
        else if(ui->checkBoxFemale->isChecked())
        {
            gender = "Female";
        }
        else if (!(ui->checkBoxFemale->isChecked()) && !(ui->checkBoxMale->isChecked()))
        {
            ui->labelError->setText("<span style='color: red'>Boxes for gender are empty</span>");
            success = false;
        }
    }
    if(success)
    {
        int answer = QMessageBox::question(this, "Confirm", "Are you sure?");
        if(answer == QMessageBox::No)
        {
            return;
        }
        p1.setName(name);
        p1.setGender(gender);
        p1.setBirthYear(birthYear);
        p1.setDeathYear(deathYear);
        d1.updatePerson(p1);
        ps1->updateValues();
        this->close();
    }
}
//If one box is checked, you cant check the other one.
void editPerson::on_checkBoxMale_clicked()
{
    ui->checkBoxMale->setChecked(true);
    ui->checkBoxFemale->setChecked(false);
}
//If one box is checked, you cant check the other one.
void editPerson::on_checkBoxFemale_clicked()
{
    ui->checkBoxFemale->setChecked(true);
    ui->checkBoxMale->setChecked(false);
}

