#include "game.h"
#include "records.h"
#include "ui_game.h"
#include <stdlib.h>
#include <string>
#include <QWidget>
#include <QtWidgets>
#include <ctime>
#include <algorithm>




game::game(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::game)
{
    ui->setupUi(this);
    connect (ui->play, SIGNAL(clicked()), this, SLOT(play_clicked()));
    connect (ui->newGame, SIGNAL(clicked()), this, SLOT(newGame_clicked()));
    connect (ui->leadersBoard, SIGNAL(clicked()), SLOT(leaders_clicked()));
    connect (ui->check, SIGNAL(clicked()), SLOT(check_clicked()));

    ui->input->hide();
    ui->leadersBoard->hide();
    ui->newGame->hide();
    ui->check->hide();
    ui->label->hide();
    ui->tableWidget->hide();
    ui->statusbar->hide();

    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "number" << "result");
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setStyleSheet("background-color:rgb(227, 244, 255);"
                                                       "color:rgb(85, 143, 255);"
                                                       "font-size: 18px;"
                                                       "font-family: Didot;"
                                                       );
    ui->tableWidget->verticalHeader()->setStyleSheet("background-color:rgb(227, 244, 255);"
                                                       "color:rgb(85, 143, 255);"
                                                       "font-size: 18px;"
                                                       "font-family: Didot;"
                                                       );
}


game::~game()
{
    delete ui;
}


void game::generate()
{
    QList<int> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int b,num = 0;
    for (int i = 0; i < 4; ++i)
    {
        num *= 10;
        num += digits.takeAt(QRandomGenerator::global()->bounded(digits.size()));
        if (num == 0)
        {
            digits.push_front(0);
            i--;
        }
    }
    for (int i= 3; i >=0 ;i--)
    {
        b = num % 10;
        comp[i]=b;
        num=(num-b)/10;
    }
}


void game::play_clicked()
{
    ui->mainLabel->hide();
    ui->play->hide();
    ui->input->show();
    ui->leadersBoard->show();
    ui->newGame->show();
    ui->check->show();
    ui->label->show();
    ui->tableWidget->show();
    ui->label->setText("enter a number:");
    newGame();
}


void game::newGame_clicked()
{
    while(ui->tableWidget->rowCount())
        ui->tableWidget->removeRow(0);
    newGame();
}


void game::readRecords()
{
    QFile input("/Users/viktoriasamsonova/lab9/records.txt");
    if (!input.open(QIODevice::ReadOnly))
        QMessageBox::about(this, "Error!","oops!leader board can not be opened!" );
    else
    {
        recordsList.clear();
        while (!input.atEnd())
        {
            char buf[1024];
            qint64 lineLength = input.readLine(buf, sizeof(buf));
            QString temp("");
            Records::record curRecord;
            for (qint64 j = 0; j< lineLength- 1; j++)
                if (buf[j] == ' ')
                {
                    curRecord.attempts = temp.toInt();
                    temp = "";
                }
                else
                    temp += buf[j];
            curRecord.name = temp;
            recordsList.push_back(curRecord);
        }
        std::sort(recordsList.begin(), recordsList.end());
        reloadRecords();
        input.close();
    }
}


void game::reloadRecords()
{
    QFile file("/Users/viktoriasamsonova/lab9/records.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
        QMessageBox::about(this, "Error!","oops!leader board can not be opened!" );
    else
    {
        QTextStream output(&file);
        for (int i = 0; i < recordsList.size(); i++)
            output << recordsList[i].attempts << ' ' << recordsList[i].name << '\n';
        file.close();
    }
}


void game::leaders_clicked()
{
readRecords();
records.write(recordsList);
records.show();
}

void game::newGame()
{
    ui->status->clear();
    generate();
    if (ui->input->text() != "")
    {
        if (ui->check->isChecked())
            check_clicked();
    }
}


void game::newNumber()
{
    int c;

    int myNumber = ui->input->text().toInt();

    for (int i = 3; i >= 0; i--)
    {
        c = myNumber % 10;
        my[i]=c;
        myNumber=(myNumber-c)/10;
    }
    bulls = 0;
    cows = 0;
    for (int i = 0; i < 4; i++)
    {
        if (my[i] == comp[i])
            bulls++;
        else
        {
            for (int j = 0; j<4; j++)
            {
                if (my[i] == comp[j])
                {
                    cows++;
                    break;
                }
            }
        }
    }
}


bool operator <(const Records::record &a, const Records::record &b)
{
    return a.attempts < b.attempts;
}


void game::check_clicked()
{
    if (ui->input->text() == "")
    {
//        QMessageBox error;
//        error.setText("Ошибка при открытии файла рекордов");
//        error.exec();
        QMessageBox::about(this, "Error!", "No any number to check!"
                                           " Input it");
        ui->input->clear();
    }
    else
    {
        bool isNum;
        ui->input->text().toInt(&isNum);
        if (!isNum)
        {
            QMessageBox::about(this, "Error!", "It's not a number!"
                                               " Input one more time");
            ui->input->clear();
        }
        else
        {

            if (ui->input->text().length() != 4 || ui->input->text()[0] == '0')
            {
                if (ui->input->text()[0] == '0' && ui->input->text()[1] == '0' && ui->input->text()[2] == '0' && ui->input->text()[3] == '0')
                {
                    QMessageBox::about(this, "Error!", "Incorrect number!"
                                                       " Input one more time");
                    ui->input->clear();
                }

                else
                {
                    QMessageBox::about(this, "Error!", "Incorrect size of a number!"
                                                       " Input one more time");
                    ui->input->clear();
                }
            }
            else
            {
                newNumber();
                bool isUnique = true;
                for (int i = 0; i < 4; ++i)
                    for (int j = i + 1; j < 4; j++)
                        if (my[i] == my[j])
                        {
                            isUnique = false;
                            break;
                        }

                if (!isUnique)
                {
                     QMessageBox::about(this, "Error!", "Numbers should be unique!"
                                                           " Input one more time");
                    ui->input->clear();
                }
                else
                {
                    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
                    QTableWidgetItem *item1 = new QTableWidgetItem(ui->input->text());
                    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0, item1);
                    QTableWidgetItem *item2 = new QTableWidgetItem("Bulls: " + QString::number(bulls) + " Cows: " + QString::number(cows));
                    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 1, item2);
                    ui->input->clear();
                    if (bulls == 4)
                    {
                        QMessageBox::about(this, "", "You won! You had " + QString::number(ui->tableWidget->rowCount()) + " attempts");
                        ui->input->setText("");
                        ui->label->clear();
                        ui->check->setEnabled(false);
                        ui->input->setEnabled(false);
                        RecordDialog* dialog = new RecordDialog;
                        if (dialog->exec() == QDialog::Accepted)
                        {
                            Records::record newRecord;
                            newRecord.name = dialog->name();
                            newRecord.attempts = ui->tableWidget->rowCount();
                            if (recordsList.size() < 10)
                            {
                                recordsList.push_back(newRecord);
                            }
                            else
                            {
                                if (recordsList[recordsList.size() - 1].attempts > newRecord.attempts)
                                {
                                    recordsList.pop_back();
                                    recordsList.push_back(newRecord);
                                }
                            }
                            std::sort(recordsList.begin(), recordsList.end());
                            reloadRecords();
                        }
                    }
                    else
                    {
                        if (ui->tableWidget->rowCount() == 0)
                            ui->status->setText(QString::number((ui->tableWidget->rowCount())+1) + "'st attempt");
                        else if (ui->tableWidget->rowCount() == 1)
                        ui->status->setText(QString::number((ui->tableWidget->rowCount())+1) + "'nd attempt");
                        else if (ui->tableWidget->rowCount() == 2)
                            ui->status->setText(QString::number((ui->tableWidget->rowCount())+1) + "'rd attempt");
                        else
                            ui->status->setText(QString::number((ui->tableWidget->rowCount()+1)) + "'th attempt");
                    }
                }
            }
        }
    }
}




