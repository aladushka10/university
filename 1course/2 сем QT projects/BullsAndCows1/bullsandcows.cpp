#include "bullsandcows.h"
#include "ui_bullsandcows.h"
#include "tablerecords.h"
#include <QRandomGenerator>
#include <QMessageBox>
#include <QInputDialog>
#include <QFile>

BullsAndCows::BullsAndCows(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BullsAndCows)
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->lineEdit->setEnabled(false);
    ui->check->setEnabled(false);
}

BullsAndCows::~BullsAndCows()
{
    delete ui;
}

void BullsAndCows::generateNum()
{
    QList<int> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    gameNum = 0;
    for (int i = 0; i < 4; ++i) {
        gameNum *= 10;
        gameNum += digits.takeAt(QRandomGenerator::global()->bounded(digits.size()));
        if (gameNum == 0)
        {
            digits.push_front(0);
            i--;
        }
    }
}

void BullsAndCows::on_newGame_clicked()
{
    ui->check->setEnabled(true);
    ui->gameStatus->setText("Начинайте игру!");
    while(ui->tableWidget->rowCount())
        ui->tableWidget->removeRow(0);
    generateNum();
    ui->lineEdit->clear();
    ui->lineEdit->setEnabled(true);
}


void BullsAndCows::on_check_clicked()
{
    QString text = ui->lineEdit->text();
    bool isNum;
    int num = text.toInt(&isNum);
    if (isNum)
    {
        text = QString::number(num);
        if (text.size() != 4)
        {
            QMessageBox incorrectSize;
            incorrectSize.setText("Число должно состоять из 4х цифр");
            incorrectSize.exec();
        }
        else
        {
            bool isUnique = true;
            for (int i = 0; i < text.size(); ++i)
                for (int j = i + 1; j < text.size(); j++)
                    if (text[i] == text[j])
                    {
                        isUnique = false;
                        break;
                    }
            if (isUnique)
            {
                int bulls = 0;
                int cows = 0;
                QString gameNumText = QString::number(gameNum);
                for (int i = 0; i < 4; i++)
                {
                    if (text[i] == gameNumText[i])
                    {
                        bulls++;
                    }
                    else
                    {
                        for (int j = 0; j < 4; j++)
                            if (text[i] == gameNumText[j])
                            {
                                cows++;
                                break;
                            }
                    }
                }
                ui->tableWidget->insertRow(ui->tableWidget->rowCount());
                QTableWidgetItem *item1 = new QTableWidgetItem(text);
                ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0, item1);
                QTableWidgetItem *item2 = new QTableWidgetItem("Быков: " + QString::number(bulls) +
                                                               " Коров: " + QString::number(cows));
                ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 1, item2);
                if (bulls == 4)
                {
                    ui->gameStatus->setText("Игра окончена! Победа! Попыток: "
                                            + QString::number(ui->tableWidget->rowCount()));
                    ui->lineEdit->setText("");
                    ui->check->setEnabled(false);
                    ui->lineEdit->setEnabled(false);
                    if(ui->tableWidget->rowCount() < 10)
                    {
                        QTableWidgetItem *curitem = ui->tableWidget->currentItem();
                        if(curitem != nullptr)
                        {
                            ui->lineEdit->clear();
                            // int r = ui->tableWidget->row(curitem);
                             QString c_text = curitem->text();
                             QString r_text = QInputDialog::getText(this, "Данные", "Введите свое имя", QLineEdit::Normal, c_text);
                             //QString s_text = r_text.simplified();
                             /*if (!s_text.isEmpty())
                             {
                                QTableWidgetItem *item = ui->tableWidget->takeItem();
                                delete item;
                                ui->tableWidget->insertRow(r, s_text);
                                ui->tableWidget->setCurrentItem();
                             }*/
                        }
                    }
                }
                else
                {
                    ui->gameStatus->setText("Игра ещё не окончена. Попыток: "
                                            + QString::number(ui->tableWidget->rowCount()));
                }
            }
            else
            {
                QMessageBox notUnique;
                notUnique.setText("Цифры не должны повторяться!");
                notUnique.exec();
            }
        }
    }
    else
    {
        QMessageBox notNum;
        notNum.setText("Вы ввели не число!");
        notNum.exec();
    }
   ///////// ui->lineEdit->clear();
}

void BullsAndCows::readRecords()
{
    QFile input("/Users/test/Documents/2 сем QT projects/BullsAndCows/records.txt");
    if (!input.open(QIODevice::ReadOnly))
    {
        QMessageBox error;
        error.setText("Ошибка при открытии файла рекордов");
        error.exec();
    }
    else
    {
        recordsList.clear();
        while (!input.atEnd())
        {
            char buf[1024];
            qint64 lineLength = input.readLine(buf, sizeof(buf));
            QString temp("");
            tableRecords::record curRecord;
            for (qint64 j = 0; j < lineLength; j++)
                if (buf[j] == ' ')
                {
                    curRecord.attempts = temp.toInt();
                    temp = "";
                }
                else
                {
                    temp += buf[j];
                }
            curRecord.name = temp;
            recordsList.push_back(curRecord);
        }
    }
}

void BullsAndCows::on_records_clicked()
{
    readRecords();
    records.write(recordsList);
    records.show();
}


/*void BullsAndCows::on_records_clicked()
{
   // table = new tableRecords(this);
   // table->show();

}
*/
