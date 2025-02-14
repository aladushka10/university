#ifndef TABLERECORDS_H
#define TABLERECORDS_H

#include <QWidget>

namespace Ui {
class tableRecords;
}

class tableRecords : public QWidget
{
    Q_OBJECT

public:
    struct record
    {
        int attempts;
        QString name;
    };
    explicit tableRecords(QWidget *parent = nullptr);
    ~tableRecords();
    void write(QVector <record>&);

private:
    Ui::tableRecords *ui;
};

#endif // TABLERECORDS_H
