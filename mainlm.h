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

private:
    Ui::MainLM *ui;
};
#endif // MAINLM_H
