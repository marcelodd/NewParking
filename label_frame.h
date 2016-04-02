/* 
 * File:   label_frame.h
 * Author: marcelo
 *
 * Created on 6 de Agosto de 2015, 13:01
 */

#ifndef LABEL_FRAME_H
#define	LABEL_FRAME_H

#include "QtCore"
#include "QLabel"
#include "QtGui/QMouseEvent"
#include "QEvent"

class label_frame:public QLabel {
    Q_OBJECT
public:
    explicit label_frame(QWidget *parent);
    
    virtual void mouseMoveEvent(QMouseEvent* ev);

    virtual void mousePressEvent(QMouseEvent*);

    virtual void mouseReleaseEvent(QMouseEvent* ev);
    
    virtual void leaveEvent(QEvent*);
    
    int x,y;
    
   signals:
   void Mouse_Pressed();
   void Mouse_Position();
   void Mouse_Left();
   void Mouse_Release();

     public slots:

};

#endif	/* LABEL_FRAME_H */

