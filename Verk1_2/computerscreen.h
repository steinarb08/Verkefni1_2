#ifndef COMPUTERSCREEN_H
#define COMPUTERSCREEN_H

#include <QMainWindow>
#include <domainlayer.h>
#include <person.h>
#include <computer.h>
#include <cplink.h>
#include <vector>
#include "addcomputerwindow.h"

namespace Ui {
class ComputerScreen;
}

class ComputerScreen : public QMainWindow
{
    Q_OBJECT

public:
    ComputerScreen(QWidget *parent,DomainLayer &dom);
    ~ComputerScreen();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_listComputer_clicked(const QModelIndex &index);

    void on_btnRemoveC_clicked();



    void on_btnEditC_clicked();

private:
    DomainLayer d1;
    vector<Person> personList;
    vector<Computer> computerList;
    Ui::ComputerScreen *ui;
};



#endif // COMPUTERSCREEN_H
