/* 
 * File:   CapThread.cpp
 * Author: marcelo
 * 
 * Created on 7 de Agosto de 2015, 20:43
 */

#include "CapThread.h"
#include "Camera.h"
#include "Camera.h"
#include "QSettings"
#include "sys/time.h"
#include "MainForm.h"

int TotalContornos, TotalExecucoes;
CapThread::CapThread(Camera *camera) {
    TotalContornos = 0, TotalExecucoes = 0;
    settings = new QSettings("NewParking.ini", QSettings::IniFormat);
    settings->beginGroup("PARAMETROS");
    _THRESHOLD = settings->value("threshold").toInt();
    _MAX_VALUE = settings->value("max_value").toInt();
    cam = camera;
    
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    
    threadId = QString::number((unsigned long long)this->currentThreadId()+cam->camera_index*77);
    cam->dao = new VagaDao(threadId+QString::number(cam->camera_index));
}


CapThread::~CapThread() {
}

void CapThread::run() {
    mutex.lock();
    while (!stopped) {
      sleep(5);
      //cout << "Thread da camera " << cam->camera_index << endl;
      compara();
    }
    mutex.unlock();
}

void CapThread::update() {
    cam->cap >> cam->frame;
    cvtColor(cam->frame, cam->frame,CV_BGR2RGB);
    emit result();  
}

void CapThread::stop() {
    timer->stop();
    cam->cap.release();
    stopped = true;
}

void CapThread::ini() {
     if(cam->cap.open(cam->camera_index)){
        timer->start();
         //update();
        //cout << "Iniando camera..." << endl;
    }else{
        cout << "Erro ao iniciar camera..." << endl;
    }
    stopped = false;
}

void CapThread::compara() {
  try{
    
    struct timeval timeInicioPorComparacao, timeFimPorComparacao, timeInicio, timeFim; 
    
    Mat image_base, image_frame, image_frameGray, image_baseGray, image_frameThr, image_baseThr;
    Rect region_of_interest; 
    vector<vector<Point> > base_contours,frame_contours;
    vector<Vec4i> base_hierarchy,frame_hierarchy;
    
    gettimeofday(&timeInicio, NULL);
        for (int i = 0; i < cam->vagas.size(); i++) { 
            gettimeofday(&timeInicioPorComparacao, NULL);
            image_frame = cam->frame;
            region_of_interest = cam->vagas[i]->getRect();
            image_frame = image_frame(region_of_interest);
            
            image_base = cam->images[i];
            cvtColor(image_frame, image_frameGray, CV_BGR2GRAY);
            cvtColor(image_base, image_baseGray, CV_BGR2GRAY);
            blur( image_frameGray, image_frameGray, Size(3,3) );
            blur( image_baseGray, image_baseGray, Size(3,3) );
            Canny(image_frameGray,image_frameThr, _THRESHOLD, _MAX_VALUE,3);
            Canny(image_baseGray,image_baseThr, _THRESHOLD, _MAX_VALUE,3);
            findContours(image_baseThr, base_contours, base_hierarchy,CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE);
            findContours(image_frameThr, frame_contours, frame_hierarchy,CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE);
            
                if((frame_contours.size() - base_contours.size()) > 1){
                    cam->vagas[i]->setStatus(1);
                    cam->dao->update(cam->vagas[i]->getId(),1);
                    TotalExecucoes++;
                    TotalContornos+=frame_contours.size();
                    cout << "Total Execuções    > " << TotalExecucoes << endl;
                    cout << "Total Contornos    > " << TotalContornos << endl;
                    cout << "Média de Contornos > " << TotalContornos/TotalExecucoes << endl;
                   // emit result();
                }else {
                    cam->vagas[i]->setStatus(0);
                    cam->dao->update(cam->vagas[i]->getId(),0);
                   // emit result();
                }
            gettimeofday(&timeFimPorComparacao, NULL);
        }
    gettimeofday(&timeFim, NULL);
    int t = (int) (1000 * (timeFim.tv_sec - timeInicio.tv_sec) + (timeFim.tv_usec - timeInicio.tv_usec) / 1000);
    int t2 = (int) (1000 * (timeFimPorComparacao.tv_sec - timeInicioPorComparacao.tv_sec) + (timeFimPorComparacao.tv_usec - timeInicioPorComparacao.tv_usec) / 1000);
    cout << "Tempo de Execução (Por Vaga) > " << (float)t2/1000 << " Segundos" << endl;
    cout << "Tempo de Execução (Total)    > " << (float)t/1000 << " Segundos" << endl; 
    emit result();
   }catch(cv::Exception e){
       cout<<" Erro ao comparar imagens :" << e.msg << endl;
   }catch(std::exception e){
       cout<<" Erro ao comparar imagens 2:" << e.what() << endl;
   }
}

void CapThread::load() {
    cam->vagas.clear();
    cam->images.clear();
    cam->dao = new VagaDao(threadId);
    cam->vagas = cam->dao->select();
    Mat img;
    for(int i = 0; i < cam->vagas.size(); i ++){
        //cout << "Pegando vaga "<< i << " camera "<< cam->camera_index << endl;
        img = imread(util.concateName(cam->vagas[i]->getDescricao()));
        cam->images.append(img);
    }
}





