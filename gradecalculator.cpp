#include "gradecalculator.h"
#include "ui_gradecalculator.h"

GradeCalculator::GradeCalculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GradeCalculator)
{
    ui->setupUi(this);

    QObject::connect( ui->HW1Spin,SIGNAL( valueChanged(int) ),
                      this, SLOT( ComputePIC10BGrade() )  );
    QObject::connect( ui->HW2Spin,SIGNAL( valueChanged(int) ),
                      this, SLOT( ComputePIC10BGrade() ) );
    QObject::connect( ui->HW3Spin,SIGNAL( valueChanged(int) ),
                      this, SLOT( ComputePIC10BGrade() )  );
    QObject::connect( ui->HW4Spin,SIGNAL( valueChanged(int) ),
                      this, SLOT( ComputePIC10BGrade() ) );
    QObject::connect( ui->HW5Spin,SIGNAL( valueChanged(int) ),
                      this, SLOT( ComputePIC10BGrade() )  );
    QObject::connect( ui->HWSpin6,SIGNAL( valueChanged(int) ),
                      this, SLOT( ComputePIC10BGrade() ) );
    QObject::connect( ui->HW7Spin,SIGNAL( valueChanged(int) ),
                      this, SLOT( ComputePIC10BGrade() )  );
    QObject::connect( ui->HW8Spin,SIGNAL( valueChanged(int) ),
                      this, SLOT( ComputePIC10BGrade() ) );
    QObject::connect( ui->Midterm1spinBox,SIGNAL( valueChanged(int) ),
                      this, SLOT( ComputePIC10BGrade() )  );
    QObject::connect( ui->Midterm2spinbox,SIGNAL( valueChanged(int) ),
                      this, SLOT( ComputePIC10BGrade() ) );
    QObject::connect( ui->Finalspinbox,SIGNAL( valueChanged(int) ),
                      this, SLOT( ComputePIC10BGrade() ) );
    QObject::connect( ui->SchemaAButton,SIGNAL( clicked() ),
                      this, SLOT( ComputePIC10BGrade() ) );
    QObject::connect( ui->SchemaBButton,SIGNAL( clicked() ),
                      this, SLOT( ComputePIC10BGrade() ) );

    ui->SchemaAButton->setChecked(1);

    QObject::connect( ui->HW1Spin_2,SIGNAL( valueChanged(int) ),
                      this, SLOT( ComputePIC10CGrade() )  );
    QObject::connect( ui->HW2Spin_2,SIGNAL( valueChanged(int) ),
                      this, SLOT( ComputePIC10CGrade() ) );
    QObject::connect( ui->HW3Spin_2,SIGNAL( valueChanged(int) ),
                      this, SLOT( ComputePIC10CGrade() )  );
    QObject::connect( ui->Midterm1spinBox_2,SIGNAL( valueChanged(int) ),
                      this, SLOT( ComputePIC10CGrade() )  );
    QObject::connect( ui->finalProject_spinBox,SIGNAL( valueChanged(int) ),
                      this, SLOT( ComputePIC10CGrade() )  );
    QObject::connect( ui->Finalspinbox_2,SIGNAL( valueChanged(int) ),
                      this, SLOT( ComputePIC10CGrade() ) );
    QObject::connect( ui->SchemaAButton_2,SIGNAL( clicked() ),
                      this, SLOT( ComputePIC10CGrade() ) );
    QObject::connect( ui->SchemaBButton_2,SIGNAL( clicked() ),
                      this, SLOT( ComputePIC10CGrade() ) );

    ui->SchemaAButton_2->setChecked(1);

}

GradeCalculator::~GradeCalculator()
{
    delete ui;
}


void GradeCalculator::ComputePIC10BGrade() {
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
    double overall = 0;

    if (ui->SchemaAButton->isChecked())
        overall = .25*(hw_sum/8) + .2*e1 + .2*e2 + .35*e3;
    if (ui->SchemaBButton->isChecked()) {
        double higher_exam = e1;
        if (e1<e2) higher_exam = e2;
        overall = .25*(hw_sum/8) + .3*higher_exam + .44*e3;
    }
    QString text(QString::number(overall));
    ui->CalculatedGrade->setText(text);
}

void GradeCalculator::ComputePIC10CGrade() {
    double h1 = ui->HW1Spin_2->value();
    double h2 = ui->HW2Spin_2->value();
    double h3 = ui->HW3Spin_2->value();

    double e1 = ui->Midterm1spinBox_2->value();
    double e2 = ui->Finalspinbox_2->value();
    double p = ui->finalProject_spinBox->value();

    double hw_sum = h1+h2+h3;
    double overall = 0;

    if (ui->SchemaAButton_2->isChecked())
        overall = .15*hw_sum/3 + .25*e1 + .3*e2 + .35*p;
    if (ui->SchemaBButton_2->isChecked())
        overall = .13*hw_sum/3 + .5*e2 + .35*p;

    ui->CalculatedGrade_2->setText(QString::number(overall));
}

void GradeCalculator::on_actionQuit_triggered()
{
    close();
}

void GradeCalculator::on_actionReset_triggered()
{
    ui->HW1Spin->setValue(0);
    ui->HW2Spin->setValue(0);
    ui->HW3Spin->setValue(0);
    ui->HW4Spin->setValue(0);
    ui->HW5Spin->setValue(0);
    ui->HWSpin6->setValue(0);
    ui->HW7Spin->setValue(0);
    ui->HW8Spin->setValue(0);
    ui->Midterm1spinBox->setValue(0);
    ui->Midterm2spinbox->setValue(0);
    ui->Midterm1spinBox_2->setValue(0);
    ui->Finalspinbox->setValue(0);
    ui->Finalspinbox_2->setValue(0);
    ui->HW1Spin_2->setValue(0);
    ui->HW2Spin_2->setValue(0);
    ui->HW3Spin_2->setValue(0);
}
