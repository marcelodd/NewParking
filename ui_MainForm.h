/********************************************************************************
** Form generated from reading UI file 'MainForm.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINFORM_H
#define UI_MAINFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>
#include <label_frame.h>

QT_BEGIN_NAMESPACE

class Ui_MainForm
{
public:
    QAction *actionDebug;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *CameraButton;
    QPushButton *AdicionarButton;
    QSpacerItem *horizontalSpacer;
    label_frame *labelFrame;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menu_Debug;

    void setupUi(QMainWindow *MainForm)
    {
        if (MainForm->objectName().isEmpty())
            MainForm->setObjectName(QString::fromUtf8("MainForm"));
        MainForm->resize(662, 584);
        MainForm->setMinimumSize(QSize(662, 584));
        MainForm->setMaximumSize(QSize(662, 584));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../Imagens/vaga.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainForm->setWindowIcon(icon);
        actionDebug = new QAction(MainForm);
        actionDebug->setObjectName(QString::fromUtf8("actionDebug"));
        centralwidget = new QWidget(MainForm);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        CameraButton = new QPushButton(centralwidget);
        CameraButton->setObjectName(QString::fromUtf8("CameraButton"));
        CameraButton->setFocusPolicy(Qt::NoFocus);
        CameraButton->setLayoutDirection(Qt::RightToLeft);
        CameraButton->setAutoFillBackground(true);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Icones/Icones/Webcam.png"), QSize(), QIcon::Normal, QIcon::Off);
        CameraButton->setIcon(icon1);

        horizontalLayout_3->addWidget(CameraButton);

        AdicionarButton = new QPushButton(centralwidget);
        AdicionarButton->setObjectName(QString::fromUtf8("AdicionarButton"));
        AdicionarButton->setEnabled(false);
        AdicionarButton->setFocusPolicy(Qt::NoFocus);
        AdicionarButton->setLayoutDirection(Qt::RightToLeft);
        AdicionarButton->setAutoFillBackground(true);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Icones/Icones/aplicativos_0847_Add.png"), QSize(), QIcon::Normal, QIcon::Off);
        AdicionarButton->setIcon(icon2);

        horizontalLayout_3->addWidget(AdicionarButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        labelFrame = new label_frame(centralwidget);
        labelFrame->setObjectName(QString::fromUtf8("labelFrame"));
        labelFrame->setMinimumSize(QSize(644, 484));
        labelFrame->setMaximumSize(QSize(644, 484));
        labelFrame->setFrameShape(QFrame::WinPanel);
        labelFrame->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelFrame, 0, 0, 1, 1);

        MainForm->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainForm);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainForm->setStatusBar(statusbar);
        menubar = new QMenuBar(MainForm);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 662, 25));
        menu_Debug = new QMenu(menubar);
        menu_Debug->setObjectName(QString::fromUtf8("menu_Debug"));
        MainForm->setMenuBar(menubar);

        menubar->addAction(menu_Debug->menuAction());
        menu_Debug->addAction(actionDebug);

        retranslateUi(MainForm);

        QMetaObject::connectSlotsByName(MainForm);
    } // setupUi

    void retranslateUi(QMainWindow *MainForm)
    {
        MainForm->setWindowTitle(QApplication::translate("MainForm", "MainForm", 0, QApplication::UnicodeUTF8));
        actionDebug->setText(QApplication::translate("MainForm", "&Debug", 0, QApplication::UnicodeUTF8));
        CameraButton->setText(QString());
        AdicionarButton->setText(QString());
        labelFrame->setText(QApplication::translate("MainForm", "<Backspace para iniciar a camera> ", 0, QApplication::UnicodeUTF8));
        menu_Debug->setTitle(QApplication::translate("MainForm", "Menu", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainForm: public Ui_MainForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINFORM_H
