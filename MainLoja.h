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

private:
  Ui::MainLoja *ui;
};

#endif // MainLoja_H
