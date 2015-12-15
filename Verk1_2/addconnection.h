#ifndef ADDCONNECTION_H
#define ADDCONNECTION_H
#include <domainlayer.h>
#include <QMainWindow>
#include <computer.h>
#include <person.h>
#include <cplink.h>
#include <vector>
#include <connectionscreen.h>
namespace Ui {
class AddConnection;
}

class AddConnection : public QMainWindow
{
    Q_OBJECT

public:
    AddConnection(QWidget *parent,DomainLayer &dom,Computer c1,ConnectionScreen *parentScreen);
    AddConnection(QWidget *parent,DomainLayer &dom,Person p1,ConnectionScreen *parentScreen);
    ~AddConnection();

private slots:
    void on_btnAdd_clicked();

private:
    Ui::AddConnection *ui;
    DomainLayer d1;
    vector<Person> personList;
    vector<Computer> computerList;
    Computer c1;
    Person p1;
    bool scientist;
    ConnectionScreen *pScreen;
};

#endif // ADDCONNECTION_H
