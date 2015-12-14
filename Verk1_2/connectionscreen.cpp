#include "connectionscreen.h"
#include "ui_connectionscreen.h"

ConnectionScreen::ConnectionScreen(QWidget *parent,DomainLayer &dom) :
    QMainWindow(parent),
    ui(new Ui::ConnectionScreen)
{
    d1 = dom;
    ui->setupUi(this);
    personList = d1.loadPerson();
    computerList = d1.loadComputer();
    on_cmbList_currentTextChanged();
}

ConnectionScreen::~ConnectionScreen()
{
    delete ui;
}

void ConnectionScreen::on_selectionList_itemSelectionChanged()
{
    int i = ui->selectionList->currentRow();
    if(ui->cmbList->currentText() == "Scientist")
    {
        // Load linked computers to the other selection field
        ui->lstFoundValues->clear();
        linkedComputerList = d1.loadComputerLinkedWith(personList.at(i));
        for(unsigned int k=0;k<linkedComputerList.size();k++)
        {
            ui->lstFoundValues->addItem(QString::fromStdString(linkedComputerList.at(k).getName()));
        }

        // Change label names to person values
        ui->lblGenderlbl->setText("Gender:");
        ui->lblDyearlbl->setText("Died:");

        // Change other label text to computer type
        ui->lblGenderFoundlbl->setText("Type:");
        ui->lblDyearFoundlbl->setText("Made:");

        // Change label text to values of selected item
        ui->lblName->setText(QString::fromStdString(personList.at(i).getName()));
        ui->lblGender->setText(QString::fromStdString(personList.at(i).getGender()));
        ui->lblByear->setText(QString::number(personList.at(i).getBirthYear()));
        ui->lblDyear->setText(QString::number(personList.at(i).getDeathYear()));
    }
    else
    {
        // Load linked persons and display on other selection field
        ui->lstFoundValues->clear();
        linkedPersonList = d1.loadPersonLinkedWith(computerList.at(i));
        for(unsigned int k=0;k<linkedPersonList.size();k++)
        {
            ui->lstFoundValues->addItem(QString::fromStdString(linkedPersonList.at(k).getName()));
        }

        // Change label text to computer type
        ui->lblGenderlbl->setText("Type:");
        ui->lblDyearlbl->setText("Made:");

        // Change other label text to person type
        ui->lblGenderFoundlbl->setText("Gender:");
        ui->lblDyearFoundlbl->setText("Died:");

        // Change label text to values of selected computer
        ui->lblName->setText(QString::fromStdString(computerList.at(i).getName()));
        ui->lblGender->setText(QString::fromStdString(computerList.at(i).getType()));
        ui->lblByear->setText(QString::number(computerList.at(i).getBuiltYear()));
        ui->lblDyear->setText(QString::fromStdString(computerList.at(i).getBuiltComputer()));
    }
}

void ConnectionScreen::on_lstFoundValues_itemSelectionChanged()
{
    int selNum = ui->lstFoundValues->currentRow();
    if(ui->cmbList->currentText() == "Scientist")
    {
        ui->lblNameFound->setText(QString::fromStdString(computerList.at(selNum).getName()));
        ui->lblNameFound->setText(QString::fromStdString(computerList.at(selNum).getName()));
        ui->lblGenderFound->setText(QString::fromStdString(computerList.at(selNum).getType()));
        ui->lblByearFound->setText(QString::number(computerList.at(selNum).getBuiltYear()));
        ui->lblDyearFound->setText(QString::fromStdString(computerList.at(selNum).getBuiltComputer()));
    }
    else
    {
        ui->lblNameFound->setText(QString::fromStdString(personList.at(selNum).getName()));
        ui->lblGenderFound->setText(QString::fromStdString(personList.at(selNum).getGender()));
        ui->lblByearFound->setText(QString::number(personList.at(selNum).getBirthYear()));
        ui->lblDyearFound->setText(QString::number(personList.at(selNum).getDeathYear()));
    }
}

void ConnectionScreen::on_cmbList_currentTextChanged()
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
