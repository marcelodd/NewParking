/* 
 * File:   Util.cpp
 * Author: marcelo
 * 
 * Created on 6 de Julho de 2015, 20:06
 */

#include "Util.h"

Util::Util() {
}

Util::Util(const Util& orig) {
    
}

Util::~Util() {
}
char* Util::toChar(std::string arg) {   
    return const_cast<char*>(arg.c_str());
}

char* Util::concateName(std::string NAME) {
    std::string NOME_COCATENADO = CAMINHO_IMAGENS+NAME+PNG;   
    return const_cast<char*>(NOME_COCATENADO.c_str());
}

QPixmap Util::matToQPixmap(cv::Mat temp){
    QImage dest = QImage((uchar*) temp.data, temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
    QPixmap map = QPixmap::fromImage(dest);
    return map;
}

string Util::intToString(int number){
	//this function has a number input and string output
	std::stringstream ss;
	ss << number;
	return ss.str();
}

QList<int> Util::listCameras() {
    QList<int> devices;
    ofstream myfile;
    for(int i = 0; i < 10; i++ ){
       myfile.open (toChar("/dev/video"+intToString(i)));
       if(myfile.is_open()){
           devices.append(i);
       }
       myfile.close();
    }
    return devices;
}










