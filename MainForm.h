/* 
 * File:   MainForm.h
 * Author: marcelo
 *
 * Created on 6 de Agosto de 2015, 12:44
 */

#ifndef _MAINFORM_H
#define	_MAINFORM_H
#define BACKSPACE 32
#define ARROW_BACK 16777234
#define ARROW_FORWARD 16777236






#include "Util.h"
#include "ui_MainForm.h"
#include "QKeyEvent"
#include "QPixmap"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "QObject"
#include "QWidget"
#include "RegistraVagaForm.h"
#include "Camera.h"
#include "QSettings"
using namespace cv;
using namespace std;

class MainForm : public QMainWindow {
    Q_OBJECT
public:
    MainForm();
    virtual ~MainForm();
    
    virtual void keyPressEvent(QKeyEvent *ev);
    
    
    void startAllCam();
    void stopAllCam();
    void connectAllCam();
    void initAllCam();
    void debug();
    
    void draw_box();
    void draw_vagas();
public slots:
    void update();
    void loadAllCam();
    
    void Mouse_current_pos();
    void Mouse_Pressed();
    void Mouse_left();
    void Mouse_Release();
    
    void camera();
    void adicionar();
      

private:
    Camera *cam;
    Mat my_frame;
    Util util;
    bool drawing_box;
    bool isStart;
    Rect box;
    QLabel *current_pos;
    QLabel *current_camera;
    Ui::MainForm widget;
    bool isMaximizado;
    int STATE_WIDTH , STATE_HEIGTH ;
    QSettings *settings;
};

#endif	/* _MAINFORM_H */
