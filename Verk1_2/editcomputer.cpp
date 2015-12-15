#include "editcomputer.h"
#include "ui_editcomputer.h"
#include <QMessageBox>

// Default constructor. Selected computer appears in edit label boxes.
EditComputer::EditComputer(QWidget *parent,DomainLayer &dom, Computer &com, ComputerScreen *cpuScreen) :
    QMainWindow(parent),
    ui(new Ui::EditComputer)
{
    ui->setupUi(this);
    d1 = dom;
    c1 = com;
    cs1 = cpuScreen;

    ui->textEdit_Name->setText(QString::fromStdString(c1.getName()));
    ui->textEdit_BuiltYear->setText(QString::number(c1.getBuiltYear()));
    ui->textEdit_Type->setText(QString::fromStdString(c1.getType()));
    if(c1.getBuiltComputer() == "Yes")
    {
        ui->checkYes->setChecked(true);
    }
    else
    {
        ui->checkNo->setChecked(true);
    }
}

EditComputer::~EditComputer()
{
    delete ui;
}

// Function for cancel button to close the window
void EditComputer::on_btnCancelEditC_clicked()
{
    this->close();
}

// Saves edited computer. Error checks.
void EditComputer::on_btnSaveEditC_clicked()
{
    string name = ui->textEdit_Name->toPlainText().toStdString();
    string type = ui->textEdit_Type->toPlainText().toStdString();
    int buildYear = ui->textEdit_BuiltYear->toPlainText().toInt();
    string built = "";
    bool success = true;

    if(ui->checkYes->isChecked())
    {
        built = "Yes";
    }
    else
    {
        ui->checkNo->setChecked(true);
    }

    if(name.empty())
    {
        ui->errorLabelC->setText("<span style = 'color: red'>Empty Name!</span>");
        success = false;
    }
    else if(buildYear < 0)
    {
        ui->errorLabelC->setText("<span style = 'color: red'> Invalid Build Year!</span>");
        success = false;
    }
    else if(type.empty())
    {
        ui->errorLabelC->setText("<span style = 'color: red'> Empty Type!</span>");
        success = false;
    }
    else
    {
        if(ui->checkYes->isChecked())
        {
            built = "Yes" ;
        }
        else if (ui->checkNo->isChecked())
        {
            built = "No";
        }
        else if (!(ui->checkNo->isChecked()) && !(ui->checkYes->isChecked()))
        {
            ui->errorLabelC->setText("<span style='color: red'>Boxes for Was It Built are empty!</span>");
            success = false;
        }
        if (success)
        {   //
            int answer = QMessageBox::question(this, "Confirm", "Are you sure?");
            if(answer == QMessageBox::No)
            {
                return;
            }

            c1.setName(name);
            c1.setType(type);
            c1.setBuiltYear(buildYear);
            c1.setBuiltComputer(built);

            d1.updateComputer(c1);
            cs1->updateComputers();
            this->close();
        }
    }
}

