#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(on_timeout()));
    timer->start(100);
}

void MainWindow::on_timeout()
{
    std::string s = "background-color: rgb(";
    int r = rand() % 255;
    int g = rand() % 255;
    int b = rand() % 255;
    s += std::to_string(r) + ", " + std::to_string(g) + ", " + std::to_string(b) + ");";
    this->setStyleSheet(s.c_str());
}

MainWindow::~MainWindow()
{
    delete ui;
}

