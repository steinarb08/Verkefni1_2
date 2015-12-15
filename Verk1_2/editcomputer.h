#ifndef EDITCOMPUTER_H
#define EDITCOMPUTER_H

#include <QMainWindow>
#include <domainlayer.h>
#include <computer.h>
#include <computerscreen.h>

namespace Ui {
class EditComputer;
}

class EditComputer : public QMainWindow
{
    Q_OBJECT

public:
     EditComputer(QWidget *parent, DomainLayer &dom, Computer &com, ComputerScreen *cpuScreen);
     // Default constructor. Selected scientist appears in edit label boxes
    ~EditComputer();

private slots:
     void on_btnCancelEditC_clicked();
     // Function for cancel button to close the window

     void on_btnSaveEditC_clicked();
     // Function for save button to overwrite computer list

private:
    Ui::EditComputer *ui;
    DomainLayer d1;
    Computer c1;
    ComputerScreen *cs1;
};

#endif // EDITCOMPUTER_H
