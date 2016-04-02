/* 
 * File:   label_frame.cpp
 * Author: marcelo
 * 
 * Created on 6 de Agosto de 2015, 13:01
 */

#include "label_frame.h"

label_frame::label_frame(QWidget *parent) {
    QLabel(parent,0);
}

void label_frame::mouseMoveEvent(QMouseEvent* ev) {
    this->x = ev->x();
    this->y = ev->y();
    emit Mouse_Position();
}

void label_frame::mousePressEvent(QMouseEvent* ev) {
    this->x = ev->x();
    this->y = ev->y();
    emit Mouse_Pressed();
}

void label_frame::leaveEvent(QEvent*) {
    emit Mouse_Left();
}

void label_frame::mouseReleaseEvent(QMouseEvent* ev) {
    emit Mouse_Release();
}





