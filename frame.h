#ifndef FRAME_H
#define FRAME_H

#include <QMainWindow>

namespace Ui {
class Frame;
}

class Frame : public QMainWindow
{
  Q_OBJECT

public:
  explicit Frame(QWidget *parent = 0);
  ~Frame();

//private slots:
//  void on_quitButton_clicked();

//  void on_actionOpen_triggered();

//  void on_actionSave_triggered();

private:
  Ui::Frame *ui;
};

#endif // FRAME_H
