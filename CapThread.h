/* 
 * File:   CapThread.h
 * Author: marcelo
 *
 * Created on 7 de Agosto de 2015, 20:43
 */

#ifndef CAPTHREAD_H
#define	CAPTHREAD_H
#include "QtCore"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "iostream"
#include "QMutex"
#include "VagaDao.h"
#include "Vaga.h"
#include "Util.h"
#include "QWidget"
#include "QObject"
#include "QSettings"
using namespace std;
class Camera;
class Vaga;
class VagaDao;

using namespace cv;
class CapThread:public QThread {
    Q_OBJECT
public:
   explicit CapThread(Camera *camera);
   virtual ~CapThread();
    
    void run();
    void stop();
    void compara();
    void load();
    void ini();
    
    
    signals:
    void fim();
    void result();
    void timeOut();
    
public slots:
    void update();
    
 
    
private:
    int   _THRESHOLD,_MAX_VALUE;
    QSettings *settings;
    QTimer *timer;
    QMutex mutex;
    Util util;
    int camera_id;
    volatile bool stopped;
    Camera *cam;
    VagaDao *dao;
    QString threadId;
    
};

#endif	/* CAPTHREAD_H */

