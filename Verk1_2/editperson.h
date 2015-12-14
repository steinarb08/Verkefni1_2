#ifndef EDITPERSON_H
#define EDITPERSON_H

#include <QDialog>

namespace Ui {
class editPerson;
}

class editPerson : public QDialog
{
    Q_OBJECT

public:
    explicit editPerson(QWidget *parent = 0);
    ~editPerson();

private slots:
    void on_lineEditNewName_textChanged(const QString &arg1);

    void on_btnCancelEdit_clicked();

private:
    Ui::editPerson *ui;
};

#endif // EDITPERSON_H
