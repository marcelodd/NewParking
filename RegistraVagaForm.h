/* 
 * File:   RegistraVagaForm.h
 * Author: marcelo
 *
 * Created on 6 de Agosto de 2015, 12:45
 */

#ifndef _REGISTRAVAGAFORM_H
#define	_REGISTRAVAGAFORM_H

#include "ui_RegistraVagaForm.h"
#include "Util.h"
//#include "opencv2/objdetect/objdetect.hpp"
//#include "opencv2/highgui/highgui.hpp"
//#include "opencv2/imgproc/imgproc.hpp"
//#include "iostream"
#include "Vaga.h"
#include "VagaDao.h"
using namespace cv;
using namespace std;
class RegistraVagaForm : public QDialog {
    Q_OBJECT
public:
    explicit RegistraVagaForm(cv::Mat imgVaga, cv::Rect recVaga);
    virtual ~RegistraVagaForm();
    
   QString nome() const;
   public slots:
   void setLabel();
   void salvar();
private:
    Ui::RegistraVagaForm widget;
    cv::Mat image;
    cv::Rect box;
    int camId;
    Util util;
    Vaga vaga;
    VagaDao *dao;
    
};

#endif	/* _REGISTRAVAGAFORM_H */
