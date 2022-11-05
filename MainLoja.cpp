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
  inclLivro = new IncluirLivro();
  connect(inclLivro, &IncluirLivro::signIncluirLivro, this, &MainLoja::slotIncluirLivro );
}

MainLoja::~MainLoja()
{
  delete ui;
}

void MainLoja::on_actionSair_triggered()
{
    std::cout << X.getNumLivro();
    QCoreApplication::quit();

}


void MainLoja::on_actionLer_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,"Ler estoque",QString(),"Text Files (*.txt);");
    bool isValid = X.ler(fileName.toStdString());

    if(!isValid){
        QMessageBox::critical(this, tr("Error"), tr("Erro ao tentar ler arquivo"));
    }
    preencher_Livros();
}



void MainLoja::on_actionSalvar_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,"Salvar estoque",QString(),"Text Files (*.txt)");
    bool isValid = X.salvar(fileName.toStdString());

    if(!isValid){
        QMessageBox::critical(this, tr("Error"), tr("Erro ao tentar salvar arquivo"));
    }

}
void MainLoja::on_actionIncluir_Livro_triggered()
{

    inclLivro->clear();
    inclLivro->show();
}

void MainLoja::on_actionIncluir_CD_triggered()
{

}


void MainLoja::on_actionIncluir_DVD_triggered()
{

}

void MainLoja::slotIncluirLivro(QString nome, QString preco, QString autor) {
    Livro livro = Livro(nome.toStdString(), preco.toInt(),autor.toStdString());
    X.incluirLivro(livro);
    preencher_Livros();
}

void MainLoja::on_table_livros_cellDoubleClicked(int row, int column)
{
   X.excluirLivro(row);
   preencher_Livros();
}

void MainLoja::preencher_Livros(){

    ui -> table_livros -> clearContents ();
    ui -> table_livros -> setRowCount ( X.getNumLivro());
    for ( int i = 0; i < X.getNumLivro (); i++ ) {
            for ( int j = 0; j < 3; j++ ) {
                QTableWidgetItem *table_item = new QTableWidgetItem;
                if ( j == 0 ) {
                    QString nome = QString::fromStdString ( X.getLivro (i).getNome () );
                    table_item -> setText(nome);
                }
                if ( j == 1 ) {
                    QString preco = QString::number( X.getLivro(i).getPreco (), 'f', 2 );
                    table_item -> setText(preco);
                }
                if ( j == 2 ) {
                    QString autor = QString::fromStdString ( X.getLivro (i).getAutor () );
                    table_item -> setText(autor);
                }
                ui->table_livros->setItem(i, j, table_item);
            }
        }
}
