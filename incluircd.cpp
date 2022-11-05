#include "incluircd.h"
#include "ui_incluircd.h"

IncluirCD::IncluirCD(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IncluirCD)
{
    ui->setupUi(this);
}

IncluirCD::~IncluirCD()
{
    delete ui;
}

void IncluirCD::clear(){
    ui->input_cd_nome->clear();
    ui->input_cd_nfaixas->clear();
    ui->input_cd_preco->clear();
}

void IncluirCD::on_buttonBox_accepted()
{
    QString nome = ui->input_cd_nome->text();
    QString preco = ui->input_cd_preco->text();
    QString nfaixas = ui->input_cd_nfaixas->text();

    emit signIncluirCD(nome,preco,nfaixas);
}

