#ifndef EDTINAME_H
#define EDTINAME_H

#include <QDialog>

namespace Ui {
class edtiName;
}

class edtiName : public QDialog
{
    Q_OBJECT

public:
    explicit edtiName(QWidget *parent = 0);
    ~edtiName();

private:
    Ui::edtiName *ui;
};

#endif // EDTINAME_H
