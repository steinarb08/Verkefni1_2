#ifndef COMPUTERSCREEN_H
#define COMPUTERSCREEN_H

#include <QMainWindow>

namespace Ui {
class ComputerScreen;
}

class ComputerScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit ComputerScreen(QWidget *parent = 0);
    ~ComputerScreen();

private:
    Ui::ComputerScreen *ui;
};

#endif // COMPUTERSCREEN_H
