#ifndef MAINLM_H
#define MAINLM_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainLM; }
QT_END_NAMESPACE

class MainLM : public QMainWindow
{
    Q_OBJECT

public:
    MainLM(QWidget *parent = nullptr);
    ~MainLM();


void read();
int bubblesortM(QString x,QString y,QString z);
int bubblesortR(QString x,QString y,QString z);
int il;





private slots:
    void on_pushButton_clicked();



    void on_Wiekbutton_clicked();
    void on_Maleje_clicked(bool checked);

    void on_Rosnie_clicked(bool checked);

    void on_pzbutton_clicked(bool checked);

    void on_ndbutton_clicked(bool checked);

    void on_Wzrbutton_clicked(bool checked);

    void on_Cenabutton_clicked(bool checked);



private:
    Ui::MainLM *ui;


};

class Zawodnik
{
    public:
    QString nazwa,narodowosc,pozycja;
    QString wiek,wzrost,wartosc;



    Zawodnik(QString="brak",QString="brak",QString="brak", QString="0",QString="0",QString="0");
    ~Zawodnik();



};


#endif // MAINLM_H
