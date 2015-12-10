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
