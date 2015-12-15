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
    ~editPerson();

private slots:
    //void on_lineEditNewName_textChanged(const QString &arg1);

    void on_btnCancelEdit_clicked();

    void on_btnSaveEdit_clicked();

    void on_checkBoxMale_clicked();

    void on_checkBoxFemale_clicked();

private:
    Ui::editPerson *ui;
    DomainLayer d1;
    Person p1;
    PersonScreen *ps1;
};

#endif // EDITPERSON_H
