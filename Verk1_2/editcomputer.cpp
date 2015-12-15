#include "editcomputer.h"
#include "ui_editcomputer.h"
#include <QMessageBox>

EditComputer::EditComputer(QWidget *parent,DomainLayer &dom, Computer &com) :
    QMainWindow(parent),
    ui(new Ui::EditComputer)
{
    ui->setupUi(this);
    d1 = dom;
    c1 = com;
    ui->textEdit_Name->setText(QString::fromStdString(c1.getName()));
    ui->textEdit_BuiltYear->setText(QString::number(c1.getBuiltYear()));
    ui->textEdit_Type->setText(QString::fromStdString(c1.getType()));
    if(c1.getBuiltComputer() == "Yes")
    {
        ui->checkBox->setChecked(true);
    }
    else
    {
        ui->checkBox_2->setChecked(true);
    }

}

EditComputer::~EditComputer()
{
    delete ui;
}

void EditComputer::on_btnCancelEditC_clicked()
{
    this->close();
}

void EditComputer::on_btnSaveEditC_clicked()
{
    string name = ui->textEdit_Name->toPlainText().toStdString();
    string type = ui->textEdit_Type->toPlainText().toStdString();
    int buildYear = ui->textEdit_BuiltYear->toPlainText().toInt();

    string built = "";
    if(ui->checkBox->isChecked())
    {
        built = "Yes";
    }
    else
    {
        built = "No";
    }

    int answer = QMessageBox::question(this, "Confirm", "Are you sure?");
    if(answer == QMessageBox::No)
    {
        return;
    }

    c1.setName(name);
    c1.setType(type);
    c1.setBuiltYear(buildYear);
    c1.setBuiltComputer(built);

    d1.updateComputer(c1);

    this->close();
}
