#include "connectionscreen.h"
#include "ui_connectionscreen.h"

ConnectionScreen::ConnectionScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ConnectionScreen)
{
    ui->setupUi(this);
}

ConnectionScreen::~ConnectionScreen()
{
    delete ui;
}
