#ifndef ADDCOMPUTERWINDOW_H
#define ADDCOMPUTERWINDOW_H
#include <domainlayer.h>
#include <computer.h>
#include <QMainWindow>
#include <computerscreen.h>

namespace Ui {
class AddComputerWindow;
}

class AddComputerWindow : public QMainWindow
{
    Q_OBJECT

public:
     AddComputerWindow(QWidget *parent,DomainLayer dom, ComputerScreen *cpuScreen);
     // Default constructor
    ~AddComputerWindow();

private slots:
    void on_checkYes_clicked();
    // Only one box can be checked.

    void on_checkNo_clicked();
    // Only one box can be checked.

    void on_btnAddC_clicked();
    // Adds new computer to database.

    void on_btnCancelC_2_clicked();
    // Closes the window when entered "Cancel" box

private:
    DomainLayer d1;
    // includes functions from datalayer
    Ui::AddComputerWindow *ui;
    ComputerScreen *cs1;

};

#endif // ADDCOMPUTERWINDOW_H
