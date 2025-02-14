#ifndef ADDELEMENT_H
#define ADDELEMENT_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QFormLayout>
#include <QColor>

namespace Ui {
class addElement;
}

class addElement : public QDialog
{
    Q_OBJECT

public:
    explicit addElement(QWidget *parent = nullptr);
    ~addElement();

private:
    QString addName;
    QColor addColor;
    qint32 addValue;
    Ui::addElement *ui;
    QPushButton *pbOk;
    QFormLayout *layout;
    QLabel *lbName;
    QLabel *lbValue;
    QLineEdit *leName;
    QLineEdit *leValue;
    QPushButton *pbColor;

private slots:
    void leValue_editingFinished();
    void leName_editingFinished();
    void pbColor_clicked();
    void pbOk_clicked();

signals:
    void sendElement(QString, qint32, QColor);
};

#endif // ADDELEMENT_H
