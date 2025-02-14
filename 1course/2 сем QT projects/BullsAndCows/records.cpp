#include "records.h"
#include "ui_records.h"

Records::Records(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Records)
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void Records::write(QVector <record>& recordList)
{
    while(ui->tableWidget->rowCount())
        ui->tableWidget->removeRow(0);
    for (int i = 0; i < recordList.size(); i++)
    {
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        QTableWidgetItem *item1 = new QTableWidgetItem(QString::number(recordList[i].attempts));
        ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0, item1);
        QTableWidgetItem *item2 = new QTableWidgetItem(recordList[i].name);
        ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 1, item2);
    }
}

Records::~Records()
{
    delete ui;
}
