#include "gradecalculator.h"
#include "ui_gradecalculator.h"

GradeCalculator::GradeCalculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GradeCalculator)
{
    ui->setupUi(this);

    QObject::connect( ui->HW1Spin,SIGNAL( valueChanged(int) ),
                      this, SLOT( ComputeGrade() )  );
    QObject::connect( ui->HW2Spin,SIGNAL( valueChanged(int) ),
                      this, SLOT( ComputeGrade() ) );


}

GradeCalculator::~GradeCalculator()
{
    delete ui;
}


void GradeCalculator::ComputeGrade() {
    double x1 = ui->HW1Spin->value();
    double x2 = ui->HW2Spin->value();

    QString text(QString::number( x1 + x2 ));
    ui->CalculatedGrade->setText(text);
}
