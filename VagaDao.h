/* 
 * File:   VagaDao.h
 * Author: marcelo
 *
 * Created on 6 de Agosto de 2015, 19:14
 */

#ifndef VAGADAO_H
#define	VAGADAO_H
#include "Connexao.h"
#include "Vaga.h"
#include "QMessageBox"
using namespace cv;
class VagaDao {
public:
    VagaDao(QString connectioID);
    VagaDao(const VagaDao& orig);
    virtual ~VagaDao();
    
    
    bool insert(char *vaga_descricao, cv::Rect box);
    bool update(int vaga_id, int vaga_status);
    QList<Vaga*> select();
    bool remove(int vaga_id);
    Connexao *con;
private:
    QSqlQuery query;
    QList<Vaga*> vagas = QList<Vaga*>();
    Vaga *vaga;
    cv::Rect box;
    
};

#endif	/* VAGADAO_H */

