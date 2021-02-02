#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int wt,ht,wp,hp,koniec;
    char czyjatura;
    char pk[26];
    //QPixmap tpole;
    QPixmap xpole= QPixmap(":/pliki/obrazki/x.png");
    QPixmap pole= QPixmap(":/pliki/obrazki/pole.png");
    QPixmap opole=QPixmap(":/pliki/obrazki/o.png");
    QPixmap pt= QPixmap(":/pliki/obrazki/pole.png");
    QPixmap xtura= QPixmap(":/pliki/obrazki/x.png");
    QPixmap otura=QPixmap(":/pliki/obrazki/o.png");
    void who(char tab[]);
    //QLabel *labtab[9]={ui->p1,ui->p2,ui->p3,ui->p4,ui->p5,ui->p6,ui->p7,ui->p8,ui->p9};
    //QPushButton *buttab[9]={ui->b1,ui->b2,ui->b3,ui->b4,ui->b5,ui->b6,ui->b7,ui->b8,ui->b9};
    QVector<QLabel*> label;
    QVector<QPushButton*> button;
    void delay();
    void bot(char tab[]);






private slots:
    void on_nowagra_clicked();




    void on_b1_clicked();

    void on_b2_clicked();

    void on_b3_clicked();

    void on_b4_clicked();

    void on_b5_clicked();

    void on_b6_clicked();

    void on_b7_clicked();

    void on_b8_clicked();

    void on_b9_clicked();

    void on_restart_clicked();

    void on_b10_clicked();

    void on_b11_clicked();

    void on_b12_clicked();

    void on_b13_clicked();

    void on_b14_clicked();

    void on_b15_clicked();

    void on_b16_clicked();

    void on_b17_clicked();

    void on_b18_clicked();

    void on_b19_clicked();

    void on_b20_clicked();

    void on_b21_clicked();

    void on_b22_clicked();

    void on_b23_clicked();

    void on_b24_clicked();

    void on_b25_clicked();

    void on_duo_clicked();

    void on_solo_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
