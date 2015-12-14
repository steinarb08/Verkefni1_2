#include "computerscreen.h"
#include "ui_computerscreen.h"

ComputerScreen::ComputerScreen(QWidget *parent,DomainLayer &dom) :
    QMainWindow(parent),
    ui(new Ui::ComputerScreen)
{
    ui->setupUi(this);
    d1 = dom;
    computerList = d1.loadComputer();
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

}
