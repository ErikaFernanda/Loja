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

  inclCD = new IncluirCD();
  connect(inclCD, &IncluirCD::signIncluirCD, this, &::MainLoja::slotIncluirCD );

  inclDVD = new IncluirDVD();
  connect(inclDVD, &IncluirDVD::signIncluirDVD, this, &::MainLoja::slotIncluirDVD );

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
    preencher_Listas();
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
    inclCD->clear();
    inclCD->show();
}


void MainLoja::on_actionIncluir_DVD_triggered()
{
    inclDVD->clear();
    inclDVD->show();
}

void MainLoja::slotIncluirLivro(QString nome, QString preco, QString autor) {
    Livro livro = Livro(nome.toStdString(), preco.toInt(),autor.toStdString());
    X.incluirLivro(livro);
    preencher_Listas();
}

void MainLoja::slotIncluirCD(QString nome, QString preco, QString nfaixas) {
    CD cd = CD(nome.toStdString(), preco.toInt(),nfaixas.toInt());
    X.incluirCD(cd);
    preencher_Listas();
}
void MainLoja::slotIncluirDVD(QString nome, QString preco, QString duracao) {
    DVD cd = DVD(nome.toStdString(), preco.toInt(),duracao.toInt());
    X.incluirDVD(cd);
    preencher_Listas();
}

void MainLoja::on_table_livros_cellDoubleClicked(int row, int column)
{
   X.excluirLivro(row);
   preencher_Listas();
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
void MainLoja::preencher_CDS(){

    ui -> table_cds -> clearContents ();
    ui -> table_cds -> setRowCount ( X.getNumCD());
    for ( int i = 0; i < X.getNumCD(); i++ ) {
            for ( int j = 0; j < 3; j++ ) {
                QTableWidgetItem *table_item = new QTableWidgetItem;
                if ( j == 0 ) {
                    QString nome = QString::fromStdString ( X.getCD(i).getNome () );
                    table_item -> setText(nome);
                }
                if ( j == 1 ) {
                    QString preco = QString::number( X.getCD(i).getPreco (), 'f', 2 );
                    table_item -> setText(preco);
                }
                if ( j == 2 ) {
                    QString nfaixas = QString::number( X.getCD(i).getNumFaixas() );
                    table_item -> setText(nfaixas);
                }
                ui->table_cds->setItem(i, j, table_item);
            }
        }
}
void MainLoja::preencher_DVDS(){

    ui -> table_dvds -> clearContents ();
    ui -> table_dvds -> setRowCount ( X.getNumDVD());
    for ( int i = 0; i < X.getNumDVD(); i++ ) {
            for ( int j = 0; j < 3; j++ ) {
                QTableWidgetItem *table_item = new QTableWidgetItem;
                if ( j == 0 ) {
                    QString nome = QString::fromStdString ( X.getDVD(i).getNome () );
                    table_item -> setText(nome);
                }
                if ( j == 1 ) {
                    QString preco = QString::number( X.getDVD(i).getPreco (), 'f', 2 );
                    table_item -> setText(preco);
                }
                if ( j == 2 ) {
                    QString duracao = QString::number( X.getDVD(i).getDuracao() );
                    table_item -> setText(duracao);
                }
                ui->table_dvds->setItem(i, j, table_item);
            }
        }
}

void MainLoja::on_table_dvds_cellDoubleClicked(int row, int column)
{
    X.excluirDVD(row);
    preencher_Listas();
}


void MainLoja::on_table_cds_cellDoubleClicked(int row, int column)
{
    X.excluirCD(row);
    preencher_Listas();
}

void MainLoja::update_n_itens(){
    int cds = X.getNumCD();
    int dvds = X.getNumDVD();
    int livro = X.getNumLivro();
    int total = cds+dvds+livro;
    ui->label_number_itens->setText(QString::number(total));
}
void MainLoja::preencher_Listas(){
    preencher_CDS();
    preencher_DVDS();
    preencher_Livros();
    update_n_itens();

}
