#include "incluirdvd.h"
#include "qmessagebox.h"
#include "ui_incluirdvd.h"

IncluirDVD::IncluirDVD(QWidget *parent) : QDialog(parent),
                                          ui(new Ui::IncluirDVD)
{
    ui->setupUi(this);
}

IncluirDVD::~IncluirDVD()
{
    delete ui;
}

void IncluirDVD::clear()
{
    ui->input_dvd_nome->clear();
    ui->input_dvd_duracao->clear();
    ui->input_dvd_preco->clear();
}

void IncluirDVD::on_buttonBox_accepted()
{
    QString nome = ui->input_dvd_nome->text();
    QString preco = ui->input_dvd_preco->text();
    QString duracao = ui->input_dvd_duracao->text();
    if (preco.toFloat() <= 0.0 || nome.isEmpty() || duracao.toInt() <= 0)
    {
        const QString csMsg("Não foi possivel incluir o DVD:\nNome=" + nome + "\n" + "Preço=" + preco + "\n" + "Duração=" + duracao);
        const QString csTitle("DVD Inválido");
        QMessageBox msgBox;
        msgBox.critical(nullptr, csTitle, csMsg);
        return;
    }

    emit signIncluirDVD(nome, preco, duracao);
}
