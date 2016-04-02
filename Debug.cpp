/*
 * File:   Debug.cpp
 * Author: marcelo
 *
 * Created on 12 de Agosto de 2015, 21:35
 */

#include "Debug.h"
QTimer *timer;
Debug::Debug(Camera *camera) {
    widget.setupUi(this);
    cam = camera;
    settings = new QSettings("NewParking.ini", QSettings::IniFormat);
    settings->beginGroup("PARAMETROS");
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    timer->start(0);
    
    connect(widget.TSlider,SIGNAL(valueChanged(int)),this,SLOT(sliderChangeThreshold(int)));
    connect(widget.MSlider,SIGNAL(valueChanged(int)),this,SLOT(sliderChangeMaxValue(int)));
    connect(widget.SalvarButton,SIGNAL(clicked()),this,SLOT(salvar_settings()));
    
    _THRESHOLD = settings->value("threshold").toInt();
    widget.TSlider->setValue(_THRESHOLD);
    _MAX_VALUE = settings->value("max_value").toInt();
    widget.MSlider->setValue(_MAX_VALUE);
}

void Debug::salvar_settings() {
    settings->setValue("threshold",_THRESHOLD);
    settings->setValue("max_value",_MAX_VALUE);
}

void Debug::sliderChangeMaxValue(int m) {
    _MAX_VALUE = m;
    widget.Valoreslabel->setText(QString("Threshol: %1  Max Value:  %2").arg(_THRESHOLD).arg(_MAX_VALUE));
}

void Debug::sliderChangeThreshold(int t) {
    _THRESHOLD = t;
    widget.Valoreslabel->setText(QString("Threshol: %1  Max Value:  %2").arg(_THRESHOLD).arg(_MAX_VALUE));
}


Debug::~Debug() {
}

void Debug::update() {
    
        Mat image_blur, image_canny;
        Mat image_gray(cam->frame_original.cols,cam->frame_original.rows,cam->frame_original.type());
        cvtColor(cam->frame_original, image_gray, CV_BGR2GRAY);
            
        blur( image_gray, image_blur, Size(3,3) );
    
        Canny(image_blur, image_canny, _THRESHOLD, _MAX_VALUE);
        
        cvtColor(image_canny , image_canny, CV_GRAY2BGR);
        QPixmap map = cam->util.matToQPixmap(image_canny);
        widget.Framelabel->setPixmap(map);    
}

