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
    explicit ConnectionScreen(QWidget *parent = 0);
    ~ConnectionScreen();

private slots:
    void on_btnLoadSelectionList_clicked();

    void on_selectionList_itemSelectionChanged();

private:
    DomainLayer d1;
    vector<Person> personList;
    vector<Computer> computerList;
    vector<Computer> linkedComputerList;
    vector<Person> linkedPersonList;
    Ui::ConnectionScreen *ui;
};

#endif // CONNECTIONSCREEN_H
