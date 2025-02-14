#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class listWidget; }
QT_END_NAMESPACE

class listWidget : public QMainWindow
{
    Q_OBJECT

public:
    listWidget(QWidget *parent = nullptr);
    ~listWidget();

private slots:

    void on_moveLeft_clicked();
    void on_moveRight_clicked();
    void on_sortLeft_clicked();
    void on_sortRight_clicked();
    void on_addLeft_clicked();
    void on_addRight_clicked();
    void on_editLeft_clicked();
    void on_editRight_clicked();
    void on_clearLeft_clicked();
    void on_clearRight_clicked();
    void on_deleteLeft_clicked();
    void on_deleteRight_clicked();

    void on_checkBox_2_clicked();

    void on_checkBox_clicked();

private:
    Ui::listWidget *ui;
};
#endif // LISTWIDGET_H
