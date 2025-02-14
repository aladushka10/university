#include "game.h"
#include <QtGlobal>
#include <QGridLayout>
#include <QPoint>
#include <QPushButton>
#include <QTime>
#include <QMessageBox>

Game::Game(QWidget*)
{
    grid = new QGridLayout(this);
    grid->setHorizontalSpacing(1);
    grid->setVerticalSpacing(1);
    grid->setContentsMargins(2, 2, 2, 2);

    QTime midnight(0, 0, 0);
    srand(midnight.secsTo(QTime::currentTime()));

    // картинки
    for(int i=0;i<15;i++){
        switch (i)
        {
            case 0: px[i]=new QPixmap(":/pics/1.png");
                    break;
            case 1: px[i]=new QPixmap(":/pics/2.png");
                    break;
            case 2: px[i]=new QPixmap(":/pics/3.png");
                    break;
            case 3: px[i]=new QPixmap(":/pics/4.png");
                    break;
            case 4: px[i]=new QPixmap(":/pics/5.png");
                    break;
            case 5: px[i]=new QPixmap(":/pics/6.png");
                    break;
            case 6: px[i]=new QPixmap(":/pics/7.png");
                    break;
            case 7: px[i]=new QPixmap(":/pics/8.png");
                    break;
            case 8: px[i]=new QPixmap(":/pics/9.png");
                    break;
            case 9: px[i]=new QPixmap(":/pics/10.png");
                    break;
            case 10: px[i]=new QPixmap(":/pics/11.png");
                    break;
            case 11: px[i]=new QPixmap(":/pics/12.png");
                    break;
            case 12: px[i]=new QPixmap(":/pics/13.png");
                    break;
            case 13: px[i]=new QPixmap(":/pics/14.png");
                    break;
            case 14: px[i]=new QPixmap(":/pics/15.png");
                    break;
        }

     }
    //
    int n;

    do
    {
        numbers.clear();

        for(int i = 0; i < 15; i++)
        { // случайные числа
            do n = rand() % 15 + 1;
            while(numbers.contains(n));
            numbers << n;
        }

        n = 0;

        for(int i = 2; i <= 15; i++)
        for(int j = 0; j < numbers.indexOf(i); j++)
        {
            if(numbers[j] < i)
            {
                ++n;
            }
        }
    } while(n%2 == 1);

    do
        path.setY(rand() % 4);
    while(n%2 != path.y()%2);

    path.setX(rand() % 4);

    n = 0;

    for(int y = 0; y < 4; ++y) // строка
    for(int x = 0; x < 4; ++x) // столбец
    {
        if(path.x() == x && path.y() == y)
            continue;

        createButton(NULL, numbers[n++], x, y);
    }
    setLayout(grid);
}

void Game::move()
{
    int x, y, rs, cs;
    QPushButton* clickedBtn = static_cast<QPushButton*>(sender());
    grid->getItemPosition(grid->indexOf(clickedBtn), &y, &x, &rs, &cs);

    if((path.x() == x && (path.y() == y+1 || path.y() == y-1))
    || (path.y() == y && (path.x() == x+1 || path.x() == x-1))) // Можно ли двигать кнопку?
    {
        // удаляем кнопку со старого места
        grid->removeWidget(clickedBtn);
        // и добавляем на свободную ячейку
        createButton(clickedBtn, 0, path.x(), path.y());
        // и обновляем координаиы свободной ячейки
        path = QPoint(x, y);
        checkGameOver(); // проверка на конец игры
    }
}

void Game::checkGameOver()
{
    Q_ASSERT(grid->count() == numbers.size());

    int i=1, n=0;

    for(int y = 0; y < grid->rowCount(); ++y) // строка
    for(int x = 0; x < grid->columnCount(); ++x) // столбец
    {
        if(grid->itemAtPosition(y, x) == 0)
            continue;
        n = numbers.indexOf(i++);
        if(buttons[n] != (QPushButton*)grid->itemAtPosition(y, x)->widget())
            return;
    }

    // проверка, свободна ли последняя ячейка
    if(path.y() == grid->rowCount()-1 && path.x() == grid->columnCount()-1)
    { // игра окончена
        // блокировка всех кнопок
        for(QList<QPushButton*>::const_iterator it = buttons.begin(); it != buttons.end(); ++it)
            (*it)->setDisabled(true);
        QMessageBox::information(this, "message", "ПОБЕДА!!!");
    }
}

void Game::createButton(QPushButton* b, int no, int x, int y) // Создание кнопки
{
    QPushButton* btn = b;
    if (!btn)
    {
        btn = new QPushButton();//(QString("%1").arg(no));
        buttons << btn;
        connect(btn, SIGNAL(clicked()), this, SLOT(move()));
        btn->setFixedSize(89,89);

        QIcon ButtonIcon(*px[no-1]);
        btn->setIcon(ButtonIcon);
        btn->setIconSize(QSize(89,89));

    }
    grid->addWidget(btn, y, x);
}
