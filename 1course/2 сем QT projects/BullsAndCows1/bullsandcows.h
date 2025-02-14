#ifndef BULLSANDCOWS_H
#define BULLSANDCOWS_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class BullsAndCows; }
QT_END_NAMESPACE

class BullsAndCows : public QMainWindow
{
    Q_OBJECT

public:
    BullsAndCows(QWidget *parent = nullptr);
    ~BullsAndCows();

private slots:
    void on_newGame_clicked();
    void on_check_clicked();

    void on_records_clicked();

private:
    Ui::BullsAndCows *ui;
    int gameNum;
    void generateNum();
    void readRecords();
};
#endif // BULLSANDCOWS_H
