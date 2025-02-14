#ifndef RECORDDIALOG_H
#define RECORDDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>

class RecordDialog : public QDialog
{
    Q_OBJECT
private:
    QLineEdit* m_ptxtName;
public:
    RecordDialog(QWidget* pwgt = 0);
    QString name() const;
};

#endif // RECORDDIALOG_H
