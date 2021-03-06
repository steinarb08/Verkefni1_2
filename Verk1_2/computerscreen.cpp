#include "computerscreen.h"
#include "ui_computerscreen.h"
#include "editcomputer.h"
#include "addcomputerwindow.h"
#include "QMessageBox"

// Default constructor. Loads list.
ComputerScreen::ComputerScreen(QWidget *parent,DomainLayer &dom) :
    QMainWindow(parent),
    ui(new Ui::ComputerScreen)
{
    ui->setupUi(this);
    d1 = dom;
    computerList = d1.loadComputer();
    updateComputers();
    on_sortComputerC_currentTextChanged();
}

ComputerScreen::~ComputerScreen()
{
    delete ui;
}

// Add computer button.
void ComputerScreen::on_pushButton_clicked()
{
    AddComputerWindow *addcomputerwindow = new AddComputerWindow(this,d1,this);
    addcomputerwindow->show();
}

// Updates computer list function.
void ComputerScreen::updateComputers()
{
    ui->listComputer->clear();
    computerList = d1.loadComputer();
    for(unsigned int i=0;i<computerList.size();i++)
    {
        ui->listComputer->addItem(QString::fromStdString(computerList.at(i).getName()));
    }
}

// Shows information about the selected computer.
void ComputerScreen::on_listComputer_clicked()
{
    int i = ui->listComputer->currentRow();
    ui-> btnRemoveC-> setEnabled(true);
    ui->btnEditC->setEnabled(true);

    ui->lblComputerName->setText(QString::fromStdString(computerList.at(i).getName()));
    ui->lblBuiltYear->setText(QString::number(computerList.at(i).getBuiltYear()));
    ui->lblType->setText(QString::fromStdString(computerList.at(i).getType()));
    ui->lblBuilt->setText(QString::fromStdString(computerList.at(i).getBuiltComputer()));
}

// Remove button. Removes selected computer from data base.
void ComputerScreen::on_btnRemoveC_clicked()
{
    if(ui->listComputer->selectedItems().empty())
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

        int selectedComputerIndex = ui->listComputer->currentRow();
        d1.deleteFromComputer(computerList.at(selectedComputerIndex));
        ui->listComputer->clear();
        computerList = d1.loadComputer();
        updateComputers();
    }
}

// Edit button. Edit selected computer.
void ComputerScreen::on_btnEditC_clicked()
{
    if(ui->listComputer->selectedItems().empty())
    {
        QMessageBox::information(NULL,"Edit error","No item selected!");
    }
    else
    {
        EditComputer *editcomputer = new EditComputer(this, d1,computerList.at(ui->listComputer->currentRow()), this);
        editcomputer->show();
    }
}

// Searches for a substring (searchString) in the name of each Computer in a list, returns a sublist that has those substrings.
void ComputerScreen::on_textBoxSearchComp_textChanged()
{
    ui-> listComputer-> clear();
    string userInputSearch = ui->textBoxSearchComp->toPlainText().toStdString();

    computerList = d1.searchName_C(userInputSearch);

    for(unsigned int i = 0;i < computerList.size(); i++)
    {
        ui->listComputer->addItem(QString::fromStdString(computerList.at(i).getName()));
    }
}

//ComboBox for sort functions. Gives you options to choose from.
void ComputerScreen::on_sortComputerC_currentTextChanged()
{
    string sort = ui->sortComputerC->currentText().toStdString();

    // Sorts the names in alphabetical order (A-Z) or descending alphabetical order(Z-A).
    if(sort == "Name")
    {
        if(ui->checkDescendingC->isChecked())
        {
            computerList = d1.reverse_C();
        }
        else
        {
            computerList = d1.sortFromAtoZ_C();
        }
    }
    // Sorts types in ascending or descending order
    else if(sort == "Type")
    {
        if(ui->checkDescendingC->isChecked())
        {
            computerList = d1.sortTypeReverse_C();
        }
        else
        {
            computerList = d1.sortType_C();
        }
    }
    // Sorts build year in ascending or descending order
    else if(sort == "Build Year")
    {
        if(ui->checkDescendingC->isChecked())
        {
            computerList = d1.sortYearBuildReverse_C();
        }
        else
        {
            computerList = d1.sortYearBuild_C();
        }
    }
    // Sorts whether the computer was built or not in ascending or descending order.
    else if(sort == "Was It Built?")
    {
        if(ui->checkDescendingC->isChecked())
        {
            computerList = d1.sortMadeReverse_C();
        }
        else
        {
            computerList = d1.sortMade_C();
        }
    }

    // updates ordered list.
    ui->listComputer->clear();
    for(unsigned int i=0;i<computerList.size();i++)
    {
        ui->listComputer->addItem(QString::fromStdString(computerList.at(i).getName()));
    }
}

// Descending order check box.
void ComputerScreen::on_checkDescendingC_clicked()
{
    on_sortComputerC_currentTextChanged();
}
