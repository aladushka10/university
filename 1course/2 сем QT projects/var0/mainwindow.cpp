#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>
#include <QPushButton>
#include <QDebug>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    add = new addElement;
    paint = new QWidget;
    lwElements = new QListWidget;
    pbInsert = new QPushButton("Add new element",this);
    horizontallayout = new QHBoxLayout;
    image = new QImage;
    lbAmount = new QLabel("Amount of elements: "+QString::number(amount));
    this->setMinimumSize(500,500);
    paint->setMinimumSize(400,400);
    horizontallayout->addWidget(paint);
    horizontallayout->addWidget(lwElements);
    ui->verticallayout->addLayout(horizontallayout);

    ui->verticallayout->addWidget(pbInsert);
    paint->installEventFilter(this);

    connect(pbInsert, SIGNAL(clicked()), SLOT(pbInsert_clicked()));
    connect(add, SIGNAL(sendElement(QString, qint32, QColor)), this, SLOT(vectorPushBack(QString, qint32, QColor)));
    connect(lwElements, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(changeItem(QListWidgetItem*)));
    vectorPushBack("test1", 500, Qt::blue);
    vectorPushBack("test2", 500, Qt::red);
    statusBar()->addWidget(lbAmount);
    this->setContextMenuPolicy(Qt::CustomContextMenu);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_action_triggered()
{

}

void MainWindow::pbInsert_clicked()
{
    add->show();
}

void MainWindow::vectorPushBack(QString tempName, qint32 tempValue, QColor tempColor)
{
    diagramItem temp;
    temp.setName(tempName);
    temp.setValue(tempValue);
    temp.setColor(tempColor);
    diagram.push_back(temp);
    double sum=0;
    for(int i = 0; i<diagram.size();i++) {
        sum+=diagram[i].getValue();
    }
    lwElements->clear();
    repaintList();
}

void MainWindow::recalculate()
{
    double sum=0;
    for(int i = 0; i<diagram.size(); i++) {
        sum+=diagram[i].getValue();
    }
    double part = (360*16)/ sum;
    for(int i = 0;i<diagram.size();i++) {
        double temp = diagram[i].getValue();
        diagram[i].setAngle(temp*part);
    }
    int big = 0;
    for(int i = 0; i<diagram.size(); i++) {
        if(big <= diagram[i].getValue()) {
            big = diagram[i].getValue();
            }
        }
    part = (paint->height()-40)/(double)big;
    int width = (paint->width()/diagram.size())/2;
    for (int i = 0; i < diagram.size(); i++) {
        diagram[i].setSize(width,diagram[i].getValue()*part);
    }
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    //new
    recalculate();
    paint->setFixedSize(width()-55,height()-50);
    lbAmount->setText("Amount of elements: "+QString::number(diagram.size()));
    if (watched == paint && event->type() == QEvent::Paint) {
        if(mode) {
            QPainter painter;
            painter.begin(paint);
            painter.setPen(pen);
            int last = 0;
            int R = std::min(paint->width()/3,paint->height()/3);
            for(int i = 0; i<diagram.size(); i++) {
                painter.setBrush(diagram[i].getColor());
                painter.drawPie(paint->width()/2-R ,paint->height()/2 - R , R*2, R*2,last,diagram[i].getAngle());
                last+=diagram[i].getAngle();
            }
            painter.end();
        } else {
            QPainter painter;
            painter.begin(paint);
            painter.setPen(pen);
            int last = 0;
            int R = std::min(paint->width()/3,paint->height()/3);
            for(int i = 0; i < diagram.size(); i++) {
                painter.setBrush(diagram[i].getColor());
                int bottom = paint->height() - 80;
                painter.drawRect(20+last,bottom - diagram[i].getSizeV(),diagram[i].getSizeH(),diagram[i].getSizeV());
                last+=diagram[i].getSizeH() + diagram[i].getSizeH()/2;
            }
             painter.end();
          }
        if (!pic.save("myline.dat"))
        qDebug() << "can not save the file";
        return true;
    }
    return false;
}


void MainWindow::on_action_2_triggered()
{
    pen.setColor(RGB->getColor());
}

void MainWindow::on_action_7_triggered()
{
    dial = new QDialog;
    dial->setModal(true);
    QVBoxLayout *dialboxV = new QVBoxLayout();
    OK = new QPushButton("OK",dial);
    lbPenWidth = new QLabel("Выберите ширину пера",dial);
    width1 = new QRadioButton("1 px",dial);
    width2 = new QRadioButton("3 px",dial);
    width3 = new QRadioButton("5 px",dial);
    width4 = new QRadioButton("10 px",dial);
    width5 = new QRadioButton("20 px",dial);
    switch(pen.width())
      {
        case 1:
            width1->setChecked(1);
            break;
        case 3:
            width2->setChecked(1);
            break;
        case 5:
            width3->setChecked(1);
            break;
        case 10:
            width4->setChecked(1);
            break;
        case 20:
            width5->setChecked(1);
            break;
        }

        OK->resize(100,30);
        dialboxV->addWidget(lbPenWidth);
        dialboxV->addWidget(width1);
        dialboxV->addWidget(width2);
        dialboxV->addWidget(width3);
        dialboxV->addWidget(width4);
        dialboxV->addWidget(width5);
        dialboxV->addWidget(OK);
        connect(OK,SIGNAL(clicked()),SLOT(setPenWidth()));
        dial->setLayout(dialboxV);
        dial->exec();
}

void MainWindow::setPenWidth()
{
   if(width1->isChecked())
    pen.setWidth(1);
   if(width2->isChecked())
    pen.setWidth(3);
   if(width3->isChecked())
    pen.setWidth(5);
   if(width4->isChecked())
    pen.setWidth(10);
   if(width5->isChecked())
    pen.setWidth(20);
   delete dial;
}

void MainWindow::on_actionClear_triggered()
{
    diagram.clear();
    lwElements->clear();
    update();
}

void MainWindow::on_actionSave_triggered()
{
    if (!pic.save("myline.dat")) {
    qDebug() << "can not save the file";
    pic.save("myline.dat");
    }
    qDebug()<<"function is called";
}

void MainWindow::on_MainWindow_customContextMenuRequested(const QPoint &/*pos*/)
{
    QMenu *pMenu = new QMenu(this);
    QAction * pNewTask = new QAction (tr ("Изменить толщину пера"), this);
    QAction * pEditTask = new QAction (tr ("Изменить цвет пера"), this);
    pNewTask->setData(1);
    pEditTask->setData(2);
    pMenu->addAction(pNewTask);
    pMenu->addAction(pEditTask);
    connect(pNewTask, SIGNAL(triggered()), this, SLOT(onTaskBoxContextMenuEvent()));
    connect(pEditTask, SIGNAL(triggered()), this, SLOT(onTaskBoxContextMenuEvent()));
    pMenu->exec(cursor().pos());
    QList<QAction*> list = pMenu->actions();
    foreach (QAction* pAction, list) delete pAction;
    delete pMenu;
}
void MainWindow::onTaskBoxContextMenuEvent()
{
    QAction * pEven = qobject_cast <QAction *> (this-> sender ());
    int iType = pEven->data().toInt();
    switch (iType)
    {
    case 1:
        on_action_7_triggered();
        break;
    case 2:
        on_action_2_triggered();
        break;
    default:
        break;
    }
}

void MainWindow::changeItem(QListWidgetItem *item)
{
    int k = lwElements->currentRow();
    diagram[k].setColor(QColorDialog::getColor(diagram[k].getColor(), this));
    repaintList();
}

void MainWindow::repaintList()
{
    double sum = 0;
    for(int i = 0; i<diagram.size();i++) {
        sum+=diagram[i].getValue();
    }
    lwElements->clear();
    if (mode) {
    for(int i = 0;i<diagram.size();i++) {
        QString temp="";
        temp+=diagram[i].getName()+" - ";
        temp+=QString::number(round(diagram[i].getValue()*100/sum))+"%";
        QListWidgetItem *item = new QListWidgetItem(temp);
        item->setForeground(diagram[i].getColor());
        lwElements->addItem(item);
    }
    } else {
        for(int i = 0;i<diagram.size();i++) {
            QString temp="";
            temp+=diagram[i].getName()+" - ";
            temp+=QString::number(diagram[i].getValue());
            QListWidgetItem *item = new QListWidgetItem(temp);
            item->setForeground(diagram[i].getColor());
            lwElements->addItem(item);
        }
}
}

void MainWindow::on_choose1_triggered()
{
    mode = true;
    repaintList();
    update();
}

void MainWindow::on_choose2_triggered()
{
    mode = false;
    repaintList();
    update();
}
