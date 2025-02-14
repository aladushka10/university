#include "tic_tac_toe.h"
#include "ui_tic_tac_toe.h"


tic_tac_toe::tic_tac_toe(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::tic_tac_toe)
{
    ui->setupUi(this);
    ui->label->setText("Player 1");

    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(symbols()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(symbols()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(symbols()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(symbols()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(symbols()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(symbols()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(symbols()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(symbols()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(symbols()));

    connect(ui->pushButton_clear, SIGNAL(clicked()), this, SLOT(clear()));
    connect(ui->radioButton, SIGNAL(clicked()), this, SLOT(gameWith()));
    connect(ui->radioButton_2, SIGNAL(clicked()), this, SLOT(gameWith()));

    setButtonsEnabled(false);
}

tic_tac_toe::~tic_tac_toe()
{
    delete ui;
}

void tic_tac_toe::setButtonsEnabled(bool flag)
{
    QPushButton * button;
    for(int i = 1; i <= 9; i++)
    {
        button = findChild<QPushButton *>(QString("pushButton_%1").arg(i));
        button->setEnabled(flag);
    }
}

bool cross = true;
bool first = true;
bool computer = true;

void tic_tac_toe::symbols()
{
    QPushButton * button = (QPushButton *) sender();
    if(button->text() == "")
    {
        if(cross)
        {
            if(first)
                ui->label->setText("Player 2");
            else
                ui->label->setText("Player 1");
            button->setText("X");
        }
        else
        {
            if(first)
                ui->label->setText("Player 1");
            else
                ui->label->setText("Player 2");
            button->setText("O");
        }
        cross = !cross;

        int end = isEnd();

        if(end == 0 && computer)
        {
            computerClick();
            end = isEnd();
        }

        if(end == 1)
        {
            if(first)
                ui->label->setText("Player 1 won!");
            else
               ui->label->setText("Player 2 won!");;
            setButtonsEnabled(false);
        }
        if(end == 2)
        {
            if(first)
                ui->label->setText("Player 1 won!");
            else
                ui->label->setText("Player 2 won!");
            setButtonsEnabled(false);
        }
        if(end == 3)
        {
            ui->label->setText("Draw!");
            setButtonsEnabled(false);
        }
    }

}

void tic_tac_toe::clear()
{
    ui->radioButton->setEnabled(true);
    ui->radioButton_2->setEnabled(true);
    ui->radioButton->setChecked(false);
    ui->radioButton_2->setChecked(false);

    setButtonsEnabled(false);

    QPushButton* button;
    for(int i = 1; i <= 9; i++)
    {
        button = findChild<QPushButton *>(QString("pushButton_%1").arg(i));
         button->setText("");
    }

    cross = true;
    if(first)
        ui->label->setText("Player 2");
    else
        ui->label->setText("Player 1");
    first = !first;
}

int tic_tac_toe::isEnd()
{
    QPushButton *button;
    QPushButton *searchButton;
    int cnt;
    ///идём вправо смотрим вниз
    for (int j = 0; j < 3; j++)
    {
        button = (QPushButton *) ui->gridLayout->itemAtPosition(0, j)->widget();
        cnt = 1;
        for (int i = 1; i < 3; i++)
        {
            searchButton = (QPushButton *) ui->gridLayout->itemAtPosition(i, j)->widget();
            if (button->text() == searchButton->text())
                cnt++;
        }
        if (cnt == 3)
        {
            if (button->text() == "X")
                return 1;
            if (button->text() == "O")
                return 2;
        }
    }
    ///идём вниз смотрим вправо
    for (int i = 0; i < 3; i++)
    {
        button = (QPushButton *) ui->gridLayout->itemAtPosition(i, 0)->widget();
        cnt = 1;
        for (int j = 1; j < 3; j++)
        {
            searchButton = (QPushButton *) ui->gridLayout->itemAtPosition(i, j)->widget();
            if (button->text() == searchButton->text())
                cnt++;
        }
        if (cnt == 3)
        {
            if (button->text() == "X")
                return 1;
            if (button->text() == "O")
                return 2;
        }
    }
    ///главная диагональ
    cnt = 1;
    button = (QPushButton *) ui->gridLayout->itemAtPosition(0, 0)->widget();
    for (int i = 1; i < 3; i++)
    {
        searchButton = (QPushButton *) ui->gridLayout->itemAtPosition(i, i)->widget();
        if (button->text() == searchButton->text())
            cnt++;
    }
    if (cnt == 3)
    {
        if (button->text() == "X")
            return 1;
        if (button->text() == "O")
            return 2;
    }
    ///побочная диагональ
    cnt = 1;
    button = (QPushButton *) ui->gridLayout->itemAtPosition(0, 3 - 1)->widget();
    for (int i = 1; i < 3; i++)
    {
        searchButton = (QPushButton *) ui->gridLayout->itemAtPosition(i, 3 - 1 - i)->widget();
        if (button->text() == searchButton->text())
            cnt++;
    }
    if (cnt == 3)
    {
        if (button->text() == "X")
            return 1;
        if (button->text() == "O")
            return 2;
    }
    cnt = 0;
    for (int i = 1; i <= 9; i++)
    {
        button = findChild<QPushButton*>(QString("pushButton_%1").arg(i));
        if (button->text() != "")
            cnt++;
    }
    if (cnt == 9)
        return 3;
    return 0;
}

void tic_tac_toe::gameWith()
{
    ui->radioButton->setEnabled(false);
    ui->radioButton_2->setEnabled(false);
    QRadioButton * radioButton = (QRadioButton *) sender();
    if(radioButton->text() == "игра с другом")
        computer = false;
    else
    {
        computer = true;
        if(!first)
            computerClick();
    }
    setButtonsEnabled(true);
}

void tic_tac_toe::computerClick()
{
    if(first)
        cross = true;
    else
        cross = false;

    int x = arc4random() % 9 +1;

    QPushButton * button;
    {
        button = findChild<QPushButton *>(QString("pushButton_%1").arg(x));
        if(button->text() == "")
        {
            if(first)
                button->setText("O");
            else
                button->setText("X");
             ui->label->setText("Player 1");
        }
        else
            computerClick();
    }
}
