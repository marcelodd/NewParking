/* 
 * File:   Connexao.cpp
 * Author: marcelo
 * 
 * Created on 6 de Agosto de 2015, 12:45
 */

#include "Connexao.h"
#include <iostream>

using namespace std;
QString conn;
Connexao::Connexao(QString connectioID) {
    db = QSqlDatabase::addDatabase("QMYSQL",connectioID);
    db.setHostName("127.0.0.1");
    db.setDatabaseName("IFSP_PARKING");
    db.setUserName("root");
    db.setPassword("root");
    conn = connectioID;
}

Connexao::Connexao(const Connexao& orig) {
}

Connexao::~Connexao() {
    db = QSqlDatabase();
    db.removeDatabase(conn);
}

void Connexao::open() {
    try{
        db.open();
    }catch(int e){
        cout << "Erro ao tentar estabelecer a conexao : " << this->db.lastError().text().toStdString() << endl;
    }
}

void Connexao::close() {
     try{
        db.close();
    }catch(int e){
        cout << "Erro ao tentar fechar a conexao : " << this->db.lastError().text().toStdString() << endl;
    }
}



