#ifndef PERSONSCREEN_H
#define PERSONSCREEN_H

#include <QMainWindow>

namespace Ui {
class PersonScreen;
}

class PersonScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit PersonScreen(QWidget *parent = 0);
    ~PersonScreen();

private:
    Ui::PersonScreen *ui;
};

#endif // PERSONSCREEN_H
