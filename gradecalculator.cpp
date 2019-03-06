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
    QObject::connect( ui->HW3Spin,SIGNAL( valueChanged(int) ),
                      this, SLOT( ComputeGrade() )  );
    QObject::connect( ui->HW4Spin,SIGNAL( valueChanged(int) ),
                      this, SLOT( ComputeGrade() ) );
    QObject::connect( ui->HW5Spin,SIGNAL( valueChanged(int) ),
                      this, SLOT( ComputeGrade() )  );
    QObject::connect( ui->HWSpin6,SIGNAL( valueChanged(int) ),
                      this, SLOT( ComputeGrade() ) );
    QObject::connect( ui->HW7Spin,SIGNAL( valueChanged(int) ),
                      this, SLOT( ComputeGrade() )  );
    QObject::connect( ui->HW8Spin,SIGNAL( valueChanged(int) ),
                      this, SLOT( ComputeGrade() ) );
    QObject::connect( ui->Midterm1spinBox,SIGNAL( valueChanged(int) ),
                      this, SLOT( ComputeGrade() )  );
    QObject::connect( ui->Midterm2spinbox,SIGNAL( valueChanged(int) ),
                      this, SLOT( ComputeGrade() ) );
    QObject::connect( ui->Finalspinbox,SIGNAL( valueChanged(int) ),
                      this, SLOT( ComputeGrade() ) );


}

GradeCalculator::~GradeCalculator()
{
    delete ui;
}


void GradeCalculator::ComputeGrade() {
    double h1 = ui->HW1Spin->value();
    double h2 = ui->HW2Spin->value();
    double h3 = ui->HW3Spin->value();
    double h4 = ui->HW4Spin->value();
    double h5 = ui->HW5Spin->value();
    double h6 = ui->HWSpin6->value();
    double h7 = ui->HW7Spin->value();
    double h8 = ui->HW8Spin->value();

    double e1 = ui->Midterm1spinBox->value();
    double e2 = ui->Midterm2spinbox->value();
    double e3 = ui->Finalspinbox->value();

    double hw_sum = h1+h2+h3+h4+h5+h6+h7+h8;
    double overall = .25*(hw_sum/8) + .2*e1 + .2*e2 + .35*e3;

    QString text(QString::number(overall));
    ui->CalculatedGrade->setText(text);
}
