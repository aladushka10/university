#include "records.h"
#include "ui_records.h"


Records::Records(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::Records)
{
        ui->setupUi(this);
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void Records::write(QVector <record>& recordsList)
{
        while (ui->tableWidget->rowCount())
            ui->tableWidget->removeRow(0);
        for (int i = 0; i < recordsList.size(); i++)
        {
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
            QTableWidgetItem *item1 = new QTableWidgetItem(QString::number(recordsList[i].attempts));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0, item1);
            QTableWidgetItem *item2 = new QTableWidgetItem(recordsList[i].name);
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 1, item2);
        }
}

Records::~Records()
{
        delete ui;
}
