#include "incluircd.h"
#include "ui_incluircd.h"
#include <QMessageBox>

IncluirCD::IncluirCD(QWidget *parent) : QDialog(parent),
                                        ui(new Ui::IncluirCD)
{
    ui->setupUi(this);
}

IncluirCD::~IncluirCD()
{
    delete ui;
}

void IncluirCD::clear()
{
    ui->input_cd_nome->clear();
    ui->input_cd_nfaixas->clear();
    ui->input_cd_preco->clear();
}

void IncluirCD::on_buttonBox_accepted()
{
    QString nome = ui->input_cd_nome->text();
    QString preco = ui->input_cd_preco->text();
    QString nfaixas = ui->input_cd_nfaixas->text();

    if (preco.toFloat() <= 0.0 || nome.isEmpty() || nfaixas.toInt() <= 0)
    {
        const QString csMsg("Não foi possivel incluir o CD:\nNome=" + nome + "\n" + "Preço=" + preco + "\n" + "Num faixas=" + nfaixas);
        const QString csTitle("CD Inválido");
        QMessageBox msgBox;
        msgBox.critical(nullptr, csTitle, csMsg);
        return;
    }

    emit signIncluirCD(nome, preco, nfaixas);
}
