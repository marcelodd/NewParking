/*
 * File:   RegistraVagaForm.cpp
 * Author: marcelo
 *
 * Created on 6 de Agosto de 2015, 12:45
 */

#include "RegistraVagaForm.h"

RegistraVagaForm::RegistraVagaForm(cv::Mat img,cv::Rect bx) {
    widget.setupUi(this);
    image = img;
    box   = bx;
    setLabel();
    connect(widget.SalvarVagaButton,SIGNAL(clicked()),this,SLOT(salvar()));
    
}

RegistraVagaForm::~RegistraVagaForm() {
}

void RegistraVagaForm::setLabel() {
    QPixmap map = this->util.matToQPixmap(image);
    widget.ImageVagalabel->setPixmap(map);
}

void RegistraVagaForm::salvar() {
    if (!widget.DescricaoVagaEdit->text().isEmpty()) {
        dao = new VagaDao(QString::number(camId));
        bool res = dao->insert(util.toChar(widget.DescricaoVagaEdit->text().toStdString()),box);
        if(!res){
            QMessageBox::critical(this,tr("Error"),tr("Erro ao adicionar nova vaga :"));
        }else{
            cvSaveImage(util.concateName(widget.DescricaoVagaEdit->text().toStdString()),new IplImage(image),0);
        }
        reject();
        this->close();
    }
}


