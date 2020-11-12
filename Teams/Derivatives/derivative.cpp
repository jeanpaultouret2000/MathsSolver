#include "derivative.h"
#include "ui_derivative.h"

derivative::derivative(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::derivative)
{
    ui->setupUi(this);
}

derivative::~derivative()
{
    delete ui;
}

