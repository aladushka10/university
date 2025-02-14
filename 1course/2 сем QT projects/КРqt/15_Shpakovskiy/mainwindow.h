#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QColorDialog>
#include <QRgb>
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
      void vectorPushBack(int tempValue);
      bool eventFilter(QObject *watched, QEvent *event);
      void recalculate();
//    void recalculate();
//    void on_action_2_triggered();
//    void setPenWidth();
//    void on_action_7_triggered();
//    void on_actionClear_triggered();
//    void on_actionSave_triggered();
//    void on_MainWindow_customContextMenuRequested(const QPoint &/*pos*/);
//    void onTaskBoxContextMenuEvent();
//    void repaintList();
//    void on_choose1_triggered();
//    void on_choose2_triggered();
//    void on_actionSave_as_a_file_triggered();
//    void on_loadFile_triggered();

      void on_setterBrushColor_triggered();
      void on_setterPenColor_triggered();
      void on_pbAbout_triggered();
      void on_MainWindow_customContextMenuRequested(const QPoint &/*pos*/);
      void onTaskBoxContextMenuEvent();
      void context_setPenWidth();
      void setPenWidth();
      void closeEvent (QCloseEvent *event);

      void on_actionSave_as_triggered();

      void on_actionClose_triggered();

      void on_actionOpen_triggered();

      void on_actionExit_triggered();

private:
    QAction *closing;
    QAction *opening;
    QLabel *lbWidth;
    QLabel *lbName;
    QLabel *lbPenWidth;
    QLabel *lbPenStyle;
    QBrush brush;
    QColor brushColor;
    int pos = 0;
    bool mode = true;
    QPicture pic;
    QListWidget *lwElements;
    QHBoxLayout *horizontallayout;
    QImage *image;
    QFileDialog *FILE = new QFileDialog;
    QString str_file;
    QPushButton *OK;
    QDialog *dial;
    QRadioButton *width1;
    QRadioButton *width2;
    QRadioButton *width3;
    QPen pen;
    Ui::MainWindow *ui;
    QPushButton *pbInsert;
    std::vector <diagramItem> diagram;
    QWidget *paint;
    QColorDialog *RGB = new QColorDialog;
};
#endif // MAINWINDOW_H
