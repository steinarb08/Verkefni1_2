#include "personscreen.h"
#include "ui_personscreen.h"

PersonScreen::PersonScreen(QWidget *parent,DomainLayer &dom) :
    QMainWindow(parent),
    ui(new Ui::PersonScreen)
{
    d1 = dom;
    ui->setupUi(this);
    personList = d1.loadPerson();
}

PersonScreen::~PersonScreen()
{
    delete ui;
}

void PersonScreen::on_btnLoad_clicked()
{
    ui-> listWidgetP-> clear();
    personList = d1.loadPerson();
    for(unsigned int i = 0;i < personList.size(); i++)
    {
        ui->listWidgetP->addItem(QString::fromStdString(personList.at(i).getName()));
    }
}

void PersonScreen::on_listWidgetP_itemSelectionChanged()
{
    int i = ui->listWidgetP->currentRow();

    ui-> labelSetName->setText(QString::fromStdString(personList.at(i).getName()));
    ui->labelSetGender->setText(QString::fromStdString(personList.at(i).getGender()));
    ui->labelSetBirthYear->setText(QString::number(personList.at(i).getBirthYear()));
    if(personList.at(i).getDeathYear() == -1)
    {
        ui->labelSetDeathYear->setText("Alive");
    }
    else
    {
        ui->labelSetDeathYear->setText(QString::number(personList.at(i).getDeathYear()));
    }
}

void PersonScreen::on_textBoxSearchList_textChanged(const QString &arg1)
{
    ui-> listWidgetP-> clear();
    string userInputSearch = ui->textBoxSearchList->text().toStdString();

    personList = d1.searchNameFunc(userInputSearch);

    for(unsigned int i = 0;i < personList.size(); i++)
    {
        ui->listWidgetP->addItem(QString::fromStdString(personList.at(i).getName()));
    }


}

void PersonScreen::on_btnAddPersonToList_clicked()
{
    addNewPerson *addnewperson = new addNewPerson(this);
    addnewperson->show();
}

void PersonScreen::on_listWidgetP_clicked(const QModelIndex &index)
{
    ui->btnRemove->setEnabled(true);
    ui->btnEdit->setEnabled(true);
}


//Virkar ekki, þarf að laga!!
void PersonScreen::on_btnRemove_clicked()
{
    int selectedOnList = ui->listWidgetP->currentIndex().row();

    d1.deleteFromPerson(personList.at(selectedOnList));
    ui->listWidgetP->clear();
    personList = d1.loadPerson();
    on_btnLoad_clicked();
}




void PersonScreen::on_btnEdit_clicked()
{
    editPerson *editperson = new editPerson(this);
    editperson->show();
}
