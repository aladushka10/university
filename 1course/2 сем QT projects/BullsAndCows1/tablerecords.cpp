#include "tablerecords.h"
#include "ui_tablerecords.h"

tableRecords::tableRecords(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tableRecords)
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

tableRecords::~tableRecords()
{
    delete ui;
}

void tableRecords::write(QVector <record>& recordList)
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
/*ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
ui->tableWidget->insertRow(ui->tableWidget->rowCount());
QTableWidgetItem *item1 = new QTableWidgetItem(QString::number(ui->tableWidget->rowCount()));
ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0, item1);
QTableWidgetItem *item2 = new QTableWidgetItem(r_text)
*/
