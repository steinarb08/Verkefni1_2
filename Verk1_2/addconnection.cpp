#include "addconnection.h"
#include "ui_addconnection.h"

AddConnection::AddConnection(QWidget *parent,DomainLayer &dom,Person per,ConnectionScreen *parentScreen) :
    QMainWindow(parent),
    ui(new Ui::AddConnection)
{
    ui->setupUi(this);
    d1 = dom;
    ui->lstConnectItem->clear();
    p1 = per;
    scientist = true;
    computerList = d1.loadComputer();
    pScreen = parentScreen;
    for(int i=0;i<computerList.size();i++)
    {
        ui->lstConnectItem->addItem(QString::fromStdString(computerList.at(i).getName()));
    }
}

AddConnection::AddConnection(QWidget *parent,DomainLayer &dom,Computer com,ConnectionScreen *parentScreen) :
    QMainWindow(parent),
    ui(new Ui::AddConnection)
{
    pScreen = parentScreen;
    c1 = com;
    ui->setupUi(this);
    d1 = dom;
    scientist = false;
    ui->lstConnectItem->clear();
    personList = d1.loadPerson();
    for(int i=0;i<personList.size();i++)
    {
        ui->lstConnectItem->addItem(QString::fromStdString(personList.at(i).getName()));
    }
}

AddConnection::~AddConnection()
{
    delete ui;
}

void AddConnection::on_btnAdd_clicked()
{
    if(!scientist)
    {
        d1.addCPlinkToDb(personList.at(ui->lstConnectItem->currentRow()),c1);
        pScreen->updateFoundValues();
        this->close();
    }
    else
    {
        d1.addCPlinkToDb(p1,computerList.at(ui->lstConnectItem->currentRow()));
        pScreen->updateFoundValues();
        this->close();
    }
}
