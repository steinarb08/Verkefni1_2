#ifndef PERSONSCREEN_H
#define PERSONSCREEN_H

#include <QMainWindow>
#include <domainlayer.h>
#include <person.h>
#include <computer.h>
#include <cplink.h>
#include <vector>
#include "addnewperson.h"
#include "editperson.h"

namespace Ui {
class PersonScreen;
}

class PersonScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit PersonScreen(QWidget *parent = 0);
    ~PersonScreen();

private slots:
    void on_btnLoad_clicked();

    void on_listWidgetP_itemSelectionChanged();

    void on_textBoxSearchList_textChanged(const QString &arg1);

    void on_btnAddPersonToList_clicked();

    void on_listWidgetP_clicked(const QModelIndex &index);

    void on_btnRemove_clicked();

    void on_btnEdit_clicked();

private:
    Ui::PersonScreen *ui;
    DomainLayer d1;
    vector<Person> personList;
};

#endif // PERSONSCREEN_H
