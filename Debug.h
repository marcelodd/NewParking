/* 
 * File:   Debug.h
 * Author: marcelo
 *
 * Created on 12 de Agosto de 2015, 21:35
 */

#ifndef _DEBUG_H
#define	_DEBUG_H

#include "ui_Debug.h"
#include "QMainWindow"
#include "Camera.h"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "QSettings"
class Camera;
class Debug : public QDialog {
    Q_OBJECT
public:
    Debug(Camera *camera);
    virtual ~Debug();
    
    int   _THRESHOLD,_MAX_VALUE;
    QSettings *settings;
    
public slots:
    void update();
    void sliderChangeThreshold(int);
    void sliderChangeMaxValue(int);
    void salvar_settings();
    
private:
    Ui::Debug widget;
    Camera *cam;
};

#endif	/* _DEBUG_H */
