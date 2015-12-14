#include "addcomputerwindow.h"
#include "ui_addcomputerwindow.h"
#include <computer.h>

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
    string type = ui->textNewType->toPlainText().toStdString();
    int buildYear = ui->textNewBuildYear->toPlainText().toInt();
    string built = "";
    if(ui->checkYes->isChecked())
    {
        built = "Yes";
    }
    else
    {
        built = "No";
    }
    Computer c1(name,buildYear,type,built);
    d1.addComputerToDB(c1);
}
