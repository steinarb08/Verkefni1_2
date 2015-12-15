#include "personscreen.h"
#include "ui_personscreen.h"
#include "addnewperson.h"
#include "editperson.h"

PersonScreen::PersonScreen(QWidget *parent,DomainLayer &dom) :
    QMainWindow(parent),
    ui(new Ui::PersonScreen)
{
    d1 = dom;
    ui->setupUi(this);
    personList = d1.loadPerson();
    updateValues();
}


PersonScreen::~PersonScreen()
{
    delete ui;
}
//List which displays all scientists
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
//Text box for search function.
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
//Button that opens new window, Add person window.
void PersonScreen::on_btnAddPersonToList_clicked()
{
    addNewPerson *addnewperson = new addNewPerson(this, d1, this);
    addnewperson->show();
}
//Enables remove and edit buttons
void PersonScreen::on_listWidgetP_clicked(const QModelIndex &index)
{
    ui->btnRemove->setEnabled(true);
    ui->btnEdit->setEnabled(true);
}
//Remove button. Removes from list. Pop-up window for confirmation
void PersonScreen::on_btnRemove_clicked()
{
    if(ui->listWidgetP->selectedItems().empty())
    {
        QMessageBox::information(NULL,"Remove error","No item selected!");
    }
    else
    {
        int answer = QMessageBox::question(this, "Confirm", "Are you sure?");
        if(answer == QMessageBox::No)
        {
            return;
        }
        int selectedOnList = ui->listWidgetP->currentIndex().row();

        d1.deleteFromPerson(personList.at(selectedOnList));
        ui->listWidgetP->clear();
        personList = d1.loadPerson();
        updateValues();
        ui->labelSetName->clear();
        ui->labelSetGender->clear();
        ui->labelSetBirthYear->clear();
        ui->labelSetDeathYear->clear();
    }
}
//Button that opens edit scientist window
void PersonScreen::on_btnEdit_clicked()
{
    if(ui->listWidgetP->selectedItems().empty())
    {
        QMessageBox::information(NULL,"Edit error","No item selected!");
    }
    else
    {
        editPerson *editperson = new editPerson(this, d1, personList.at(ui->listWidgetP->currentRow()),this);
        editperson->show();
    }
}
//Updateds values when add new scientist and edit scientist are finshed
void PersonScreen::updateValues()
{
    ui-> listWidgetP-> clear();
    personList = d1.loadPerson();
    on_comboBoxSort_currentTextChanged();
}
//ComboBox for sort functions. Gives you options to choose from
void PersonScreen::on_comboBoxSort_currentTextChanged()
{
    string sort = ui->comboBoxSort->currentText().toStdString();
    if(sort == "Name")
    {
        if(ui->checkBoxDescending->isChecked())
        {
            personList = d1.reverse();
        }
        else
        {
            personList = d1.sortFromAtoZ();
        }
    }
    else if (sort == "Gender")
    {
        if(ui->checkBoxDescending->isChecked())
        {
            personList = d1.reverseGender();
        }
        else
        {
            personList = d1.sortGender();
        }
    }
    else if(sort == "Year of Birth")
    {
        if(ui->checkBoxDescending->isChecked())
        {
            personList = d1.sortBirthYearDescending();
        }
        else
        {
            personList = d1.sortBirthYear();
        }
    }
    else if(sort == "Year of Death")
    {
        if(ui->checkBoxDescending->isChecked())
        {
            personList = d1.sortDeathYearDescending();
        }
        else
        {
            personList = d1.sortDeathYear();
        }
    }
    ui->listWidgetP->clear();
    for(unsigned int i = 0; i < personList.size(); i++)
    {
        ui->listWidgetP->addItem(QString::fromStdString(personList.at(i).getName()));
    }
}
//Check Box for sort, if you want descending. Ascending is default
void PersonScreen::on_checkBoxDescending_clicked()
{
    on_comboBoxSort_currentTextChanged();
}
