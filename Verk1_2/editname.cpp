#include "editname.h"
#include "ui_editname.h"

edtiName::edtiName(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edtiName)
{
    ui->setupUi(this);
}

edtiName::~edtiName()
{
    delete ui;
}
