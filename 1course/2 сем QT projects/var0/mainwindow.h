#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QColorDialog>
#include <QRgb>
#include "addelement.h"
#include "diagramitem.h"
#include <vector>
#include <QVBoxLayout>
#include <QtWidgets>
#include <QMainWindow>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    qint32 amount=0;
    QLabel *lbAmount = new QLabel("Amount of elements" + QString::number(amount));

private slots:
    void on_action_triggered();
    void pbInsert_clicked();
    void vectorPushBack(QString tempName, qint32 tempValue, QColor tempColor);
    void recalculate();
    bool eventFilter(QObject *watched, QEvent *event);
    void on_action_2_triggered();
    void setPenWidth();
    void on_action_7_triggered();
    void on_actionClear_triggered();
    void on_actionSave_triggered();
    void on_MainWindow_customContextMenuRequested(const QPoint &/*pos*/);
    void onTaskBoxContextMenuEvent();
    void changeItem(QListWidgetItem *item);
    void repaintList();


    void on_choose1_triggered();

    void on_choose2_triggered();

private:
    bool mode = true;
    QPicture pic;
    QListWidget *lwElements;
    QHBoxLayout *horizontallayout;
    QImage *image;
    QFileDialog *FILE;
    QString str_file;
    QPushButton *OK;
    QLabel *lbPenWidth;
    QDialog *dial;
    QRadioButton *width1;
    QRadioButton *width2;
    QRadioButton *width3;
    QRadioButton *width4;
    QRadioButton *width5;
    QPen pen;
    Ui::MainWindow *ui;
    QPushButton *pbInsert;
    addElement *add;
    std::vector <diagramItem> diagram;
    QWidget *paint;
    QColorDialog *RGB = new QColorDialog;
};
#endif // MAINWINDOW_H
