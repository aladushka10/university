#ifndef RECORDS_H
#define RECORDS_H

#include <QMainWindow>

namespace Ui {
class Records;
}

class Records : public QMainWindow
{
    Q_OBJECT

public:
    struct record
    {
        int attempts;
        QString name;
    };
    explicit Records(QWidget *parent = nullptr);
    ~Records();
    void write(QVector <record>&);
private:
    Ui::Records *ui;
};

#endif // RECORDS_H
