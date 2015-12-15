#ifndef CONNECTIONSCREEN_H
#define CONNECTIONSCREEN_H

#include <QMainWindow>
#include <domainlayer.h>
#include <person.h>
#include <computer.h>
#include <cplink.h>
#include <vector>
namespace Ui {
class ConnectionScreen;
}

class ConnectionScreen : public QMainWindow
{
    Q_OBJECT

public:
    ConnectionScreen(QWidget *parent,DomainLayer &dom);
    void updateFoundValues();
    ~ConnectionScreen();

private slots:
    void on_selectionList_itemSelectionChanged();

    void on_lstFoundValues_itemSelectionChanged();
    // Shows informations about selected scientist or computer.

    void on_cmbList_currentTextChanged();

    void on_cmbSort_currentTextChanged();
    // ComboBox for sort functions. Gives you options to choose from.

    void on_chkAscending_clicked();

    void on_btnRemoveConnection_clicked();
    // Remove button. Removes selected computer connections to a scientist or vice versa.

    void on_btnAddConnection_clicked();
    // Opens add a connection window.

private:
    Ui::ConnectionScreen *ui;
    DomainLayer d1;
    vector<Person> personList;
    vector<Computer> computerList;
    vector<Computer> linkedComputerList;
    vector<Person> linkedPersonList;
};

#endif // CONNECTIONSCREEN_H
