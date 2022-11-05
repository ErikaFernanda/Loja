#include "incluirlivro.h"
#include "qmessagebox.h"
#include "ui_incluirlivro.h"

IncluirLivro::IncluirLivro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IncluirLivro)
{
    ui->setupUi(this);
}

IncluirLivro::~IncluirLivro()
{
    delete ui;
}

void IncluirLivro::clear(){
  ui->input_livro_name->clear();
  ui->input_livro_preco->clear();
  ui->input_livro_autor->clear();
}

void IncluirLivro::on_buttonBox_accepted()
{
    QString nome = ui->input_livro_autor->text();
    QString preco = ui->input_livro_preco->text();
    QString autor = ui->input_livro_autor->text();
    if(preco.toFloat() <= 0.0 || nome.isEmpty() || autor.isEmpty()){
        const QString csMsg("Não foi possivel incluir o livro:\nNome=" + nome + "\n" + "Preço=" + preco +"\n" + "Autor=" + autor);
        const QString csTitle("Livro Inválido");
        QMessageBox msgBox;
        msgBox.critical(nullptr, csTitle, csMsg);
        return;
    }

    emit signIncluirLivro(nome,preco,autor);
}

