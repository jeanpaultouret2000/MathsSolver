#ifndef DERIVATIVE_H
#define DERIVATIVE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class derivative; }
QT_END_NAMESPACE

class derivative : public QMainWindow
{
    Q_OBJECT

public:
    derivative(QWidget *parent = nullptr);
    ~derivative();

private:
    Ui::derivative *ui;
};
#endif // DERIVATIVE_H
