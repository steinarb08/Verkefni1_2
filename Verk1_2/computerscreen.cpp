#include "computerscreen.h"
#include "ui_computerscreen.h"

ComputerScreen::ComputerScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ComputerScreen)
{
    ui->setupUi(this);
}

ComputerScreen::~ComputerScreen()
{
    delete ui;
}
