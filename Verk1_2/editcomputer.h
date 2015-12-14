#ifndef EDITCOMPUTER_H
#define EDITCOMPUTER_H

#include <QMainWindow>
#include <domainlayer.h>
#include <computer.h>

namespace Ui {
class EditComputer;
}

class EditComputer : public QMainWindow
{
    Q_OBJECT

public:
     EditComputer(QWidget *parent, DomainLayer &dom, Computer &com);
    ~EditComputer();

private slots:
     void on_btnCancelEditC_clicked();

private:
    Ui::EditComputer *ui;
    DomainLayer d1;
    Computer c1;
};

#endif // EDITCOMPUTER_H
