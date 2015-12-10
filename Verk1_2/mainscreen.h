#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <QMainWindow>
#include <personscreen.h>

namespace Ui {
class MainScreen;
}

class MainScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainScreen(QWidget *parent = 0);
    ~MainScreen();

private slots:
    void on_btnQuit_clicked();

    void on_btnPerson_clicked();

private:
    Ui::MainScreen *ui;
};

#endif // MAINSCREEN_H
