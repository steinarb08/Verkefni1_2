#include "computerscreen.h"
#include "ui_computerscreen.h"
#include "editcomputer.h"

ComputerScreen::ComputerScreen(QWidget *parent,DomainLayer &dom) :
    QMainWindow(parent),
    ui(new Ui::ComputerScreen)
{
    ui->setupUi(this);
    d1 = dom;
    computerList = d1.loadComputer();
    on_sortComputerC_currentTextChanged();

}

ComputerScreen::~ComputerScreen()
{
    delete ui;
}

void ComputerScreen::on_pushButton_clicked()
{
    AddComputerWindow *addcomputerwindow = new AddComputerWindow(this,d1);
    addcomputerwindow->show();
}

void ComputerScreen::on_pushButton_5_clicked()
{
    ui->listComputer->clear();
    computerList = d1.loadComputer();
        for(unsigned int i=0;i<computerList.size();i++)
        {
            ui->listComputer->addItem(QString::fromStdString(computerList.at(i).getName()));
        }

}

void ComputerScreen::on_listComputer_clicked(const QModelIndex &index)
{
    int i = ui->listComputer->currentRow();
    ui-> btnRemoveC-> setEnabled(true);
    ui->btnEditC->setEnabled(true);

     ui->lblComputerName->setText(QString::fromStdString(computerList.at(i).getName()));
     ui->lblBuiltYear->setText(QString::number(computerList.at(i).getBuiltYear()));
     ui->lblType->setText(QString::fromStdString(computerList.at(i).getType()));
     ui->lblBuilt->setText(QString::fromStdString(computerList.at(i).getBuiltComputer()));
}

void ComputerScreen::on_btnRemoveC_clicked()
{
    int selectedComputerIndex = ui->listComputer->currentRow();
    d1.deleteFromComputer(computerList.at(selectedComputerIndex));
    ui->listComputer->clear();
    computerList = d1.loadComputer();
    on_pushButton_5_clicked();


}

void ComputerScreen::on_btnEditC_clicked()
{
    EditComputer *editcomputer = new EditComputer(this, d1,computerList.at(ui->listComputer->currentRow()));
    editcomputer->show();
}

void ComputerScreen::on_textBoxSearchComp_textChanged()
{
    ui-> listComputer-> clear();
    string userInputSearch = ui->textBoxSearchComp->toPlainText().toStdString();

    computerList = d1.searchName_C(userInputSearch);

    for(unsigned int i = 0;i < computerList.size(); i++)
    {
        ui->listComputer->addItem(QString::fromStdString(computerList.at(i).getName()));
    }
}

void ComputerScreen::on_sortComputerC_currentTextChanged()
{
    string sort = ui->sortComputerC->currentText().toStdString();
    if(sort == "Name")
    {
        if(ui->checkAscendingC->isChecked())
        {
            computerList = d1.sortFromAtoZ_C();
        }
        else
        {
            computerList = d1.reverse_C();
        }
    }

    else if(sort == "Type")
    {
        if(ui->checkAscendingC->isChecked())
        {
            computerList = d1.sortType_C();
        }
        else
        {
            computerList = d1.sortTypeReverse_C();
        }
    }

    else if(sort == "Build Year")
    {
        if(ui->checkAscendingC->isChecked())
        {
            computerList = d1.sortYearBuild_C();
        }
        else
        {
            computerList = d1.sortYearBuildReverse_C();
        }
    }

    else if(sort == "Was It Built?")
    {
        if(ui->checkAscendingC->isChecked())
        {
            computerList = d1.sortMade_C();
        }
        else
        {
            computerList = d1.sortMadeReverse_C();
        }
    }

    ui->listComputer->clear();

    for(unsigned int i=0;i<computerList.size();i++)
    {
        ui->listComputer->addItem(QString::fromStdString(computerList.at(i).getName()));
    }

}

void ComputerScreen::on_checkAscendingC_clicked()
{
    on_sortComputerC_currentTextChanged();
}
