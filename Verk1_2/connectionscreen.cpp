#include "connectionscreen.h"
#include "ui_connectionscreen.h"
#include "addconnection.h"
#include <qmessagebox.h>

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


void ConnectionScreen::updateFoundValues()
{
    on_selectionList_itemSelectionChanged();
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
        if(personList.at(i).getDeathYear() == -1)
        {
           ui->lblDyear->setText("Alive");
        }
        else
        {
            ui->lblDyear->setText(QString::number(personList.at(i).getDeathYear()));
        }
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
    if(ui->cmbList->currentText() == "Scientist")
    {
        // Change sort values
        ui->cmbSort->clear();
        ui->cmbSort->addItem("Name");
        ui->cmbSort->addItem("Gender");
        ui->cmbSort->addItem("Born");
        ui->cmbSort->addItem("Died");
    }
    else
    {
        // Change sort values
        ui->cmbSort->clear();
        ui->cmbSort->addItem("Name");
        ui->cmbSort->addItem("Type");
        ui->cmbSort->addItem("Born");
        ui->cmbSort->addItem("Made");
    }
}

void ConnectionScreen::on_cmbSort_currentTextChanged()
{
    string sort = ui->cmbSort->currentText().toStdString();
    if(sort == "Name")
    {
        if(ui->chkAscending->isChecked())
        {
            personList = d1.sortFromAtoZ();
            computerList = d1.sortFromAtoZ_C();
        }
        else
        {
            computerList = d1.reverse_C();
            personList = d1.reverse();
        }
    }
    else if(sort == "Gender")
    {
        if(ui->chkAscending->isChecked())
        {
            personList = d1.sortGender();
        }
        else
        {
            personList = d1.reverseGender();
        }
    }
    else if(sort == "Born")
    {
        if(ui->chkAscending->isChecked())
        {
            personList = d1.sortBirthYear();
            computerList = d1.sortYearBuild_C();
        }
        else
        {
            personList = d1.sortBirthYearDescending();
            computerList = d1.sortYearBuildReverse_C();
        }
    }
    else if(sort == "Died")
    {
        if(ui->chkAscending->isChecked())
        {
            personList = d1.sortDeathYear();
        }
        else
        {
            personList = d1.sortDeathYearDescending();
        }
    }
    else if(sort == "Type")
    {
        if(ui->chkAscending->isChecked())
        {
            computerList = d1.sortType_C();
        }
        else
        {
            computerList = d1.sortTypeReverse_C();
        }
    }
    else if(sort == "Made")
    {
        if(ui->chkAscending->isChecked())
        {
            computerList = d1.sortMade_C();
        }
        else
        {
            computerList = d1.sortMadeReverse_C();
        }
    }

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

void ConnectionScreen::on_chkAscending_clicked()
{
    on_cmbSort_currentTextChanged();
}

void ConnectionScreen::on_btnRemoveConnection_clicked()
{
    if(ui->lstFoundValues->selectedItems().empty())
    {
        QMessageBox::information(NULL,"Remove error","No item selected!");
    }
    else
    {
        if(ui->cmbList->currentText() == "Scientist")
        {
            Computer c1 = linkedComputerList.at(ui->lstFoundValues->currentRow());
            Person p1 = personList.at(ui->selectionList->currentRow());
            d1.deleteFromCPlink(p1,c1);
            linkedComputerList = d1.loadComputerLinkedWith(p1);
            ui->lstFoundValues->clear();
            for(int i=0;i<linkedComputerList.size();i++)
            {
                ui->lstFoundValues->addItem(QString::fromStdString(linkedComputerList.at(i).getName()));
            }
        }
        else
        {
            Computer c1 = computerList.at(ui->selectionList->currentRow());
            Person p1 = linkedPersonList.at(ui->lstFoundValues->currentRow());
            d1.deleteFromCPlink(p1,c1);
            linkedPersonList = d1.loadPersonLinkedWith(c1);
            ui->lstFoundValues->clear();
            for(int i=0;i<linkedPersonList.size();i++)
            {
                ui->lstFoundValues->addItem(QString::fromStdString(linkedPersonList.at(i).getName()));
            }
        }


    }
}

void ConnectionScreen::on_btnAddConnection_clicked()
{
    if(ui->selectionList->selectedItems().empty())
    {
        QMessageBox::information(NULL,"Remove error","No item selected!");
    }
    else
    {
        if(ui->cmbList->currentText() == "Scientist")
        {
            AddConnection *addConnectionScreen = new AddConnection(this,d1,personList.at(ui->selectionList->currentRow()),this);
            addConnectionScreen->show();
        }
        else
        {
            AddConnection *addConnectionScreen = new AddConnection(this,d1,computerList.at(ui->selectionList->currentRow()),this);
            addConnectionScreen->show();
        }
    }

}
