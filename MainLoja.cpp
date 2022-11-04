#include <QFileDialog>
#include "MainLoja.h"
#include "ui_MainLoja.h"
#include <fstream>
#include <QMessageBox>
#include <QTextStream>
#include "loja.h"
#include "incluirlivro.h"

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


void MainLoja::on_actionSair_triggered()
{
     QCoreApplication::quit();
}


void MainLoja::on_actionLer_triggered()
{
    Loja j;
    QString fileName = QFileDialog::getOpenFileName(this,"Ler estoque",QString(),"Text Files (*.txt);");
    bool isValid = j.ler(fileName.toStdString());

    if(!isValid){
        QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
    }
}


void MainLoja::on_actionIncluir_Livro_triggered()
{
    IncluirLivro w;
    w.exec();
}

