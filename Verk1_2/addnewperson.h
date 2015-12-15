#ifndef ADDNEWPERSON_H
#define ADDNEWPERSON_H

#include <QDialog>
#include <domainlayer.h>
#include <person.h>
#include <vector>
#include <string>
#include <QMessageBox>
#include <personscreen.h>

namespace Ui {
class addNewPerson;
}

class addNewPerson : public QDialog
{
    Q_OBJECT

public:
     addNewPerson(QWidget *parent,DomainLayer &dom, PersonScreen *perScreen);
     // Default constructor
    ~addNewPerson();

private slots:
    void on_Button_Cancel_NewScientist_clicked();

    void on_Button_ADD_NewScientist_clicked();
    // Adds scientist to data base.

    void on_checkBox_male_clicked();
    // Only one box is allowed to be checked

    void on_checkBox_female_clicked();
    // Only one box is allowed to be checked

private:
    Ui::addNewPerson *ui;
    DomainLayer d1;
    // functions in domainlayer are included
    PersonScreen *ps1;
};

#endif // ADDNEWPERSON_H
