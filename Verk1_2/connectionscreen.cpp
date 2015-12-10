#include "connectionscreen.h"
#include "ui_connectionscreen.h"

ConnectionScreen::ConnectionScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ConnectionScreen)
{
    ui->setupUi(this);
    personList = d1.loadPerson();
    computerList = d1.loadComputer();
}

ConnectionScreen::~ConnectionScreen()
{
    delete ui;
}

void ConnectionScreen::on_btnLoadSelectionList_clicked()
{
    ui->selectionList->clear();
    if(ui->cmbList->currentText() == "Scientist")
    {
        for(unsigned int i=0;i<personList.size();i++)
        {
            ui->selectionList->addItem(QString::fromStdString(personList.at(i).getName()));
        }
    }
    else
    {
        for(unsigned int i=0;i<computerList.size();i++)
        {
            ui->selectionList->addItem(QString::fromStdString(computerList.at(i).getName()));
        }
    }
}

void ConnectionScreen::on_selectionList_itemSelectionChanged()
{
    int i = ui->selectionList->currentRow();
    if(ui->cmbList->currentText() == "Scientist")
    {
        ui->lblGenderlbl->setText("Gender:");
        ui->lblDyearlbl->setText("Died:");
        ui->lblName->setText(QString::fromStdString(personList.at(i).getName()));
        ui->lblGender->setText(QString::fromStdString(personList.at(i).getGender()));
        ui->lblByear->setText(QString::number(personList.at(i).getBirthYear()));
        ui->lblDyear->setText(QString::number(personList.at(i).getDeathYear()));
    }
    else
    {
        ui->lblGenderlbl->setText("Type:");
        ui->lblDyearlbl->setText("Made:");

        ui->lblName->setText(QString::fromStdString(computerList.at(i).getName()));
        ui->lblGender->setText(QString::fromStdString(computerList.at(i).getType()));
        ui->lblByear->setText(QString::number(computerList.at(i).getBuiltYear()));
        ui->lblDyear->setText(QString::fromStdString(computerList.at(i).getBuiltComputer()));
    }
}
