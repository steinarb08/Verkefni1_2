#include "mainscreen.h"
#include "ui_mainscreen.h"

MainScreen::MainScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainScreen)
{
    ui->setupUi(this);
}

MainScreen::~MainScreen()
{
    delete ui;
}

void MainScreen::on_btnQuit_clicked()
{
    qApp->quit();
}

void MainScreen::on_btnPerson_clicked()
{
    PersonScreen *personScreen = new PersonScreen(this);
    personScreen->show();
}