#ifndef CONNECTIONSCREEN_H
#define CONNECTIONSCREEN_H

#include <QMainWindow>

namespace Ui {
class ConnectionScreen;
}

class ConnectionScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit ConnectionScreen(QWidget *parent = 0);
    ~ConnectionScreen();

private:
    Ui::ConnectionScreen *ui;
};

#endif // CONNECTIONSCREEN_H
