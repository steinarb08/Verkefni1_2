#ifndef CONNECTIONSCREEN_H
#define CONNECTIONSCREEN_H

#include <QMainWindow>
#include <domainlayer.h>
#include <person.h>
#include <computer.h>
#include <cplink.h>
#include <vector>
#include <addconnection.h>
namespace Ui {
class ConnectionScreen;
}

class ConnectionScreen : public QMainWindow
{
    Q_OBJECT

public:
    ConnectionScreen(QWidget *parent,DomainLayer &dom);
    ~ConnectionScreen();

private slots:
    void on_selectionList_itemSelectionChanged();

    void on_lstFoundValues_itemSelectionChanged();

    void on_cmbList_currentTextChanged();

    void on_cmbSort_currentTextChanged();

    void on_chkAscending_clicked();

    void on_btnRemoveConnection_clicked();

    void on_btnAddConnection_clicked();

private:
    DomainLayer d1;
    vector<Person> personList;
    vector<Computer> computerList;
    vector<Computer> linkedComputerList;
    vector<Person> linkedPersonList;
    Ui::ConnectionScreen *ui;
};

#endif // CONNECTIONSCREEN_H
