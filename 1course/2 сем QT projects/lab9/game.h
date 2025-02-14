#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include "recordDialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class game; }
QT_END_NAMESPACE

class game : public QMainWindow
{
    Q_OBJECT

public:
    game(QWidget *parent = nullptr);
    ~game();

protected:
    void newGame();
    void newNumber();

private slots:
   void play_clicked();
   void leaders_clicked();
   void newGame_clicked();
   void check_clicked();


   private:
    Ui::game *ui;
    int comp[4];
    int my[4];
    void generate();
    int bulls = 0;
    int cows = 0;
    Records records;
    QVector <Records::record> recordsList;
    void readRecords();
    void reloadRecords();
};



#endif // GAME_H
