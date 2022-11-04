#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

#include "frame.h"
#include "ui_frame.h"

Frame::Frame(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Frame)
{
  ui->setupUi(this);
}

Frame::~Frame()
{
  delete ui;
}
