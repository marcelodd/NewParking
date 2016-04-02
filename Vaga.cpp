/* 
 * File:   Vaga.cpp
 * Author: marcelo
 * 
 * Created on 6 de Julho de 2015, 20:53
 */

#include "Vaga.h"

Vaga::Vaga() {  
}
Vaga::Vaga(std::string Descricao, cv::Rect Box){
    descricao = Descricao;
    box = Box;
}

Vaga::Vaga(const Vaga& orig) {
}

Vaga::~Vaga() {
}
int Vaga::getId(){
  return this->vaga_id; 
}
void Vaga::setId(int Vaga_ID){
   this->vaga_id = Vaga_ID; 
}
std::string Vaga::getDescricao() {
    return this->descricao;
}

void Vaga::setDescricao(std::string Descricao) {
    this->descricao = Descricao;
}

cv::Rect Vaga::getRect() {
    return this->box;
}

void Vaga::setRect(cv::Rect Box) {
    this->box = Box;
}

int Vaga::getStatus() {
    return this->status;
}

void Vaga::setStatus(int Status) {
    this->status = Status;
}








