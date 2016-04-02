/* 
 * File:   Util.h
 * Author: marcelo
 *
 * Created on 6 de Julho de 2015, 20:06
 */

#ifndef UTIL_H
#define	UTIL_H
#include<stdio.h>
#include <iostream>
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"


#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <time.h>
#include <QPixmap>
#include <QImage>
#include "QList"
#include "QSettings"

#define CAMINHO_IMAGENS "./ImagensVagas/"
#define PNG ".png"
#include <fstream>

using namespace std;
using namespace cv;
class Util {
public:
    Util();
    Util(const Util& orig);
    virtual ~Util();
    static char*        toChar(std::string arg);
    static char*        concateName(std::string name);
    static QPixmap      matToQPixmap(cv::Mat Img);
    static std::string  intToString(int number);
    
   
    
    
    static QList<int> listCameras();

private:

};

#endif	/* UTIL_H */