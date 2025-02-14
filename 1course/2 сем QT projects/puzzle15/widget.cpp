#include "widget.h"
#include "ui_widget.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QLCDNumber>
#include <QPushButton>
//#include <QSpinBox>
#include <QTimer>
#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    layout = new QVBoxLayout(this);
    settingsLayout = new QHBoxLayout;

    QPushButton* newgame = new QPushButton();
    QPushButton* exitgame = new QPushButton();

    QPixmap newG(":/pics/new.png");
    QPixmap exG(":/pics/exit.png");
    QIcon newGIcon(newG);
    QIcon exGIcon(exG);
    newgame->setIcon(newGIcon);
    exitgame->setIcon(exGIcon);
    newgame->setIconSize(QSize(178,70));
    exitgame->setIconSize(QSize(178,70));

    connect(newgame, SIGNAL(clicked()), this, SLOT(newGame()));
    connect(exitgame, SIGNAL(clicked()), this, SLOT(exitGame()));

    settingsLayout->addWidget(newgame);
    settingsLayout->addWidget(exitgame);

    layout->setContentsMargins(2, 2, 2, 2);
    layout->addLayout(settingsLayout);
    newGame();

    setLayout(layout);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::newGame()
{
    if (game) //удаляем старое поле
    {
        layout->removeWidget(game);
        delete game;
    }

    game = new Game(this); //рисуем новое поле
    layout->addWidget(game);

    layout->update();

    game->hide();
    game->show();

    resize(sizeHint());
}

void Widget::exitGame()
{
    this->close();
}
