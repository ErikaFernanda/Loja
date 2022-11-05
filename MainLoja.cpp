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

  total_itens = new QLabel(this);
  statusBar()->insertWidget(0, new QLabel("Total de itens: "));
  statusBar()->insertWidget(1, total_itens);
  total_itens->setText("0");

  ui->label_livros->setStyleSheet("QLabel { background-color: lightgray }"); //Label livro
  ui->table_livros->setHorizontalHeaderLabels(QStringList() << "NOME" << "PRECO" << "AUTOR");
  ui->table_livros->setStyleSheet("QHeaderView::section{background-color:lightgray}");
  ui->table_livros->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Stretch);
  ui->table_livros->horizontalHeader()->setSectionResizeMode(1,QHeaderView::ResizeToContents);
  ui->table_livros->horizontalHeader()->setSectionResizeMode(2,QHeaderView::ResizeToContents);

  ui->label_cds->setStyleSheet("QLabel { background-color: lightgray }"); //Label cd
  ui->table_cds->setStyleSheet("QHeaderView::section { background-color:lightgray }");
  ui->table_cds->setHorizontalHeaderLabels(QStringList() << "NOME" << "PRECO" << "N FAIXAS");
  ui->table_cds->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Stretch);
  ui->table_cds->horizontalHeader()->setSectionResizeMode(1,QHeaderView::ResizeToContents);
  ui->table_cds->horizontalHeader()->setSectionResizeMode(2,QHeaderView::ResizeToContents);

  ui->label_dvds->setStyleSheet("QLabel { background-color: lightgray }"); //Label dvd
  ui->table_dvds->setHorizontalHeaderLabels(QStringList() << "NOME" << "PRECO" << "DURACAO");
  ui->table_dvds->setStyleSheet("QHeaderView::section { background-color:lightgray }");
  ui->table_dvds->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Stretch);
  ui->table_dvds->horizontalHeader()->setSectionResizeMode(1,QHeaderView::ResizeToContents);
  ui->table_dvds->horizontalHeader()->setSectionResizeMode(2,QHeaderView::ResizeToContents);
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
        QMessageBox::critical(this, tr("Erro de leitura"), tr("Erro ao tentar ler arquivo"));
    }
    preencher_Listas();
}



void MainLoja::on_actionSalvar_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,"Salvar estoque",QString(),"Text Files (*.txt)");
    bool isValid = X.salvar(fileName.toStdString());

    if(!isValid){
        QMessageBox::critical(this, tr("Erro ao salvar"), tr("Erro ao tentar salvar arquivo"));
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
    Livro livro = Livro(nome.toStdString(), round(preco.toFloat() *100.0),autor.toStdString());
    X.incluirLivro(livro);
    preencher_Listas();
}

void MainLoja::slotIncluirCD(QString nome, QString preco, QString nfaixas) {
    CD cd = CD(nome.toStdString(), round(preco.toFloat() *100.0),nfaixas.toInt());
    X.incluirCD(cd);
    preencher_Listas();
}
void MainLoja::slotIncluirDVD(QString nome, QString preco, QString duracao) {
    DVD cd = DVD(nome.toStdString(),round(preco.toFloat() *100.0),duracao.toInt());
    X.incluirDVD(cd);
    preencher_Listas();
}

void MainLoja::on_table_livros_cellDoubleClicked(int row, int column)
{
   X.excluirLivro(row);
   preencher_Listas();
}

void MainLoja::preencher_Livros(){
    QLabel* prov;
    ui -> table_livros -> clearContents ();
    ui -> table_livros -> setRowCount ( X.getNumLivro());
    for ( int i = 0; i < X.getNumLivro(); i++ ) {
            for ( int j = 0; j < 3; j++ ) {
                prov = new QLabel();
                Livro L = X.getLivro(i);

                if ( j == 0 ) {
                    QString nome = QString::fromStdString ( L.getNome () );
                    prov -> setText(nome);
                    prov->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
                }
                if ( j == 1 ) {
                    QString preco = QString::number( L.getPreco (), 'f', 2 );
                    prov -> setText(preco);
                    prov->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
                }
                if ( j == 2 ) {
                    QString autor = QString::fromStdString ( L.getAutor () );
                    prov -> setText(autor);
                    prov->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
                }
                ui->table_livros->setCellWidget(i, j, prov);
            }
        }
}
void MainLoja::preencher_CDS(){

    ui -> table_cds -> clearContents ();
    ui -> table_cds -> setRowCount ( X.getNumCD());
    for ( int i = 0; i < X.getNumCD(); i++ ) {
            for ( int j = 0; j < 3; j++ ) {
                QLabel* prov = new QLabel();
                CD cd = X.getCD(i);
                if ( j == 0 ) {
                    QString nome = QString::fromStdString ( cd.getNome () );
                    prov -> setText(nome);
                    prov->setAlignment(Qt::AlignLeft| Qt::AlignVCenter);
                }
                if ( j == 1 ) {
                    QString preco = QString::number( cd.getPreco (), 'f', 2 );
                    prov -> setText(preco);
                    prov->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
                }
                if ( j == 2 ) {
                    QString nfaixas = QString::number(cd.getNumFaixas() );
                    prov -> setText(nfaixas);
                    prov->setAlignment(Qt::AlignCenter | Qt::AlignVCenter);
                }
                ui->table_cds->setCellWidget(i, j, prov);
            }
        }
}
void MainLoja::preencher_DVDS(){
    QLabel* prov;
    ui -> table_dvds -> clearContents ();
    ui -> table_dvds -> setRowCount ( X.getNumDVD());
    for ( int i = 0; i < X.getNumDVD(); i++ ) {
            for ( int j = 0; j < 3; j++ ) {
                prov = new QLabel();
                DVD dvd = X.getDVD(i);

                if ( j == 0 ) {
                    QString nome = QString::fromStdString ( dvd.getNome () );
                    prov -> setText(nome);
                    prov->setAlignment(Qt::AlignLeft| Qt::AlignVCenter);
                }
                if ( j == 1 ) {
                    QString preco = QString::number(dvd.getPreco (), 'f', 2 );
                    prov -> setText(preco);
                    prov->setAlignment(Qt::AlignRight| Qt::AlignVCenter);
                }
                if ( j == 2 ) {
                    QString duracao = QString::number( dvd.getDuracao() );
                    prov -> setText(duracao);
                    prov->setAlignment(Qt::AlignCenter | Qt::AlignVCenter);
                }
                ui->table_dvds->setCellWidget(i, j, prov);
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
    total_itens->setText(QString::number(total));
}
void MainLoja::preencher_Listas(){
    preencher_CDS();
    preencher_DVDS();
    preencher_Livros();
    update_n_itens();

}
