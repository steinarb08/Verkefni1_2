#ifndef EDITPERSON_H
#define EDITPERSON_H

#include <QDialog>
#include <iostream>
#include <personscreen.h>
#include <domainlayer.h>

namespace Ui {
class editPerson;
}

class editPerson : public QDialog
{
    Q_OBJECT

public:
     editPerson(QWidget *parent, DomainLayer &dom, Person &per,PersonScreen *perScreen);
     // Default constructor. Selected scientist appears in edit label boxes.
    ~editPerson();

private slots:
    void on_btnCancelEdit_clicked();
    // Cancel button.

    void on_btnSaveEdit_clicked();
    // Saves edited scientists. Error checks.

    void on_checkBoxMale_clicked();
    // If one box is checked, you cant check the other one.

    void on_checkBoxFemale_clicked();
    // If one box is checked, you cant check the other one.

private:
    Ui::editPerson *ui;
    DomainLayer d1;
    Person p1;
    PersonScreen *ps1;
};

#endif // EDITPERSON_H
