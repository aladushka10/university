#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class tic_tac_toe; }
QT_END_NAMESPACE

class tic_tac_toe : public QMainWindow
{
    Q_OBJECT

public:
    tic_tac_toe(QWidget *parent = nullptr);
    ~tic_tac_toe();

private:
    Ui::tic_tac_toe *ui;
    int isEnd();

private slots:
    void setButtonsEnabled(bool);
    void symbols();
    void clear();
    void gameWith();
    void computerClick();
};
#endif // TIC_TAC_TOE_H
