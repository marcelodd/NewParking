/*
 * File:   MainForm.cpp
 * Author: marcelo
 *
 * Created on 6 de Agosto de 2015, 12:44
 */

#include "MainForm.h"
#include "Debug.h"
#include <stdio.h>
#include "QSettings"
#include <QApplication>
#include "QStyleFactory"
#include "QStyle"

MainForm::MainForm() {
    widget.setupUi(this);
    
    
    connect(widget.labelFrame,SIGNAL(Mouse_Position()),this,SLOT(Mouse_current_pos()));
    connect(widget.labelFrame,SIGNAL(Mouse_Pressed()),this,SLOT(Mouse_Pressed()));
    connect(widget.labelFrame,SIGNAL(Mouse_Left()),this,SLOT(Mouse_left()));
    connect(widget.labelFrame,SIGNAL(Mouse_Release()),this,SLOT(Mouse_Release()));
    
    connect(widget.CameraButton,SIGNAL(clicked()),this,SLOT(camera()));
    connect(widget.AdicionarButton,SIGNAL(clicked()),this,SLOT(adicionar()));
    
    
    this->isStart = false;
    this->drawing_box = false;
    

    
    settings = new QSettings("NewParking.ini", QSettings::IniFormat);
    settings->beginGroup("PARAMETROS");
    
    cam = new Camera(settings->value("camera").toInt());
    connect(cam,SIGNAL(timeOut()),this,SLOT(update()));
    
    current_pos =  new QLabel(this);
    
    widget.statusbar->addPermanentWidget(current_pos);
}

void MainForm::debug() {
    Debug *d = new Debug(cam);
    d->exec();
}



void MainForm::loadAllCam() {
        cam->load();
}

MainForm::~MainForm() {
    cam->stop();
}

void MainForm::camera() {
    if(isStart){
        isStart = false;
        stopAllCam();
        widget.labelFrame->clear();
        box = cvRect(0,0,0,0);
        widget.labelFrame->setText("<Backspace para iniciar a camera>");
    }else{
        isStart = true;
        startAllCam();
    }
}

void MainForm::adicionar() {
    if(box.width!=0&&box.height!=0){
        Rect rectVaga = Rect(box.x+1,box.y+1,box.width-1,box.height-1);
        Mat imgVaga = cam->frame(rectVaga);
        RegistraVagaForm *registra = new RegistraVagaForm(imgVaga,rectVaga);
        int res = registra->exec(); 
        if (res==QDialog::Rejected) {
            box = cvRect(0,0,0,0);
            loadAllCam();
        }  
    }
}

void MainForm::keyPressEvent(QKeyEvent* ev) {
//inicia ou para as cameras se apertar backspace
    //cout <<  ev->modifiers() << endl;
    //cout <<  ev->key() << endl;
    if(ev->key() == BACKSPACE){
        camera();
    }
    
    if(ev->modifiers() == 33554432 && ev->key() == 68){
        debug();
    }
}

void MainForm::startAllCam() {
        cam->start();
    loadAllCam();
}

void MainForm::stopAllCam() {
        cam->stop();  
}

void MainForm::update() {
       draw_box();
       draw_vagas();
       QPixmap map = this->util.matToQPixmap(cam->frame);
       cam->frame_original = cam->frame;
       cvtColor(cam->frame_original, cam->frame_original,CV_BGR2RGB);
       widget.labelFrame->setPixmap(map);  
         
}

//EVENTOS CAPTURA DE MOUSE=========================================================
void MainForm::Mouse_Release() {
          drawing_box = false;
          if( box.width < 0 )
          {
              box.x += box.width;
              box.width *= -1;
          }
          if( box.height < 0 )
          {
              box.y += box.height;
              box.height *= -1;
          }
          draw_box();
}
void MainForm::Mouse_Pressed() {
    current_pos->setText(QString("x = %1, y = %2").arg(widget.labelFrame->x).arg(widget.labelFrame->y));
    drawing_box = true;
    widget.AdicionarButton->setEnabled(true);
    box = cvRect( widget.labelFrame->x, widget.labelFrame->y, 0, 0 );
}
void MainForm::Mouse_left() {
    if (drawing_box) {
       box = cvRect(0,0,0,0);
       widget.AdicionarButton->setEnabled(false);
    }
    drawing_box = false;
}
void MainForm::Mouse_current_pos() {
    current_pos->setText(QString("x = %1, y = %2").arg(widget.labelFrame->x).arg(widget.labelFrame->y));
    box.width = widget.labelFrame->x - box.x;
    box.height = widget.labelFrame->y - box.y;
    widget.AdicionarButton->setEnabled(true);
}

void MainForm::draw_box()
{
    try{
       cv::resize(cam->frame, cam->frame, Size(widget.labelFrame->width(), widget.labelFrame->height()), 0, 0, INTER_CUBIC);
       rectangle(cam->frame, cvPoint(box.x, box.y), cvPoint(box.x+box.width,box.y+box.height),
              cv::Scalar(255, 255, 255) ,1); 
    }catch(cv::Exception e){
        cout << "Ocorreu um erro >> draw_box(): " << e.msg << endl;
    }
}

void MainForm::draw_vagas() {
    cv::Rect rec;
        for(int j = 0; j < cam->vagas.size(); j++){
            rec = cam->vagas[j]->getRect();
            if(cam->vagas[j]->getStatus() == 1){
               //cv::resize(cameras[frame_atual]->frame, cameras[frame_atual]->frame, Size(widget.labelFrame->width(), widget.labelFrame->height()), 0, 0, INTER_CUBIC);
               rectangle(cam->frame, cvPoint(rec.x-1, rec.y-1), cvPoint((rec.x+rec.width)+1,(rec.y+rec.height)+1),
               Scalar(255,0,0) ,000.2); 
            }else{
               //cv::resize(cameras[frame_atual]->frame, cameras[frame_atual]->frame, Size(widget.labelFrame->width(), widget.labelFrame->height()), 0, 0, INTER_CUBIC);
               rectangle(cam->frame, cvPoint(rec.x-1, rec.y-1), cvPoint((rec.x+rec.width)+1,(rec.y+rec.height)+1),
               Scalar(0,255,0) ,000.2); 
            }
        }
}

