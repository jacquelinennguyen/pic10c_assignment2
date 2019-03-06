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
    void ComputeGrade();
    //void AssignmentChanged();

};

#endif // GRADECALCULATOR_H
