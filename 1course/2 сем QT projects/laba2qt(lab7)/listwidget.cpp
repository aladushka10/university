#include "listwidget.h"
#include "ui_listwidget.h"
#include <QInputDialog>


listWidget::listWidget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::listWidget)
{
    ui->setupUi(this);

    ui->listWidget_1->addItem("макароны");
    ui->listWidget_1->addItem("огурцы");
    ui->listWidget_1->addItem("пончики");
    ui->listWidget_2->addItem("сыр");
    ui->listWidget_2->addItem("лепешка");
    ui->listWidget_2->addItem("рис");
    ui->listWidget_2->addItem("курица");
}

listWidget::~listWidget()
{
    delete ui;
}

void listWidget::on_moveLeft_clicked()
{
    QList<QListWidgetItem *> items = ui->listWidget_2->selectedItems();
    for (auto it = items.begin(); it != items.end(); ++it)
    {
        ui->listWidget_1->addItem((*it)->text());
        delete (*it);
    }
}


void listWidget::on_moveRight_clicked()
{
    QList<QListWidgetItem *> items = ui->listWidget_1->selectedItems();
    for (auto it = items.begin(); it != items.end(); ++it)
    {
        ui->listWidget_2->addItem((*it)->text());
        delete (*it);
    }
}


void listWidget::on_sortLeft_clicked()
{
     ui->listWidget_1->sortItems(Qt::AscendingOrder);
}


void listWidget::on_sortRight_clicked()
{
    ui->listWidget_2->sortItems(Qt::DescendingOrder);
}


void listWidget::on_addLeft_clicked()
{

    QString c_text = QInputDialog::getText(this, "Элемент", "Введите новый элемент");
    QString s_text = c_text.simplified();
    if (!s_text.isEmpty())
    {
         ui->listWidget_1->addItem(s_text);
    }
}


void listWidget::on_addRight_clicked()
{
    QString c_text = QInputDialog::getText(this, "Элемент", "Введите новый элемент");
    QString s_text = c_text.simplified();
    if (!s_text.isEmpty())
    {
         ui->listWidget_2->addItem(s_text);
    }
}


void listWidget::on_editLeft_clicked()
{
    QListWidgetItem *curitem = ui->listWidget_1->currentItem();
    if(curitem != nullptr)
    {
         int r = ui->listWidget_1->row(curitem);
         QString c_text = curitem->text();
         QString r_text = QInputDialog::getText(this, "Элемент", "Введите новый элемент", QLineEdit::Normal, c_text);
         QString s_text = r_text.simplified();
         if (!s_text.isEmpty())
         {
            QListWidgetItem *item = ui->listWidget_1->takeItem(r);
            delete item;
            ui->listWidget_1->insertItem(r, s_text);
            ui->listWidget_1->setCurrentRow(r);
         }
    }
}


void listWidget::on_editRight_clicked()
{
    QListWidgetItem *curitem = ui->listWidget_2->currentItem();
    if(curitem != nullptr)
    {
         int r = ui->listWidget_2->row(curitem);
         QString c_text = curitem->text();
         QString r_text = QInputDialog::getText(this, "Элемент", "Введите новый элемент", QLineEdit::Normal, c_text);
         QString s_text = r_text.simplified();
         if (!s_text.isEmpty())
         {
            QListWidgetItem *item = ui->listWidget_2->takeItem(r);
            delete item;
            ui->listWidget_2->insertItem(r, s_text);
            ui->listWidget_2->setCurrentRow(r);
         }
    }
}


void listWidget::on_clearLeft_clicked()
{
    ui->listWidget_1->clear();
}


void listWidget::on_clearRight_clicked()
{
    ui->listWidget_2->clear();
}


void listWidget::on_deleteLeft_clicked()
{
    QList<QListWidgetItem *> items = ui->listWidget_1->selectedItems();
    for (auto it = items.begin(); it != items.end(); ++it)
    {
         delete (*it);
    }
}


void listWidget::on_deleteRight_clicked()
{
    QList<QListWidgetItem *> items = ui->listWidget_2->selectedItems();
    for (auto it = items.begin(); it != items.end(); ++it)
    {
         delete (*it);
    }
}



void listWidget::on_checkBox_2_clicked()
{
    if(ui->checkBox_2->isChecked())
    {
         ui->listWidget_1->setSelectionMode(QAbstractItemView::MultiSelection);
         ui->listWidget_2->setSelectionMode(QAbstractItemView::MultiSelection);
    }
    else {
         ui->listWidget_1->setSelectionMode(QAbstractItemView::SingleSelection);
         ui->listWidget_2->setSelectionMode(QAbstractItemView::SingleSelection);
    }
}


void listWidget::on_checkBox_clicked()
{
    if(ui->checkBox->isChecked())
    {
         ui->listWidget_1->setViewMode(QListView::IconMode);
         ui->listWidget_2->setViewMode(QListView::IconMode);
    }
    else {
         ui->listWidget_1->setViewMode(QListView::ListMode);
         ui->listWidget_2->setViewMode(QListView::ListMode);
    }
}

