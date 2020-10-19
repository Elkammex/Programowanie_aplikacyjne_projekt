#include "mainlm.h"
#include "ui_mainlm.h"

MainLM::MainLM(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainLM)
{
    ui->setupUi(this);
}

MainLM::~MainLM()
{
    delete ui;
}

