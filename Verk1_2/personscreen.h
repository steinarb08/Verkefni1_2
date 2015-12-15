#ifndef PERSONSCREEN_H
#define PERSONSCREEN_H

#include <QMainWindow>
#include <domainlayer.h>
#include <person.h>
#include <computer.h>
#include <cplink.h>
#include <vector>


namespace Ui {
class PersonScreen;
}

class PersonScreen : public QMainWindow
{
    Q_OBJECT

public:
    PersonScreen(QWidget *parent,DomainLayer &dom);
    // Default Constructor. Loads scientists in list.

    void updateValues();
    // Updateds values when add new scientist and edit scientist are finshed.

    ~PersonScreen();

private slots:

    void on_listWidgetP_itemSelectionChanged();
    // List which displays all scientists

    void on_textBoxSearchList_textChanged();
    // Text box for search function.

    void on_btnAddPersonToList_clicked();
    // Button that opens new window, Add person window.

    void on_listWidgetP_clicked();
    // Enables remove and edit buttons

    void on_btnRemove_clicked();
    // Remove button. Removes from list. Pop-up window for confirmation.

    void on_btnEdit_clicked();
    // Button that opens edit scientist window.

    void on_comboBoxSort_currentTextChanged();
    // ComboBox for sort functions. Gives you options to choose from.

    void on_checkBoxDescending_clicked();
    // Check Box for sort, if you want descending. Ascending is default

private:
    Ui::PersonScreen *ui;
    DomainLayer d1;
    vector<Person> personList;
};

#endif // PERSONSCREEN_H
