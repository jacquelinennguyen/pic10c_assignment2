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
    QObject::connect( ui->HW4Spin_2,SIGNAL( valueChanged(int) ),
                      this, SLOT( ComputePIC10CGrade() ) );
    QObject::connect( ui->HW5Spin_2,SIGNAL( valueChanged(int) ),
                      this, SLOT( ComputePIC10CGrade() )  );
    QObject::connect( ui->HWSpin6_2,SIGNAL( valueChanged(int) ),
                      this, SLOT( ComputePIC10CGrade() ) );
    QObject::connect( ui->HW7Spin_2,SIGNAL( valueChanged(int) ),
                      this, SLOT( ComputePIC10CGrade() )  );
    QObject::connect( ui->HW8Spin_2,SIGNAL( valueChanged(int) ),
                      this, SLOT( ComputePIC10CGrade() ) );
    QObject::connect( ui->Midterm1spinBox_2,SIGNAL( valueChanged(int) ),
                      this, SLOT( ComputePIC10CGrade() )  );
    QObject::connect( ui->Midterm2spinbox_2,SIGNAL( valueChanged(int) ),
                      this, SLOT( ComputePIC10CGrade() ) );
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

    if (ui->SchemaAButton->isChecked()) overall = .25*(hw_sum/8) + .2*e1 + .2*e2 + .35*e3;
    if (ui->SchemaBButton->isChecked()) {
        double higher_exam = e1;
        if (e1<e2) higher_exam = e2;
        overall = .25*(hw_sum/8) + .3*higher_exam + .44*e3;
    }
    QString text(QString::number(overall));
    ui->CalculatedGrade->setText(text);
}

void GradeCalculator::ComputePIC10CGrade() {

}
