#ifndef ADDNEWPERSON_H
#define ADDNEWPERSON_H

#include <QDialog>
#include <domainlayer.h>
#include <person.h>
#include <vector>
#include <string>
#include <QMessageBox>
class PersonScreen;

namespace Ui {
class addNewPerson;
}

class addNewPerson : public QDialog
{
    Q_OBJECT

public:
     addNewPerson(QWidget *parent,DomainLayer &dom, PersonScreen *perscreen);
    ~addNewPerson();

private slots:
    void on_Button_Cancel_NewScientist_clicked();

    void on_Button_ADD_NewScientist_clicked();

    void on_checkBox_male_clicked();

    void on_checkBox_female_clicked();

private:
    Ui::addNewPerson *ui;
    DomainLayer d1;
    PersonScreen *ps1;
};

#endif // ADDNEWPERSON_H
