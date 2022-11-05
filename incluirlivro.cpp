#include "incluirlivro.h"
#include "loja.h"
#include "ui_incluirlivro.h"
#include <iostream>

IncluirLivro::IncluirLivro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IncluirLivro)
{
    ui->setupUi(this);
}

IncluirLivro::~IncluirLivro()
{
    delete ui;
}
void IncluirLivro::clear(){
  ui->input_livro_name->clear();
  ui->input_livro_preco->clear();
  ui->input_livro_autor->clear();
}

void IncluirLivro::on_buttonBox_accepted()
{
    QString nome = ui->input_livro_autor->text();
    QString preco = ui->input_livro_preco->text();
    QString autor = ui->input_livro_autor->text();
//    Livro a = Livro(ax.toStdString(), b.toInt(),c.toStdString());

    emit signIncluirLivro(nome,preco,autor);
}

