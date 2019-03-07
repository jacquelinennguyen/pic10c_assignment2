#ifndef GRADECALCULATOR_H
#define GRADECALCULATOR_H

#include <QMainWindow>
#include <QObject>

namespace Ui {
class GradeCalculator;
}

class GradeCalculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit GradeCalculator(QWidget *parent = nullptr);
    ~GradeCalculator();

private:
    Ui::GradeCalculator *ui;

private slots:
    void ComputePIC10BGrade();
    void ComputePIC10CGrade();
    void on_actionQuit_triggered();
    void on_actionReset_triggered();
};

#endif // GRADECALCULATOR_H
