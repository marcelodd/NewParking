/* 
 * File:   Camera.cpp
 * Author: marcelo
 * 
 * Created on 6 de Agosto de 2015, 18:27
 */

#include "Camera.h"
#include "QWidget"

using namespace cv;
Camera::Camera(int index) {
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    camera_index = index;
    dao = new VagaDao(QString::number((camera_index+99)*77));
    myThread = new CapThread(this);
    connect(myThread,SIGNAL(result()),this,SLOT(update()));
}

Camera::~Camera() {
}

void Camera::fimdociclo() {
    emit result();
}


void Camera::start() {
    myThread->ini();
    if(!myThread->isRunning()){
       myThread->start();
       //cout << "Iniando thread..." << camera_index << endl;
    }

}

void Camera::stop() {
    //cout << "Parando camera..." << endl;
    myThread->stop();
    if(myThread->isRunning()){
      myThread->terminate();
      //cout << "Parando thread..." << endl;
    } 
}

void Camera::update() {
    emit timeOut();
}

void Camera::load() {
    vagas.clear();
    images.clear();
    vagas = dao->select();
    Mat img;
    for(int i = 0; i < vagas.size(); i ++){
        //cout << "Pegando vaga "<< i << " camera "<< camera_index << endl;
        img = imread(util.concateName(vagas[i]->getDescricao()));
        images.append(img);
    }
}







