/* 
 * File:   VagaDao.cpp
 * Author: marcelo
 * 
 * Created on 6 de Agosto de 2015, 19:14
 */

#include "VagaDao.h"
#include "Vaga.h"
#include "Util.h"

VagaDao::VagaDao(QString connectioID) {
    con = new Connexao(connectioID);
}

VagaDao::VagaDao(const VagaDao& orig) {
}

VagaDao::~VagaDao() {
}

bool VagaDao::insert(char* vaga_descricao, cv::Rect box) {
    query = QSqlQuery(con->db);
    con->open();
    query.prepare("INSERT INTO VAGA (DESCRICAO, BOX_X, BOX_Y, BOX_WIDTH, BOX_HEIGHT, STATUS) "
                  "VALUES (:DESCRICAO, :BOX_X, :BOX_Y, :BOX_WIDTH, :BOX_HEIGHT, :STATUS)");
    query.bindValue(":DESCRICAO", vaga_descricao);
    query.bindValue(":BOX_X",box.x);
    query.bindValue(":BOX_Y",box.y);
    query.bindValue(":BOX_WIDTH",box.width);
    query.bindValue(":BOX_HEIGHT",box.height);
    query.bindValue(":STATUS",0);
    if(!query.exec()){
        return false;
        con->close();
    }  
    con->close();
    return true;
}

bool VagaDao::update(int vaga_id,int vaga_status){
    query = QSqlQuery(con->db);
    con->open();
    query.prepare("UPDATE VAGA SET STATUS = :Status WHERE VAGA_ID = :Vaga_ID");
    query.bindValue(":Status",vaga_status);
    query.bindValue(":Vaga_ID",vaga_id);
        
    if(!query.exec()){
        return false;
        con->close();
    }
    con->close();
    return true;
}

QList<Vaga*> VagaDao::select(){ 
    query = QSqlQuery(con->db);
    con->open();
              query.prepare("SELECT VAGA_ID, DESCRICAO, BOX_X, BOX_Y, BOX_WIDTH, BOX_HEIGHT, STATUS "
                       "FROM VAGA"
                       " ORDER BY DESCRICAO ASC");
        if(!query.exec()){
            QMessageBox ms;
            ms.setText("Erro ao selecionar vagas aaa");
            ms.exec();
            cout << "Erro ao selecionar vagas : " << query.lastError().text().toStdString() << endl;
        }else{
            while (query.next()) {
            vaga = new Vaga();
            vaga->setId(query.value(0).toInt());
            vaga->setDescricao(query.value(1).toString().toStdString());
            box.x      = query.value(2).toInt();
            box.y      = query.value(3).toInt();
            box.width  = query.value(4).toInt();
            box.height = query.value(5).toInt();
            vaga->setRect(box);
            vaga->setStatus(query.value(6).toInt());
            vagas.append(vaga);
            }   
        }
    con->close(); 
    return vagas;
}






