#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QObject>
#include <QRandomGenerator>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pen.setWidth(1);
    pen.setStyle(Qt::DashLine);
    brushColor = Qt::red;
    brush.setColor(brushColor);
    paint = new QWidget;
    ui->verticallayout->addWidget(paint);
    this->setMinimumSize(500,500);
    paint->setMinimumSize(400,400);
    paint->installEventFilter(this);
    this->setContextMenuPolicy(Qt::CustomContextMenu);
    QShortcut *shortcut = new QShortcut(QKeySequence("Ctrl+S"), this);
    QObject::connect(shortcut, SIGNAL(activated()), this, SLOT(on_actionSave_as_triggered()));
    QShortcut *shortcut_close = new QShortcut(QKeySequence("Alt+X"), this);
    QObject::connect(shortcut_close, SIGNAL(activated()), this, SLOT(on_actionExit_triggered()));
    QShortcut *shortcut_open =  new QShortcut(QKeySequence("Ctrl+O"), this);
    QObject::connect(shortcut_open, SIGNAL(activated()), this, SLOT(on_actionOpen_triggered()));
    lbName = new QLabel("Кольцевая диограмма");
    lbPenStyle = new QLabel("Стиль пера: dash line");
    lbWidth = new QLabel("Толщина пера: 1px");
    horizontallayout = new QHBoxLayout;
    statusBar()->addWidget(lbName);
    statusBar()->addWidget(lbPenStyle);
    statusBar()->addWidget(lbWidth);
    QRandomGenerator *rnd;
    rnd = QRandomGenerator::global();
    for (int i =0 ; i < 5 ; i ++) {
        int temp = rnd->bounded(0,50);
        vectorPushBack(temp);
    }
    closing = new QAction("Close");
    opening = new QAction("Open");
    ui->menuFile->addAction(closing);
    ui->menuFile->addAction(opening);
    closing->setDisabled(true);
    opening->setDisabled(true);
    connect( closing, SIGNAL(triggered()),this,SLOT(on_actionClose_triggered()));
    connect( opening, SIGNAL(triggered()),this,SLOT(on_actionOpen_triggered()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::vectorPushBack(int tempValue)
{
    diagramItem temp;
    temp.setValue(tempValue);
    diagram.push_back(temp);
    double sum=0;
    for(int i = 0; i<diagram.size();i++) {
        sum+=diagram[i].getValue();
    }
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if (diagram.size()==0) {
        return false;
    }
    recalculate();
    paint->setFixedSize(width()-55,height()-50);
    if (watched == paint && event->type() == QEvent::Paint) {
       QPainter painter;
       painter.begin(paint);
       painter.setPen(pen);
       painter.setBrush(brushColor);
       int last = 0;
       int R = std::min(paint->width()/3,paint->height()/3);
       for(int i = 0; i<diagram.size(); i++) {
            painter.drawPie(paint->width()/2-R ,paint->height()/2 - R , R*2, R*2,last,diagram[i].getAngle());
            last+=diagram[i].getAngle();
       }
       painter.setBrush(Qt::white);
       painter.drawEllipse(paint->width()/2-R*3/4 ,paint->height()/2 - R*3/4, 1.5*R, 1.5*R);
       painter.end();
       return true;
    }
    return false;
}

void MainWindow::recalculate()
{
    if (diagram.size()==0)
        return;
    double sum=0;
    for(int i = 0; i<diagram.size(); i++) {
        sum+=diagram[i].getValue();
    }
    double part = (360*16)/ sum;
    for(int i = 0;i<diagram.size();i++) {
        double temp = diagram[i].getValue();
        diagram[i].setAngle(temp*part);
    }
}


void MainWindow::on_setterBrushColor_triggered()
{
    brushColor = RGB->getColor();
}

void MainWindow::on_setterPenColor_triggered()
{
    pen.setColor(RGB->getColor());
}

void MainWindow::on_pbAbout_triggered()
{
    QMessageBox box;
    box.setWindowTitle("About");
    box.setText("Шпаковский Артем. 15 группа. Вариант 5.");
    box.exec();
}

void MainWindow::on_MainWindow_customContextMenuRequested(const QPoint &/*pos*/)
{
    QMenu *pMenu = new QMenu(this);
    QAction * pNewTask = new QAction (tr ("Изменить толщину пера"), this);
    pNewTask->setData(1);
    pMenu->addAction(pNewTask);
    connect(pNewTask, SIGNAL(triggered()), this, SLOT(onTaskBoxContextMenuEvent()));
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
        context_setPenWidth();
        break;
    default:
        break;
    }
}


void MainWindow::setPenWidth()
{
   if(width1->isChecked()) {
    pen.setWidth(1);
    lbWidth->setText("Толщина пера: 1px");
   }
   if(width2->isChecked()) {
    pen.setWidth(3);
    lbWidth->setText("Толщина пера: 3px");
   }
   if(width3->isChecked()) {
    pen.setWidth(5);
    lbWidth->setText("Толщина пера: 5px");
   }
   delete dial;
}

void MainWindow::context_setPenWidth()
{
    dial = new QDialog;
    dial->setModal(true);
    dial->setWindowTitle("Pen width");
    QVBoxLayout *dialboxV = new QVBoxLayout();
    OK = new QPushButton("OK",dial);
    lbPenWidth = new QLabel("Выберите ширину пера",dial);
    width1 = new QRadioButton("1 px",dial);
    width2 = new QRadioButton("3 px",dial);
    width3 = new QRadioButton("5 px",dial);
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
        }

    OK->resize(100,30);
    dialboxV->addWidget(lbPenWidth);
    dialboxV->addWidget(width1);
    dialboxV->addWidget(width2);
    dialboxV->addWidget(width3);
    dialboxV->addWidget(OK);
    connect(OK,SIGNAL(clicked()),SLOT(setPenWidth()));
    dial->setLayout(dialboxV);
    dial->exec();
}


void MainWindow::on_actionSave_as_triggered()
{
    QPixmap p(paint->size());
    paint->render(&p,QPoint(0,0),paint->rect());
    p.save(FILE->getSaveFileName()+".jpg","jpg");
    closing->setEnabled(true);
    opening->setEnabled(true);
}

void MainWindow::on_actionExit_triggered()
{
    if (diagram.size()==0) {
        return;
    }
    if (QMessageBox::question(this, "Уходите?", "Хотите сохранить изображение?", QMessageBox::Yes | QMessageBox::No) == QMessageBox::No)
        QApplication::quit();
    else {
        on_actionSave_as_triggered();
        QApplication::quit();
    }
}

void MainWindow::closeEvent (QCloseEvent *event) {
    on_actionExit_triggered();
}


void MainWindow::on_actionOpen_triggered()
{

}

void MainWindow::on_actionClose_triggered()
{
    diagram.clear();
    update();
}
