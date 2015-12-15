#include "mainscreen.h"
#include "ui_mainscreen.h"

MainScreen::MainScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainScreen)
{
    ui->setupUi(this);
    d1.connectToDatabase();
}

MainScreen::~MainScreen()
{
    delete ui;
}

void MainScreen::on_btnQuit_clicked()
{
    qApp->quit();
}

// Scientist button
void MainScreen::on_btnPerson_clicked()
{
    PersonScreen *personScreen = new PersonScreen(this,d1);
    personScreen->show();
}

// Computer button.
void MainScreen::on_btnComputer_clicked()
{
    ComputerScreen *computerScreen = new ComputerScreen(this,d1);
    computerScreen->show();
}

// Connector button.
void MainScreen::on_btnConnection_clicked()
{
    ConnectionScreen *connectionScreen = new ConnectionScreen(this,d1);
    connectionScreen->show();
}
