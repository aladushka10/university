#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "game.h"
class QHBoxLayout;
class QLabel;
class QLCDNumber;
class QSpinBox;
class QVBoxLayout;

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
public slots:
    void newGame();
    void exitGame();

private:
    Game* game;
    QHBoxLayout* settingsLayout;
    QVBoxLayout* layout;
    QSpinBox* cubesize;
    QTimer* timer;
};
#endif // WIDGET_H
