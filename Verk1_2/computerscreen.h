#ifndef COMPUTERSCREEN_H
#define COMPUTERSCREEN_H

#include <QMainWindow>
#include <domainlayer.h>
#include <person.h>
#include <computer.h>
#include <cplink.h>
#include <vector>


namespace Ui {
class ComputerScreen;
}

class ComputerScreen : public QMainWindow
{
    Q_OBJECT

public:
    ComputerScreen(QWidget *parent,DomainLayer &dom);
    // Default constructor. Loads list.
    ~ComputerScreen();

    void updateComputers();
    // Updates computer list function.

private slots:
    void on_pushButton_clicked();
    // Add computer button.

    void on_listComputer_clicked();
    // Shows information about the selected computer.

    void on_btnRemoveC_clicked();
    // Remove button. Removes selected computer from data base.

    void on_btnEditC_clicked();
    // Edit button. Edit selected computer.

    void on_textBoxSearchComp_textChanged();
    // Searches for a substring (searchString) in the name of each Computer in a list, returns a sublist that has those substrings.

    void on_sortComputerC_currentTextChanged();
    //ComboBox for sort functions. Gives you options to choose from.

    void on_checkDescendingC_clicked();
    // Descending order check box.

private:
    DomainLayer d1;
    vector<Person> personList;
    vector<Computer> computerList;
    Ui::ComputerScreen *ui;
};



#endif // COMPUTERSCREEN_H
