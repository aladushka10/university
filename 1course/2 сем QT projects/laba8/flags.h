#ifndef FLAGS_H
#define FLAGS_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class flags; }
QT_END_NAMESPACE

class flags : public QMainWindow
{
    Q_OBJECT

public:
    flags(QWidget *parent = nullptr);
    ~flags();
    void paintEvent (QPaintEvent*);
private slots:
    void on_tabWidget_currentChanged(int);

private:
    Ui::flags *ui;

};
#endif // FLAGS_H
