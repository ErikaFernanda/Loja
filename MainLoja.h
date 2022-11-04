#ifndef MainLoja_H
#define MainLoja_H

#include <QMainWindow>

namespace Ui {
class MainLoja;
}

class MainLoja : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainLoja(QWidget *parent = 0);
  ~MainLoja();

private slots:
  void on_tableWidget_3_cellDoubleClicked(int row, int column);


  void on_actionSair_triggered();

  void on_actionLer_triggered();

  void on_actionIncluir_Livro_triggered();

private:
  Ui::MainLoja *ui;
};

#endif // MainLoja_H
