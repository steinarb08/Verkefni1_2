#include "addcomputerwindow.h"
#include "ui_addcomputerwindow.h"
#include <computer.h>
#include "QMessageBox"

AddComputerWindow::AddComputerWindow(QWidget *parent,DomainLayer dom) :
    QMainWindow(parent),
    ui(new Ui::AddComputerWindow)
{
    ui->setupUi(this);
    d1 = dom;
}

AddComputerWindow::~AddComputerWindow()
{
    delete ui;
}


void AddComputerWindow::on_checkYes_clicked()
{
    ui->checkNo->setChecked(false);
    ui->checkYes->setChecked(true);
}


void AddComputerWindow::on_checkNo_clicked()
{
    ui->checkYes->setChecked(false);
    ui->checkNo->setChecked(true);
}

void AddComputerWindow::on_btnAddC_clicked()
{
    string name = ui->textNewNameC->toPlainText().toStdString();
    name = d1.fixName(name);
    string type = ui->textNewType->toPlainText().toStdString();
    type = d1.fixName(type);
    int buildYear = ui->textNewBuildYear->toPlainText().toInt();
    string built = "";
    bool success = true;

    if(ui->checkYes->isChecked())
    {
        built = "Yes";
    }
    else
    {
        built = "No";
    }

    if(name.empty())
    {
        ui->errorLabelC->setText("<span style = 'color: red'>Empty Name!</span>");
        success = false;
    }
    else if(buildYear <= 1800)
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

           if(success)
           {
                int answer = QMessageBox::question(this, "Confirm", "Are you sure?");
                if(answer == QMessageBox::No)
                {
                    return;
                }

                Computer c1(name,buildYear,type,built);
                d1.addComputerToDB(c1);

                this->close();
           }
        }
}





void AddComputerWindow::on_btnCancelC_2_clicked()
{
    this->close();
}
