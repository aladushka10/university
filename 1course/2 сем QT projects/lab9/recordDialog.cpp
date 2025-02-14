#include "recordDialog.h"

RecordDialog::RecordDialog(QWidget* pwgt) : QDialog(pwgt, Qt::WindowTitleHint |
                        Qt::WindowSystemMenuHint)
{
    m_ptxtName = new QLineEdit;
    QLabel* plblName = new QLabel("&Name");
    plblName->setBuddy(m_ptxtName);
    QPushButton* pcmdOk = new QPushButton("&Ok");
    QPushButton* pcmdCancel = new QPushButton("&Cancel");
    connect(pcmdOk,SIGNAL(clicked()), SLOT(accept()));
    connect(pcmdCancel,SIGNAL(clicked()), SLOT(reject()));
    QGridLayout* ptopLayout = new QGridLayout;
    ptopLayout->addWidget(plblName, 0, 0);
    ptopLayout->addWidget(m_ptxtName, 0, 1);
    ptopLayout->addWidget(pcmdOk, 1, 0);
    ptopLayout->addWidget(pcmdCancel, 1, 1);
    setLayout(ptopLayout);
}

QString RecordDialog::name() const
{
    return m_ptxtName->text();
}
