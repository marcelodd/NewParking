/* 
 * File:   Vaga.h
 * Author: marcelo
 *
 * Created on 6 de Agosto de 2015, 19:09
 */

#ifndef VAGA_H
#define	VAGA_H
#include <iostream>
#include <stdio.h>
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;

class Vaga {
public:
    Vaga();
    Vaga(std::string Descricao, cv::Rect Box);
    Vaga(const Vaga& orig);
    virtual ~Vaga();
    
    std::string getDescricao();
    void setDescricao(std::string Descricao);
    
    cv::Rect getRect();
    void setRect(cv::Rect box);
    
    int getStatus();
    void setStatus(int status);
    
    int getId();
    void setId(int vagaId);
    
    int getCamId();
    void setCamId(int camId);
private:
    int         vaga_id;
    std::string descricao;
    cv::Rect    box;
    int         status;

};

#endif	/* VAGA_H */

