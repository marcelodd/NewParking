# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Debug/GNU-Linux
TARGET = NewParking
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += link_pkgconfig debug 
PKGCONFIG += opencv opencv
QT = core gui widgets sql
SOURCES += Camera.cpp CapThread.cpp Connexao.cpp Debug.cpp MainForm.cpp RegistraVagaForm.cpp Util.cpp Vaga.cpp VagaDao.cpp label_frame.cpp main.cpp
HEADERS += Camera.h CapThread.h Connexao.h Debug.h MainForm.h RegistraVagaForm.h Util.h Vaga.h VagaDao.h label_frame.h
FORMS += Debug.ui MainForm.ui RegistraVagaForm.ui
RESOURCES += Resource.qrc
TRANSLATIONS +=
OBJECTS_DIR = build/Debug/GNU-Linux
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += 
INCLUDEPATH += 
LIBS += 
