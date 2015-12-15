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
    ~AddComputerWindow();

private slots:
    void on_checkYes_clicked();

    void on_checkNo_clicked();

    void on_btnAddC_clicked();

    void on_btnCancelC_2_clicked();

private:
    DomainLayer d1;
    Ui::AddComputerWindow *ui;
    ComputerScreen *cs1;

};

#endif // ADDCOMPUTERWINDOW_H
