#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QList>

class QGridLayout;
class QPoint;
class QPushButton;

class Game : public QWidget
{
    Q_OBJECT
public:
    Game(QWidget *parent = nullptr);
    void createButton(QPushButton*, int, int, int);
private:
    QList<QPushButton*> buttons;
    QList<int> numbers;
    QGridLayout* grid;
    QPoint path;
    QPixmap *px[15];
    void checkGameOver();
public slots:
    void move();

};

#endif // GAME_H
