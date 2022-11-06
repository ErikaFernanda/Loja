#ifndef MainLoja_H
#define MainLoja_H

#include "incluircd.h"
#include "incluirdvd.h"
#include "incluirlivro.h"
#include "loja.h"
#include "qlabel.h"
#include <QMainWindow>

namespace Ui
{
  class MainLoja;
}

class MainLoja : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainLoja(QWidget *parent = 0);
  ~MainLoja();
  void preencher_Livros();
  void preencher_CDS();
  void preencher_DVDS();
  void preencher_Listas();
  void update_n_itens();
private slots:

  void on_actionSair_triggered();

  void on_actionLer_triggered();

  void on_actionIncluir_Livro_triggered();

  void on_actionSalvar_triggered();

  void on_actionIncluir_CD_triggered();

  void on_actionIncluir_DVD_triggered();

  void slotIncluirLivro(QString nome, QString preco, QString autor);
  void slotIncluirCD(QString nome, QString preco, QString nfaixas);
  void slotIncluirDVD(QString nome, QString preco, QString duracao);

  void on_table_livros_cellDoubleClicked(int row, int column);

  void on_table_dvds_cellDoubleClicked(int row, int column);

  void on_table_cds_cellDoubleClicked(int row, int column);

private:
  Ui::MainLoja *ui;
  Loja X;
  IncluirLivro *inclLivro;
  IncluirCD *inclCD;
  IncluirDVD *inclDVD;
  QLabel *total_itens;
};

#endif // MainLoja_H
