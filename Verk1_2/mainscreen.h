#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <QMainWindow>
#include <personscreen.h>
#include <computerscreen.h>
#include <connectionscreen.h>
#include <domainlayer.h>

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
    // Scientist button.

    void on_btnComputer_clicked();
    // Computer button.

    void on_btnConnection_clicked();
    // Connector button.

private:
    DomainLayer d1;
    Ui::MainScreen *ui;
};

#endif // MAINSCREEN_H
