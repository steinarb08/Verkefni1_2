#include "personscreen.h"
#include "ui_personscreen.h"

PersonScreen::PersonScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PersonScreen)
{
    ui->setupUi(this);
}

PersonScreen::~PersonScreen()
{
    delete ui;
}
