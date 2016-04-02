/*
 * F
#include "MainForm.h"ile:   main.cpp
 * Author: marcelo
 *
 * Created on 6 de Agosto de 2015, 12:43
 */

#include <QApplication>
#include <QWidget>
#include "MainForm.h"

int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);
    //QApplication::setStyle("plastique");
    //QApplication::setStyle("motif");
    //QApplication::setStyle("windows");
    //QApplication::setStyle("cde");
    //QApplication::setStyle("gtk");
    //QApplication::setStyle("cleanlooks");
    QApplication::setStyle("windowsxp");
    //QApplication::setStyle("windowsvista");
    //QApplication::setStyle("macintosh");
    QApplication app(argc, argv);
    MainForm main;
    main.show();
    // create and show your widgets here
    
    return app.exec();
}
