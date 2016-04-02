/* 
 * File:   Camera.h
 * Author: marcelo
 *
 * Created on 6 de Agosto de 2015, 18:27
 */

#ifndef CAMERA_H
#define	CAMERA_H
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "QWidget"
#include "QTimer"
#include "iostream"
#include "CapThread.h"
#include "QList"
#include "Vaga.h"
#include "VagaDao.h"
#include "Util.h"
#define CAMERA_TIMER 0

using namespace std;
using namespace cv;
class CapThread;
class Camera:public QObject {
    Q_OBJECT
public:
    Camera(int camera_index);
    virtual ~Camera();
    
    void start();
    void stop();
    void load();
    
    Mat frame;
    Mat frame_original;
    QList<Vaga*> vagas;
    QList<Mat> images;
    
    
    Util util;
    QTimer *timer;
    VideoCapture cap;
    CapThread *myThread;
    int camera_index;
    Vaga *vaga;
    VagaDao *dao;
    
    signals:
    void timeOut();
    void result();

  
public slots:
    void update();
    void fimdociclo();
private:
   
};

#endif	/* CAMERA_H */

