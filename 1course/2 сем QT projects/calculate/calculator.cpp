#include "calculator.h"
#include "ui_calculator.h"

double num1;

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);

    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(digits_numbers()));

    connect(ui->pushButton_plusminus,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_percent,SIGNAL(clicked()),this,SLOT(operations()));

    connect(ui->pushButton_div,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_mul,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_add,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_sub,SIGNAL(clicked()),this,SLOT(math_operations()));

    ui->pushButton_add->setCheckable(true);
    ui->pushButton_sub->setCheckable(true);
    ui->pushButton_mul->setCheckable(true);
    ui->pushButton_div->setCheckable(true);
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::digits_numbers()
{
    QPushButton *button =  (QPushButton *)sender(); //1
    QString value;
    if (ui->result->text().contains(".") && button->text()== "0") //3
        value = ui->result->text() + button->text();
    else {
        double numbers = (ui->result->text() + button->text()).toDouble(); //2
        value = QString::number(numbers,'g',15);
    }
    ui->result->setText(value);
}

void Calculator::on_pushButton_dot_clicked()
{
    if (!(ui->result->text().contains('.')))
        ui->result->setText(ui->result->text()+".");  //1
}

void Calculator::operations()
{
    QPushButton *button =  (QPushButton *)sender(); //1
    double numbers;
    QString value;

    /*    if (button->text()=="+/-") {
        numbers = (ui->result->text()).toDouble();
        numbers = -numbers;
        value = QString::number(numbers,'g',15);
        ui->result->setText(value);
    }
    else if (button->text()=="%") {
        numbers = (ui->result->text()).toDouble();
        numbers = numbers * 0.01;
        value = QString::number(numbers,'g',15);
        ui->result->setText(value);
    }*/

    numbers = (ui->result->text()).toDouble();
    if (button->text()=="+/-") {
        numbers = -numbers;
    }
    else if (button->text()=="%") {
        numbers = numbers * 0.01;
    }
    value = QString::number(numbers,'g',15);
    ui->result->setText(value);
}

void Calculator::math_operations()
{
    QPushButton *button =  (QPushButton *)sender();

    num1 = ui->result->text().toDouble(); //2
    ui->result->setText(""); //3
    button->setChecked(true); //1
}

void Calculator::on_pushButton_AC_clicked()
{
    ui->pushButton_add->setChecked(false);
    ui->pushButton_sub->setChecked(false);
    ui->pushButton_mul->setChecked(false);
    ui->pushButton_div->setChecked(false);

    //   ui->result->clear();
    ui->result->setText("0");
}

void Calculator::on_pushButton_equal_clicked()
{
    double labelNum, num2;
    QString value;

    num2 = ui->result->text().toDouble();

    if (ui->pushButton_add->isChecked())
    {
        labelNum = num1 + num2;
        value = QString::number(labelNum,'g',15);
        ui->result->setText(value);
        ui->pushButton_add->setChecked(false);
    }
    else if (ui->pushButton_sub->isChecked())
    {
        labelNum = num1 - num2;
        value = QString::number(labelNum,'g',15);
        ui->result->setText(value);
        ui->pushButton_sub->setChecked(false);
    }
    else if (ui->pushButton_mul->isChecked())
    {
        labelNum = num1 * num2;
        value = QString::number(labelNum,'g',15);
        ui->result->setText(value);
        ui->pushButton_mul->setChecked(false);
    }
    else if (ui->pushButton_div->isChecked())
    {
        if (num2 == 0)
        {
            ui->result->setText("0");
        }
        else {
            labelNum = num1 / num2;
            value = QString::number(labelNum,'g',15);
            ui->result->setText(value);
        }
        ui->pushButton_div->setChecked(false);
    }
}

