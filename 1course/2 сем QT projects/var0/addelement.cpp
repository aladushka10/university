#include "addelement.h"
#include "ui_addelement.h"
#include <QPushButton>
#include <QColorDialog>
addElement::addElement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addElement)
{
    ui->setupUi(this);
    layout = new QFormLayout(this);
    lbName = new QLabel("Enter the name of element", this);
    leName = new QLineEdit(this);
    lbValue = new QLabel("Enter the value of element", this);
    leValue = new QLineEdit(this);
    pbOk = new QPushButton("Ok", this);
    pbColor = new QPushButton("Select the color", this);

    layout -> addWidget(lbName);
    layout -> addWidget(leName);
    layout -> addWidget(lbValue);
    layout -> addWidget(leValue);
    layout -> addWidget(pbColor);
    layout -> addWidget(pbOk);

    connect(leValue, SIGNAL(editingFinished()), SLOT(leValue_editingFinished()));
    connect(leName, SIGNAL(editingFinished()), SLOT(leName_editingFinished()));
    connect(pbColor, SIGNAL(clicked()),this, SLOT(pbColor_clicked()));
    connect(pbOk, SIGNAL(clicked()), this, SLOT(pbOk_clicked()));

}

addElement::~addElement()
{
    delete ui;
}

void addElement::leValue_editingFinished()
{
    addValue = leValue->text().toInt();
}

void addElement::leName_editingFinished()
{
    addName = leName->text();
}

void addElement::pbColor_clicked()
{
    addColor = QColorDialog::getColor(Qt::red, this);
}

void addElement::pbOk_clicked()
{
    emit(sendElement(leName->text(),leValue->text().toInt(), addColor));
    hide();
    leName->clear();
    leValue->clear();
}
