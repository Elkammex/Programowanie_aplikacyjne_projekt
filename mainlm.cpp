#include "mainlm.h"
#include "ui_mainlm.h"
//#include <QtCore>
//#include <QtGui>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

MainLM::MainLM(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainLM)
{
    ui->setupUi(this);
    ui->Rosnie->setVisible(false);
    ui->Maleje->setVisible(false);
    ui->Rosnie->setChecked(true); //aby pozbyć się okienka "error"
    ui->Sortlabel->setVisible(false);

}

MainLM::~MainLM()
{
    delete ui;
}

Zawodnik::Zawodnik(QString n, QString nd, QString pz, QString w, QString wz, QString war)
{
    nazwa=n;
    wiek=w;
    narodowosc=nd;
    pozycja=pz;
    wzrost=wz;
    wartosc=war;


}

Zawodnik::~Zawodnik()
{
    //cout<<"destruktor";
}

Zawodnik z1;
Zawodnik z2;
Zawodnik z3;


void MainLM::read()
{
    QFile file("C:/Users/EL_kammex/Documents/LM/zaw.txt");
        if (!file.open(QFile::ReadOnly | QFile::Text))
        {return;}

        QTextStream in(&file);

            QString zaw1 = in.readLine();  QString zaw2 = in.readLine(); QString zaw3 = in.readLine();
            QStringList list1 = zaw1.split(" "); QStringList list2 = zaw2.split(" "); QStringList list3 = zaw3.split(" ");

            z1.nazwa = list1[0];        z2.nazwa = list2[0];         z3.nazwa = list3[0];
            z1.narodowosc=list1[1];     z2.narodowosc=list2[1];      z3.narodowosc=list3[1];
            z1.pozycja=list1[2];        z2.pozycja=list2[2];         z3.pozycja=list3[2];
            z1.wiek=list1[3];           z2.wiek=list2[3];            z3.wiek=list3[3];
            z1.wzrost=list1[4];         z2.wzrost=list2[4];          z3.wzrost=list3[4];
            z1.wartosc=list1[5];        z2.wartosc=list2[5];         z3.wartosc=list3[5];

            Zawodnik z1(list1[0],list1[1],list1[2],list1[3],list1[4],list1[5]);
            Zawodnik z2(list2[0],list2[1],list2[2],list2[3],list2[4],list2[5]);
            Zawodnik z3(list3[0],list3[1],list3[2],list3[3],list3[4],list3[5]);

        file.flush();
        file.close();

}



int MainLM::bubblesortR(QString x,QString y,QString z)
{
    int tab[3];
     tab[0]=x.toInt();
     tab[1]=y.toInt();
     tab[2]=z.toInt();
    int p,k;
    for(int j=0; j<3; j++)
     {
         for(int i=0; i<3; i++)
             {
                 if(tab[i]<tab[i+1]){}
                 else if(i+1<3)
                 {
                     p=tab[i+1];
                     k=tab[i];
                     tab[i+1]=k;
                     tab[i]=p;
                 }
             }

     }

    return tab[2];


}

int MainLM::bubblesortM(QString x,QString y,QString z)
{

    int tab[3];

     tab[0]=x.toInt();
     tab[1]=y.toInt();
     tab[2]=z.toInt();
    int p,k;
    for(int j=0; j<3; j++)
     {
         for(int i=0; i<3; i++)
             {
                 if(tab[i]<tab[i+1]){}
                 else if(i+1<3)
                 {
                     p=tab[i+1];
                     k=tab[i];
                     tab[i+1]=k;
                     tab[i]=p;
                 }
             }

     }


    return tab[0];
}




void MainLM::on_pushButton_clicked()
{
    read();

    if(ui->Maleje->checkState() == Qt::Unchecked && ui->Rosnie->checkState() == Qt::Unchecked)
    {
        QMessageBox::information(this,"error","no checkbox was pressed");
    }


    if(ui->Wiekbutton->isChecked())          //wieksort
    {
        if(ui->Rosnie->isChecked())
        {
          //sort(z1.wiek,z2.wiek,z3.wiek);
           ui->Line->setText(QString::number(bubblesortR(z1.wiek,z2.wiek,z3.wiek)));
           if(bubblesortR(z1.wiek,z2.wiek,z3.wiek)==z1.wiek) ui->Line2->setText(z1.nazwa);
           else if(bubblesortR(z1.wiek,z2.wiek,z3.wiek)==z2.wiek) ui->Line2->setText(z2.nazwa);
           else ui->Line2->setText(z3.nazwa);
        }

        else if(ui->Maleje->isChecked())
        {
            ui->Line->setText(QString::number(bubblesortM(z1.wiek,z2.wiek,z3.wiek)));
            if(bubblesortM(z1.wiek,z2.wiek,z3.wiek)==z1.wiek) ui->Line2->setText(z1.nazwa);
            else if(bubblesortM(z1.wiek,z2.wiek,z3.wiek)==z2.wiek) ui->Line2->setText(z2.nazwa);
            else ui->Line2->setText(z3.nazwa);
        }

    }

    //wzrostsort
    if(ui->Wzrbutton->isChecked())
    {
        if(ui->Rosnie->isChecked())
        {
          //sort(z1.wiek,z2.wiek,z3.wiek);
           ui->Line->setText(QString::number(bubblesortR(z1.wzrost,z2.wzrost,z3.wzrost)));
           if(bubblesortR(z1.wzrost,z2.wzrost,z3.wzrost)==z1.wzrost) ui->Line2->setText(z1.nazwa);
           else if(bubblesortR(z1.wzrost,z2.wzrost,z3.wzrost)==z2.wzrost) ui->Line2->setText(z2.nazwa);
           else ui->Line2->setText(z3.nazwa);
        }

        else if(ui->Maleje->isChecked())
        {
            ui->Line->setText(QString::number(bubblesortM(z1.wzrost,z2.wzrost,z3.wzrost)));
            if(bubblesortM(z1.wzrost,z2.wzrost,z3.wzrost)==z1.wzrost) ui->Line2->setText(z1.nazwa);
            else if(bubblesortM(z1.wzrost,z2.wzrost,z3.wzrost)==z2.wzrost) ui->Line2->setText(z2.nazwa);
            else ui->Line2->setText(z3.nazwa);
        }

    }

    //cenasort
    if(ui->Cenabutton->isChecked())
    {

        if(ui->Rosnie->isChecked())
        {
          //sort(z1.wiek,z2.wiek,z3.wiek);
           ui->Line->setText(QString::number(bubblesortR(z1.wartosc,z2.wartosc,z3.wartosc)));
           if(bubblesortR(z1.wartosc,z2.wartosc,z3.wartosc)==z1.wartosc) ui->Line2->setText(z1.nazwa);
           else if(bubblesortR(z1.wartosc,z2.wartosc,z3.wartosc)==z2.wartosc) ui->Line2->setText(z2.nazwa);
           else ui->Line2->setText(z3.nazwa);
        }

        else if(ui->Maleje->isChecked())
        {
            ui->Line->setText(QString::number(bubblesortM(z1.wartosc,z2.wartosc,z3.wartosc)));
            if(bubblesortM(z1.wartosc,z2.wartosc,z3.wartosc)==z1.wartosc) ui->Line2->setText(z1.nazwa);
            else if(bubblesortM(z1.wartosc,z2.wartosc,z3.wartosc)==z2.wartosc) ui->Line2->setText(z2.nazwa);
            else ui->Line2->setText(z3.nazwa);
        }

    }

    //narodowosc
    if(ui->ndbutton->isChecked())
    {
       //ui->Line->setText("");
       ui->Line2->setText(z1.nazwa+", "+z2.nazwa+", "+z3.nazwa);
       ui->Line->setText(z1.narodowosc+", "+z2.narodowosc+", "+z3.narodowosc);

    }

    //Pozycja
    if(ui->pzbutton->isChecked())
    {
       //ui->Line->setText("");
       ui->Line2->setText(z1.nazwa+", "+z2.nazwa+", "+z3.nazwa);
       ui->Line->setText(z1.pozycja+", "+z2.pozycja+", "+z3.pozycja);

    }




}


void MainLM::on_Wiekbutton_clicked()
{
    ui->Sortlabel->setVisible(true);
    ui->Line->setText("");
    ui->Line2->setText("");
    ui->Rosnie->setChecked(false);
    ui->Maleje->setChecked(false);
    ui->Rosnie->setVisible(true);
    ui->Maleje->setVisible(true);
}


void MainLM::on_Maleje_clicked(bool)
{
    ui->Line->setText("");
    ui->Line2->setText("");
    ui->Rosnie->setChecked(false);
}

void MainLM::on_Rosnie_clicked(bool)
{
    ui->Line->setText("");
    ui->Line2->setText("");
    ui->Maleje->setChecked(false);
}

void MainLM::on_pzbutton_clicked(bool)
{
    ui->Sortlabel->setVisible(false);
    ui->Line->setText("");
    ui->Line2->setText("");
    ui->Rosnie->setChecked(true);
    ui->Rosnie->setVisible(false);
    ui->Maleje->setVisible(false);
}

void MainLM::on_ndbutton_clicked(bool)
{
    ui->Sortlabel->setVisible(false);
    ui->Line->setText("");
    ui->Line2->setText("");
    ui->Rosnie->setChecked(true);
    ui->Rosnie->setVisible(false);
    ui->Maleje->setVisible(false);
}

void MainLM::on_Wzrbutton_clicked(bool)
{
    ui->Sortlabel->setVisible(true);
    ui->Line->setText("");
    ui->Line2->setText("");
    ui->Rosnie->setChecked(false);
    ui->Maleje->setChecked(false);
    ui->Rosnie->setVisible(true);
    ui->Maleje->setVisible(true);
}

void MainLM::on_Cenabutton_clicked(bool)
{
    ui->Sortlabel->setVisible(true);
    ui->Line->setText("");
    ui->Line2->setText("");
    ui->Rosnie->setChecked(false);
    ui->Maleje->setChecked(false);
    ui->Rosnie->setVisible(true);
    ui->Maleje->setVisible(true);
}


