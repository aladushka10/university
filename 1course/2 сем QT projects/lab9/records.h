#ifndef RECORDS_H
#define RECORDS_H

#include <QMainWindow>
#include "game.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class Records;
}
QT_END_NAMESPACE
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
