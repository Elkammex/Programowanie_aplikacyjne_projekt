#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QMessageBox>
//#include <QtCore>
//#include <QtGui>
//#include <QList>
#include <QVector>
#include <QTime>
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->solo->setVisible(false);
    ui->duo->setVisible(false);
    wp = ui->lab1->width();
    hp = ui->lab1->height();
    wt = ui->turalabel->width();
    ht = ui->turalabel->height();
    czyjatura='n';
    //QLabel *labtab[9]={ui->p1,ui->p2,ui->p3,ui->p4,ui->p5,ui->p6,ui->p7,ui->p8,ui->p9};

    QVector<QLabel*> label; label <<ui->turagracza << ui->lab1 << ui->lab2 << ui->lab3 << ui->lab4 << ui-> lab5 << ui->lab6 << ui->lab7 << ui->lab8 << ui->lab9
                                    << ui->lab10 << ui->lab11 << ui->lab12 << ui->lab13 << ui-> lab14 << ui->lab15 << ui->lab16 << ui->lab17 << ui->lab18
                                    << ui->lab19 << ui->lab20 << ui->lab21 << ui->lab22 << ui-> lab23 << ui->lab24 << ui->lab25;

    QVector<QPushButton*> button; button << ui->nowagra << ui->b1 << ui->b2 << ui->b3 << ui->b4 << ui-> b5 << ui->b6 << ui->b7 << ui->b8 << ui->b9
                                         << ui->b10 << ui->b11 << ui->b12 << ui->b13 << ui-> b14 << ui->b15 << ui->b16 << ui->b17 << ui->b18
                                         << ui->b19 << ui->b20 << ui->b21 << ui->b22 << ui-> b23 << ui->b24 << ui->b25;


    //QPixmap pole= QPixmap(":/pliki/obrazki/pole.png");    
    xpole=xpole.scaled(wp,hp,Qt::KeepAspectRatio);
    pole=pole.scaled(wp,hp,Qt::KeepAspectRatio);    
    opole=opole.scaled(wp,hp,Qt::KeepAspectRatio);    
    pt=pt.scaled(wt,ht,Qt::KeepAspectRatio);    
    xtura=xtura.scaled(wt,ht,Qt::KeepAspectRatio);
    otura=otura.scaled(wt,ht,Qt::KeepAspectRatio);

    //foreach (QLabel *label, findChildren<QLabel*>())
    //{label->setPixmap(pole); }

    for(int i=1; i<26; i++)
    {
        label[i]->setPixmap(pole);
        button[i]->setVisible(false);
    }
    ui->turalabel->setPixmap(pt);

}

void MainWindow::delay()
{
    QTime dieTime= QTime::currentTime().addSecs(2);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

//funkcja dla 1 gracza
void MainWindow::bot(char pk[])
{
    for(int i=1; i<26; i++)
    {
        button[i]->setEnabled(false);
    }

    delay();
    koniec=0;

   for(int i=1;i<26;i++)
   {
       // blokowanie srodka
       if(pk[i]=='x'&&pk[i+2]=='x'&&pk[i+1]=='n') {pk[i+1]='o'; label[i+1]->setPixmap(opole);button[i+1]->setVisible(false);koniec=1;break;}
       else if(pk[i]=='x'&&pk[i-2]=='x'&&pk[i-1]=='n') {pk[i-1]='o';label[i-1]->setPixmap(opole);button[i-1]->setVisible(false);koniec=1;break;}
       else if(pk[i]=='x'&&pk[i+10]=='x'&&pk[i+5]=='n') {pk[i+5]='o';label[i+5]->setPixmap(opole);button[i+5]->setVisible(false);koniec=1;break;}
       else if(pk[i]=='x'&&pk[i-10]=='x'&&pk[i-5]=='n') {pk[i-5]='o';label[i-5]->setPixmap(opole);button[i-1]->setVisible(false);koniec=1;break;}
       else if(pk[i]=='x'&&pk[i+12]=='x'&&pk[i+6]=='n') {pk[i+6]='o';label[i+6]->setPixmap(opole);button[i+6]->setVisible(false);koniec=1;break;}
       else if(pk[i]=='x'&&pk[i-12]=='x'&&pk[i-6]=='n') {pk[i-6]='o';label[i-6]->setPixmap(opole);button[i-1]->setVisible(false);koniec=1;break;}
       else if(pk[i]=='x'&&pk[i+8]=='x'&&pk[i+4]=='n') {pk[i+4]='o';label[i+4]->setPixmap(opole);button[i+4]->setVisible(false);koniec=1;break;}
       else if(pk[i]=='x'&&pk[i-8]=='x'&&pk[i-4]=='n') {pk[i-4]='o';label[i-4]->setPixmap(opole);button[i-4]->setVisible(false);koniec=1;break;}
   }

   if(koniec==0)
   {
        // blokowanie pojedynczych x
        for(int i=1;i<26;i++)
        {

           if((pk[i]=='x'&&pk[i+1]=='n') || (pk[i]=='x'&&pk[i-1]=='n') || (pk[i]=='x'&&pk[i+5]=='n') || (pk[i]=='x'&&pk[i-5]=='n') ||
              (pk[i]=='x'&&pk[i+6]=='n') || (pk[i]=='x'&&pk[i-6]=='n') || (pk[i]=='x'&&pk[i+4]=='n') || (pk[i]=='x'&&pk[i-4]=='n'))
           {

                    for(int j=1; j<3; j++)
                    {
                           quint32 random = QRandomGenerator::global()->bounded(1,9);
                           if(random==1&&pk[i+1]=='n')
                           {
                               pk[i+1]='o';
                               label[i+1]->setPixmap(opole);
                               button[i+1]->setVisible(false);
                               koniec=1;
                               break;
                           }

                           else if(random==2&&pk[i-1]=='n')
                           {
                               pk[i-1]='o';
                               label[i-1]->setPixmap(opole);
                               button[i-1]->setVisible(false);
                               koniec=1;
                               break;
                           }

                           else if(random==3&&pk[i+5]=='n')
                           {
                               pk[i+5]='o';
                               label[i+5]->setPixmap(opole);
                               button[i+5]->setVisible(false);
                               koniec=1;
                               break;
                           }

                           else if(random==4&&pk[i-5]=='n')
                           {
                               pk[i-5]='o';
                               label[i-5]->setPixmap(opole);
                               button[i-5]->setVisible(false);
                               koniec=1;
                               break;
                           }

                           else if(random==5&&pk[i+6]=='n')
                           {
                               pk[i+6]='o';
                               label[i+6]->setPixmap(opole);
                               button[i+6]->setVisible(false);
                               koniec=1;
                               break;
                           }

                           else if(random==6&&pk[i-6]=='n')
                           {
                               pk[i-6]='o';
                               label[i-6]->setPixmap(opole);
                               button[i-6]->setVisible(false);
                               koniec=1;
                               break;
                           }

                           else if(random==7&&pk[i+4]=='n')
                           {
                               pk[i+4]='o';
                               label[i+4]->setPixmap(opole);
                               button[i+4]->setVisible(false);
                               koniec=1;
                               break;
                           }

                           else if(random==8&&pk[i-4]=='n')
                           {
                               pk[i-4]='o';
                               label[i-4]->setPixmap(opole);
                               button[i-4]->setVisible(false);
                               koniec=1;
                               break;
                           }

                    }


           }


        if(koniec==1) break;

        }

  }

   for(int i=1; i<26; i++)
   {
       button[i]->setEnabled(true);
   }
    ui->turalabel->setPixmap(xtura);
}


void MainWindow::who(char pk[])
{

    for(int i=1,j=1,u=5,k=1; i<4; i++,j=j+5,k=k+6,u=u+4)
    {
      if( (pk[i]=='x'&&pk[i+1]=='x'&&pk[i+2]=='x') || (pk[i+5]=='x'&&pk[i+6]=='x'&&pk[i+7]=='x') || (pk[i+10]=='x'&&pk[i+11]=='x'&&pk[i+12]=='x') ||//poziomo
          (pk[i+15]=='x'&&pk[i+16]=='x'&&pk[i+17]=='x') || (pk[i+20]=='x'&&pk[i+21]=='x'&&pk[i+22]=='x') ||
          (pk[j]=='x'&&pk[j+5]=='x'&&pk[j+10]=='x') || (pk[j+1]=='x'&&pk[j+6]=='x'&&pk[j+11]=='x') || (pk[j+2]=='x'&&pk[j+7]=='x'&&pk[j+12]=='x') ||//pionowo
          (pk[j+3]=='x'&&pk[j+8]=='x'&&pk[j+13]=='x') || (pk[j+4]=='x'&&pk[j+9]=='x'&&pk[j+14]=='x') ||
          (pk[k]=='x'&&pk[k+6]=='x'&&pk[k+12]=='x') || (pk[u]=='x'&&pk[u+4]=='x'&&pk[u+8]=='x') || //ukosnie
          (pk[11]=='x'&&pk[17]=='x'&&pk[23]=='x') || (pk[3]=='x'&&pk[9]=='x'&&pk[15]=='x') || (pk[6]=='x'&&pk[12]=='x'&&pk[18]=='x') ||
          (pk[12]=='x'&&pk[18]=='x'&&pk[24]=='x') || (pk[2]=='x'&&pk[8]=='x'&&pk[14]=='x') || (pk[8]=='x'&&pk[14]=='x'&&pk[20]=='x') ||
          (pk[15]=='x'&&pk[19]=='x'&&pk[23]=='x') || (pk[3]=='x'&&pk[7]=='x'&&pk[11]=='x') || (pk[4]=='x'&&pk[8]=='x'&&pk[12]=='x') ||
          (pk[8]=='x'&&pk[12]=='x'&&pk[16]=='x') || (pk[10]=='x'&&pk[14]=='x'&&pk[18]=='x') || (pk[14]=='x'&&pk[18]=='x'&&pk[22]=='x'))


        {
            QMessageBox::about(this,"Koniec Gry!","Wygrał gracz: KRZYŻYK!        ");
            ui->restart->setEnabled(false);
            for(int i=1; i<26; i++)
            {
                label[i]->setPixmap(pole);
                button[i]->setVisible(false);
            }

            ui->turalabel->setPixmap(pt);
            ui->solo->setVisible(false);
            ui->duo->setVisible(false);
            ui->solo->setChecked(false);
            ui->duo->setChecked(false);
            break;


        }

    else if( (pk[i]=='o'&&pk[i+1]=='o'&&pk[i+2]=='o') || (pk[i+5]=='o'&&pk[i+6]=='o'&&pk[i+7]=='o') || (pk[i+10]=='o'&&pk[i+11]=='o'&&pk[i+12]=='o') ||//poziomo
             (pk[i+15]=='o'&&pk[i+16]=='o'&&pk[i+17]=='o') || (pk[i+20]=='o'&&pk[i+21]=='o'&&pk[i+22]=='o') ||
             (pk[j]=='o'&&pk[j+5]=='o'&&pk[j+10]=='o') || (pk[j+1]=='o'&&pk[j+6]=='o'&&pk[j+11]=='o') || (pk[j+2]=='o'&&pk[j+7]=='o'&&pk[j+12]=='o') ||//pionowo
             (pk[j+3]=='o'&&pk[j+8]=='o'&&pk[j+13]=='o') || (pk[j+4]=='o'&&pk[j+9]=='o'&&pk[j+14]=='o') ||
             (pk[k]=='o'&&pk[k+6]=='o'&&pk[k+12]=='o') || (pk[u]=='o'&&pk[u+4]=='o'&&pk[u+8]=='o') || //ukosnie
             (pk[11]=='o'&&pk[17]=='o'&&pk[23]=='o') || (pk[3]=='o'&&pk[9]=='o'&&pk[15]=='o') || (pk[6]=='o'&&pk[12]=='o'&&pk[18]=='o') ||
             (pk[12]=='o'&&pk[18]=='o'&&pk[24]=='o') || (pk[2]=='o'&&pk[8]=='o'&&pk[14]=='o') || (pk[8]=='o'&&pk[14]=='o'&&pk[20]=='o') ||
             (pk[15]=='o'&&pk[19]=='o'&&pk[23]=='o') || (pk[3]=='o'&&pk[7]=='o'&&pk[11]=='o') || (pk[4]=='o'&&pk[8]=='o'&&pk[12]=='o') ||
             (pk[8]=='o'&&pk[12]=='o'&&pk[16]=='o') || (pk[10]=='o'&&pk[14]=='o'&&pk[18]=='o') || (pk[14]=='o'&&pk[18]=='o'&&pk[22]=='o'))

        {
            QMessageBox::about(this,"Koniec Gry!","Wygrał gracz: KÓŁKO!        ");
            ui->restart->setEnabled(false);
            for(int i=1; i<26; i++)
            {
                label[i]->setPixmap(pole);
                button[i]->setVisible(false);
            }

            ui->turalabel->setPixmap(pt);
            ui->solo->setVisible(false);
            ui->duo->setVisible(false);
            ui->solo->setChecked(false);
            ui->duo->setChecked(false);
            break;

        }
    }

}



MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_nowagra_clicked()
{
    ui->solo->setVisible(true);
    ui->duo->setVisible(true);
    ui->solo->setEnabled(true);
    ui->duo->setEnabled(true);
    ui->solo->setChecked(false);
    ui->duo->setChecked(false);
    //ui->restart->clicked(false);

}

void MainWindow::on_restart_clicked()
{
    for(int i=1;i<26;i++)
    {
        pk[i]='n';
        label[i]->setPixmap(pole);
        button[i]->setVisible(true);
        button[i]->setCursor(Qt::PointingHandCursor);
    }

    ui->turalabel->setPixmap(xtura);
    czyjatura='x';
}

void MainWindow::on_duo_clicked()
{
    //ui->onep->setVisible(false);
    //ui->twop->setVisible(false);
    ui->solo->setEnabled(false);
    ui->duo->setEnabled(false);
    ui->turalabel->setPixmap(xtura);
    czyjatura='x';

    label <<ui->turagracza << ui->lab1 << ui->lab2 << ui->lab3 << ui->lab4 << ui-> lab5 << ui->lab6 << ui->lab7 << ui->lab8 << ui->lab9
          << ui->lab10 << ui->lab11 << ui->lab12 << ui->lab13 << ui-> lab14 << ui->lab15 << ui->lab16 << ui->lab17 << ui->lab18
          << ui->lab19 << ui->lab20 << ui->lab21 << ui->lab22 << ui-> lab23 << ui->lab24 << ui->lab25;
    button <<ui->nowagra << ui->b1 << ui->b2 << ui->b3 << ui->b4 << ui-> b5 << ui->b6 << ui->b7 << ui->b8 << ui->b9
           << ui->b10 << ui->b11 << ui->b12 << ui->b13 << ui-> b14 << ui->b15 << ui->b16 << ui->b17 << ui->b18
           << ui->b19 << ui->b20 << ui->b21 << ui->b22 << ui-> b23 << ui->b24 << ui->b25;

    for(int i=1; i<26; i++)
    {
        pk[i]='n';
        label[i]->setPixmap(pole);
        label[i]->setEnabled(true);
        button[i]->setVisible(true);
        button[i]->setCursor(Qt::PointingHandCursor);
    }
    ui->restart->setEnabled(true);

}

void MainWindow::on_solo_clicked()
{
    ui->solo->setEnabled(false);
    ui->duo->setEnabled(false);
    ui->turalabel->setPixmap(xtura);
    czyjatura='x';

    label <<ui->turagracza << ui->lab1 << ui->lab2 << ui->lab3 << ui->lab4 << ui-> lab5 << ui->lab6 << ui->lab7 << ui->lab8 << ui->lab9
          << ui->lab10 << ui->lab11 << ui->lab12 << ui->lab13 << ui-> lab14 << ui->lab15 << ui->lab16 << ui->lab17 << ui->lab18
          << ui->lab19 << ui->lab20 << ui->lab21 << ui->lab22 << ui-> lab23 << ui->lab24 << ui->lab25;
    button <<ui->nowagra << ui->b1 << ui->b2 << ui->b3 << ui->b4 << ui-> b5 << ui->b6 << ui->b7 << ui->b8 << ui->b9
           << ui->b10 << ui->b11 << ui->b12 << ui->b13 << ui-> b14 << ui->b15 << ui->b16 << ui->b17 << ui->b18
           << ui->b19 << ui->b20 << ui->b21 << ui->b22 << ui-> b23 << ui->b24 << ui->b25;

    for(int i=1; i<26; i++)
    {
        pk[i]='n';
        label[i]->setPixmap(pole);
        label[i]->setEnabled(true);
        button[i]->setVisible(true);
        button[i]->setCursor(Qt::PointingHandCursor);
    }
    ui->restart->setEnabled(true);
}

void MainWindow::on_b1_clicked()
{
    if(czyjatura=='x')
    {
        if(ui->solo->isChecked())
        {
            ui->b1->setVisible(false);
            ui->lab1->setPixmap(xpole);
            ui->turalabel->setPixmap(otura);
            pk[1]='x';
            who(pk);
            bot(pk);
            who(pk);
        }

        else
        {
            ui->b1->setVisible(false);
            czyjatura='o'; ui->turalabel->setPixmap(otura);
            ui->lab1->setPixmap(xpole);
            pk[1]='x';
            who(pk);
        }

    }

    else if(czyjatura=='o')
    {
        ui->b1->setVisible(false);
        czyjatura='x'; ui->turalabel->setPixmap(xtura);
        ui->lab1->setPixmap(opole);
        pk[1]='o';
        who(pk);
    }
}

void MainWindow::on_b2_clicked()
{
    if(czyjatura=='x')
    {
        if(ui->solo->isChecked())
        {
            ui->b2->setVisible(false);
            ui->lab2->setPixmap(xpole);
            ui->turalabel->setPixmap(otura);
            pk[2]='x';
            who(pk);
            bot(pk);
            who(pk);
        }

        else
        {
            ui->b2->setVisible(false);
            czyjatura='o'; ui->turalabel->setPixmap(otura);
            ui->lab2->setPixmap(xpole);
            pk[2]='x';
            who(pk);
        }

    }

    else if(czyjatura=='o')
    {
        ui->b2->setVisible(false);
        czyjatura='x'; ui->turalabel->setPixmap(xtura);
        ui->lab2->setPixmap(opole);
        pk[2]='o';
        who(pk);
    }
}

void MainWindow::on_b3_clicked()
{
    if(czyjatura=='x')
    {
        if(ui->solo->isChecked())
        {
            ui->b3->setVisible(false);
            ui->lab3->setPixmap(xpole);
            ui->turalabel->setPixmap(otura);
            pk[3]='x';
            who(pk);
            bot(pk);
            who(pk);
        }

        else
        {
            ui->b3->setVisible(false);
            czyjatura='o'; ui->turalabel->setPixmap(otura);
            ui->lab3->setPixmap(xpole);
            pk[3]='x';
            who(pk);
        }

    }

    else if(czyjatura=='o')
    {
        ui->b3->setVisible(false);
        czyjatura='x'; ui->turalabel->setPixmap(xtura);
        ui->lab3->setPixmap(opole);
        pk[3]='o';
        who(pk);
    }
}

void MainWindow::on_b4_clicked()
{
    if(czyjatura=='x')
    {
        if(ui->solo->isChecked())
        {
            ui->b4->setVisible(false);
            ui->lab4->setPixmap(xpole);
            ui->turalabel->setPixmap(otura);
            pk[4]='x';
            who(pk);
            bot(pk);
            who(pk);
        }

        else
        {
            ui->b4->setVisible(false);
            czyjatura='o'; ui->turalabel->setPixmap(otura);
            ui->lab4->setPixmap(xpole);
            pk[4]='x';
            who(pk);
        }

    }

    else if(czyjatura=='o')
    {
        ui->b4->setVisible(false);
        czyjatura='x'; ui->turalabel->setPixmap(xtura);
        ui->lab4->setPixmap(opole);
        pk[4]='o';
        who(pk);
    }
}

void MainWindow::on_b5_clicked()
{
    if(czyjatura=='x')
    {
        if(ui->solo->isChecked())
        {
            ui->b5->setVisible(false);
            ui->lab5->setPixmap(xpole);
            ui->turalabel->setPixmap(otura);
            pk[5]='x';
            who(pk);
            bot(pk);
            who(pk);
        }

        else
        {
            ui->b5->setVisible(false);
            czyjatura='o'; ui->turalabel->setPixmap(otura);
            ui->lab5->setPixmap(xpole);
            pk[5]='x';
            who(pk);
        }

    }

    else if(czyjatura=='o')
    {
        ui->b5->setVisible(false);
        czyjatura='x'; ui->turalabel->setPixmap(xtura);
        ui->lab5->setPixmap(opole);
        pk[5]='o';
        who(pk);
    }
}

void MainWindow::on_b6_clicked()
{
    if(czyjatura=='x')
    {
        if(ui->solo->isChecked())
        {
            ui->b6->setVisible(false);
            ui->lab6->setPixmap(xpole);
            ui->turalabel->setPixmap(otura);
            pk[6]='x';
            who(pk);
            bot(pk);
            who(pk);
        }

        else
        {
            ui->b6->setVisible(false);
            czyjatura='o'; ui->turalabel->setPixmap(otura);
            ui->lab6->setPixmap(xpole);
            pk[6]='x';
            who(pk);
        }

    }

    else if(czyjatura=='o')
    {
        ui->b6->setVisible(false);
        czyjatura='x'; ui->turalabel->setPixmap(xtura);
        ui->lab6->setPixmap(opole);
        pk[6]='o';
        who(pk);
    }
}

void MainWindow::on_b7_clicked()
{
    if(czyjatura=='x')
    {
        if(ui->solo->isChecked())
        {
            ui->b7->setVisible(false);
            ui->lab7->setPixmap(xpole);
            ui->turalabel->setPixmap(otura);
            pk[7]='x';
            who(pk);
            bot(pk);
            who(pk);
        }

        else
        {
            ui->b7->setVisible(false);
            czyjatura='o'; ui->turalabel->setPixmap(otura);
            ui->lab7->setPixmap(xpole);
            pk[7]='x';
            who(pk);
        }

    }

    else if(czyjatura=='o')
    {
        ui->b7->setVisible(false);
        czyjatura='x'; ui->turalabel->setPixmap(xtura);
        ui->lab7->setPixmap(opole);
        pk[7]='o';
        who(pk);
    }
}

void MainWindow::on_b8_clicked()
{
    if(czyjatura=='x')
    {
        if(ui->solo->isChecked())
        {
            ui->b8->setVisible(false);
            ui->lab8->setPixmap(xpole);
            ui->turalabel->setPixmap(otura);
            pk[8]='x';
            who(pk);
            bot(pk);
            who(pk);
        }

        else
        {
            ui->b8->setVisible(false);
            czyjatura='o'; ui->turalabel->setPixmap(otura);
            ui->lab8->setPixmap(xpole);
            pk[8]='x';
            who(pk);
        }

    }

    else if(czyjatura=='o')
    {
        ui->b8->setVisible(false);
        czyjatura='x'; ui->turalabel->setPixmap(xtura);
        ui->lab8->setPixmap(opole);
        pk[8]='o';
        who(pk);
    }
}

void MainWindow::on_b9_clicked()
{
    if(czyjatura=='x')
    {
        if(ui->solo->isChecked())
        {
            ui->b9->setVisible(false);
            ui->lab9->setPixmap(xpole);
            ui->turalabel->setPixmap(otura);
            pk[9]='x';
            who(pk);
            bot(pk);
            who(pk);
        }

        else
        {
            ui->b9->setVisible(false);
            czyjatura='o'; ui->turalabel->setPixmap(otura);
            ui->lab9->setPixmap(xpole);
            pk[9]='x';
            who(pk);
        }

    }

    else if(czyjatura=='o')
    {
        ui->b9->setVisible(false);
        czyjatura='x'; ui->turalabel->setPixmap(xtura);
        ui->lab9->setPixmap(opole);
        pk[9]='o';
        who(pk);
    }
}



void MainWindow::on_b10_clicked()
{
    if(czyjatura=='x')
    {
        if(ui->solo->isChecked())
        {
            ui->b10->setVisible(false);
            ui->lab10->setPixmap(xpole);
            ui->turalabel->setPixmap(otura);
            pk[10]='x';
            who(pk);
            bot(pk);
            who(pk);
        }

        else
        {
            ui->b10->setVisible(false);
            czyjatura='o'; ui->turalabel->setPixmap(otura);
            ui->lab10->setPixmap(xpole);
            pk[10]='x';
            who(pk);
        }

    }

    else if(czyjatura=='o')
    {
        ui->b10->setVisible(false);
        czyjatura='x'; ui->turalabel->setPixmap(xtura);
        ui->lab10->setPixmap(opole);
        pk[10]='o';
        who(pk);
    }
}

void MainWindow::on_b11_clicked()
{
    if(czyjatura=='x')
    {
        if(ui->solo->isChecked())
        {
            ui->b11->setVisible(false);
            ui->lab11->setPixmap(xpole);
            ui->turalabel->setPixmap(otura);
            pk[11]='x';
            who(pk);
            bot(pk);
            who(pk);
        }

        else
        {
            ui->b11->setVisible(false);
            czyjatura='o'; ui->turalabel->setPixmap(otura);
            ui->lab11->setPixmap(xpole);
            pk[11]='x';
            who(pk);
        }

    }

    else if(czyjatura=='o')
    {
        ui->b11->setVisible(false);
        czyjatura='x'; ui->turalabel->setPixmap(xtura);
        ui->lab11->setPixmap(opole);
        pk[11]='o';
        who(pk);
    }
}

void MainWindow::on_b12_clicked()
{
    if(czyjatura=='x')
    {
        if(ui->solo->isChecked())
        {
            ui->b12->setVisible(false);
            ui->lab12->setPixmap(xpole);
            ui->turalabel->setPixmap(otura);
            pk[12]='x';
            who(pk);
            bot(pk);
            who(pk);
        }

        else
        {
            ui->b12->setVisible(false);
            czyjatura='o'; ui->turalabel->setPixmap(otura);
            ui->lab12->setPixmap(xpole);
            pk[12]='x';
            who(pk);
        }

    }

    else if(czyjatura=='o')
    {
        ui->b12->setVisible(false);
        czyjatura='x'; ui->turalabel->setPixmap(xtura);
        ui->lab12->setPixmap(opole);
        pk[12]='o';
        who(pk);
    }
}

void MainWindow::on_b13_clicked()
{
    if(czyjatura=='x')
    {
        if(ui->solo->isChecked())
        {
            ui->b13->setVisible(false);
            ui->lab13->setPixmap(xpole);
            ui->turalabel->setPixmap(otura);
            pk[13]='x';
            who(pk);
            bot(pk);
            who(pk);
        }

        else
        {
            ui->b13->setVisible(false);
            czyjatura='o'; ui->turalabel->setPixmap(otura);
            ui->lab13->setPixmap(xpole);
            pk[13]='x';
            who(pk);
        }

    }

    else if(czyjatura=='o')
    {
        ui->b13->setVisible(false);
        czyjatura='x'; ui->turalabel->setPixmap(xtura);
        ui->lab13->setPixmap(opole);
        pk[13]='o';
        who(pk);
    }
}

void MainWindow::on_b14_clicked()
{
    if(czyjatura=='x')
    {
        if(ui->solo->isChecked())
        {
            ui->b14->setVisible(false);
            ui->lab14->setPixmap(xpole);
            ui->turalabel->setPixmap(otura);
            pk[14]='x';
            who(pk);
            bot(pk);
            who(pk);
        }

        else
        {
            ui->b14->setVisible(false);
            czyjatura='o'; ui->turalabel->setPixmap(otura);
            ui->lab14->setPixmap(xpole);
            pk[14]='x';
            who(pk);
        }

    }

    else if(czyjatura=='o')
    {
        ui->b14->setVisible(false);
        czyjatura='x'; ui->turalabel->setPixmap(xtura);
        ui->lab14->setPixmap(opole);
        pk[14]='o';
        who(pk);
    }
}

void MainWindow::on_b15_clicked()
{
    if(czyjatura=='x')
    {
        if(ui->solo->isChecked())
        {
            ui->b15->setVisible(false);
            ui->lab15->setPixmap(xpole);
            ui->turalabel->setPixmap(otura);
            pk[15]='x';
            who(pk);
            bot(pk);
            who(pk);
        }

        else
        {
            ui->b15->setVisible(false);
            czyjatura='o'; ui->turalabel->setPixmap(otura);
            ui->lab15->setPixmap(xpole);
            pk[15]='x';
            who(pk);
        }

    }

    else if(czyjatura=='o')
    {
        ui->b15->setVisible(false);
        czyjatura='x'; ui->turalabel->setPixmap(xtura);
        ui->lab15->setPixmap(opole);
        pk[15]='o';
        who(pk);
    }
}

void MainWindow::on_b16_clicked()
{
    if(czyjatura=='x')
    {
        if(ui->solo->isChecked())
        {
            ui->b16->setVisible(false);
            ui->lab16->setPixmap(xpole);
            ui->turalabel->setPixmap(otura);
            pk[16]='x';
            who(pk);
            bot(pk);
            who(pk);
        }

        else
        {
            ui->b16->setVisible(false);
            czyjatura='o'; ui->turalabel->setPixmap(otura);
            ui->lab16->setPixmap(xpole);
            pk[16]='x';
            who(pk);
        }

    }

    else if(czyjatura=='o')
    {
        ui->b16->setVisible(false);
        czyjatura='x'; ui->turalabel->setPixmap(xtura);
        ui->lab16->setPixmap(opole);
        pk[16]='o';
        who(pk);
    }
}

void MainWindow::on_b17_clicked()
{
    if(czyjatura=='x')
    {
        if(ui->solo->isChecked())
        {
            ui->b17->setVisible(false);
            ui->lab17->setPixmap(xpole);
            ui->turalabel->setPixmap(otura);
            pk[17]='x';
            who(pk);
            bot(pk);
            who(pk);
        }

        else
        {
            ui->b17->setVisible(false);
            czyjatura='o'; ui->turalabel->setPixmap(otura);
            ui->lab17->setPixmap(xpole);
            pk[17]='x';
            who(pk);
        }

    }

    else if(czyjatura=='o')
    {
        ui->b17->setVisible(false);
        czyjatura='x'; ui->turalabel->setPixmap(xtura);
        ui->lab17->setPixmap(opole);
        pk[17]='o';
        who(pk);
    }
}

void MainWindow::on_b18_clicked()
{
    if(czyjatura=='x')
    {
        if(ui->solo->isChecked())
        {
            ui->b18->setVisible(false);
            ui->lab18->setPixmap(xpole);
            ui->turalabel->setPixmap(otura);
            pk[18]='x';
            who(pk);
            bot(pk);
            who(pk);
        }

        else
        {
            ui->b18->setVisible(false);
            czyjatura='o'; ui->turalabel->setPixmap(otura);
            ui->lab18->setPixmap(xpole);
            pk[18]='x';
            who(pk);
        }

    }

    else if(czyjatura=='o')
    {
        ui->b18->setVisible(false);
        czyjatura='x'; ui->turalabel->setPixmap(xtura);
        ui->lab18->setPixmap(opole);
        pk[18]='o';
        who(pk);
    }
}

void MainWindow::on_b19_clicked()
{
    if(czyjatura=='x')
    {
        if(ui->solo->isChecked())
        {
            ui->b19->setVisible(false);
            ui->lab19->setPixmap(xpole);
            ui->turalabel->setPixmap(otura);
            pk[19]='x';
            who(pk);
            bot(pk);
            who(pk);
        }

        else
        {
            ui->b19->setVisible(false);
            czyjatura='o'; ui->turalabel->setPixmap(otura);
            ui->lab19->setPixmap(xpole);
            pk[19]='x';
            who(pk);
        }

    }

    else if(czyjatura=='o')
    {
        ui->b19->setVisible(false);
        czyjatura='x'; ui->turalabel->setPixmap(xtura);
        ui->lab19->setPixmap(opole);
        pk[19]='o';
        who(pk);
    }
}

void MainWindow::on_b20_clicked()
{
    if(czyjatura=='x')
    {
        if(ui->solo->isChecked())
        {
            ui->b20->setVisible(false);
            ui->lab20->setPixmap(xpole);
            ui->turalabel->setPixmap(otura);
            pk[20]='x';
            who(pk);
            bot(pk);
            who(pk);
        }

        else
        {
            ui->b20->setVisible(false);
            czyjatura='o'; ui->turalabel->setPixmap(otura);
            ui->lab20->setPixmap(xpole);
            pk[20]='x';
            who(pk);
        }

    }

    else if(czyjatura=='o')
    {
        ui->b20->setVisible(false);
        czyjatura='x'; ui->turalabel->setPixmap(xtura);
        ui->lab20->setPixmap(opole);
        pk[20]='o';
        who(pk);
    }
}

void MainWindow::on_b21_clicked()
{
    if(czyjatura=='x')
    {
        if(ui->solo->isChecked())
        {
            ui->b21->setVisible(false);
            ui->lab21->setPixmap(xpole);
            ui->turalabel->setPixmap(otura);
            pk[21]='x';
            who(pk);
            bot(pk);
            who(pk);
        }

        else
        {
            ui->b21->setVisible(false);
            czyjatura='o'; ui->turalabel->setPixmap(otura);
            ui->lab21->setPixmap(xpole);
            pk[21]='x';
            who(pk);
        }

    }

    else if(czyjatura=='o')
    {
        ui->b21->setVisible(false);
        czyjatura='x'; ui->turalabel->setPixmap(xtura);
        ui->lab21->setPixmap(opole);
        pk[21]='o';
        who(pk);
    }
}

void MainWindow::on_b22_clicked()
{
    if(czyjatura=='x')
    {
        if(ui->solo->isChecked())
        {
            ui->b22->setVisible(false);
            ui->lab22->setPixmap(xpole);
            ui->turalabel->setPixmap(otura);
            pk[22]='x';
            who(pk);
            bot(pk);
            who(pk);
        }

        else
        {
            ui->b22->setVisible(false);
            czyjatura='o'; ui->turalabel->setPixmap(otura);
            ui->lab22->setPixmap(xpole);
            pk[22]='x';
            who(pk);
        }

    }

    else if(czyjatura=='o')
    {
        ui->b22->setVisible(false);
        czyjatura='x'; ui->turalabel->setPixmap(xtura);
        ui->lab22->setPixmap(opole);
        pk[22]='o';
        who(pk);
    }
}

void MainWindow::on_b23_clicked()
{
    if(czyjatura=='x')
    {
        if(ui->solo->isChecked())
        {
            ui->b23->setVisible(false);
            ui->lab23->setPixmap(xpole);
            ui->turalabel->setPixmap(otura);
            pk[23]='x';
            who(pk);
            bot(pk);
            who(pk);
        }

        else
        {
            ui->b23->setVisible(false);
            czyjatura='o'; ui->turalabel->setPixmap(otura);
            ui->lab23->setPixmap(xpole);
            pk[23]='x';
            who(pk);
        }

    }

    else if(czyjatura=='o')
    {
        ui->b23->setVisible(false);
        czyjatura='x'; ui->turalabel->setPixmap(xtura);
        ui->lab23->setPixmap(opole);
        pk[23]='o';
        who(pk);
    }
}

void MainWindow::on_b24_clicked()
{
    if(czyjatura=='x')
    {
        if(ui->solo->isChecked())
        {
            ui->b24->setVisible(false);
            ui->lab24->setPixmap(xpole);
            ui->turalabel->setPixmap(otura);
            pk[24]='x';
            who(pk);
            bot(pk);
            who(pk);
        }

        else
        {
            ui->b24->setVisible(false);
            czyjatura='o'; ui->turalabel->setPixmap(otura);
            ui->lab24->setPixmap(xpole);
            pk[24]='x';
            who(pk);
        }

    }

    else if(czyjatura=='o')
    {
        ui->b24->setVisible(false);
        czyjatura='x'; ui->turalabel->setPixmap(xtura);
        ui->lab24->setPixmap(opole);
        pk[24]='o';
        who(pk);
    }
}

void MainWindow::on_b25_clicked()
{
    if(czyjatura=='x')
    {
        if(ui->solo->isChecked())
        {
            ui->b25->setVisible(false);
            ui->lab25->setPixmap(xpole);
            ui->turalabel->setPixmap(otura);
            pk[25]='x';
            who(pk);
            bot(pk);
            who(pk);
        }

        else
        {
            ui->b25->setVisible(false);
            czyjatura='o'; ui->turalabel->setPixmap(otura);
            ui->lab25->setPixmap(xpole);
            pk[25]='x';
            who(pk);
        }

    }

    else if(czyjatura=='o')
    {
        ui->b25->setVisible(false);
        czyjatura='x'; ui->turalabel->setPixmap(xtura);
        ui->lab25->setPixmap(opole);
        pk[25]='o';
        who(pk);
    }
}




