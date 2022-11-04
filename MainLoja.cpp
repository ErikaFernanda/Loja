#include "MainLoja.h"
#include "ui_MainLoja.h"

MainLoja::MainLoja(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainLoja)
{
  ui->setupUi(this);
}

MainLoja::~MainLoja()
{
  delete ui;
}

void MainLoja::on_tableWidget_3_cellDoubleClicked(int row, int column)
{

}

