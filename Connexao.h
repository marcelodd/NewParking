/* 
 * File:   Connexao.h
 * Author: marcelo
 *
 * Created on 6 de Agosto de 2015, 12:45
 */

#ifndef CONNEXAO_H
#define	CONNEXAO_H

#include "QtCore/qmutex.h"
#include "QtSql/QSqlDatabase"
#include "QtSql"
#include <iostream>

using namespace std;


class Connexao {
public:
    Connexao(QString connectioID);
    Connexao(const Connexao& orig);
    virtual ~Connexao();
    
    QSqlDatabase db;
    void open();
    void close();
private:
    
};

#endif	/* CONNEXAO_H */

