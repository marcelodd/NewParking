/********************************************************************************
** Form generated from reading UI file 'Debug.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEBUG_H
#define UI_DEBUG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <label_frame.h>

QT_BEGIN_NAMESPACE

class Ui_Debug
{
public:
    QGridLayout *gridLayout;
    QCheckBox *CannycheckBox;
    QPushButton *SalvarButton;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSlider *TSlider;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSlider *MSlider;
    label_frame *Framelabel;
    QLabel *Valoreslabel;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *Debug)
    {
        if (Debug->objectName().isEmpty())
            Debug->setObjectName(QString::fromUtf8("Debug"));
        Debug->resize(664, 636);
        gridLayout = new QGridLayout(Debug);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        CannycheckBox = new QCheckBox(Debug);
        CannycheckBox->setObjectName(QString::fromUtf8("CannycheckBox"));
        CannycheckBox->setEnabled(false);
        CannycheckBox->setChecked(true);

        gridLayout->addWidget(CannycheckBox, 0, 0, 1, 1);

        SalvarButton = new QPushButton(Debug);
        SalvarButton->setObjectName(QString::fromUtf8("SalvarButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icones/Icones/aplicativos_0832_Save.png"), QSize(), QIcon::Normal, QIcon::Off);
        SalvarButton->setIcon(icon);

        gridLayout->addWidget(SalvarButton, 0, 2, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(Debug);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        TSlider = new QSlider(Debug);
        TSlider->setObjectName(QString::fromUtf8("TSlider"));
        TSlider->setMaximum(250);
        TSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(TSlider);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(Debug);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setEnabled(true);

        horizontalLayout_2->addWidget(label_2);

        MSlider = new QSlider(Debug);
        MSlider->setObjectName(QString::fromUtf8("MSlider"));
        MSlider->setEnabled(true);
        MSlider->setMaximum(250);
        MSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(MSlider);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        Framelabel = new label_frame(Debug);
        Framelabel->setObjectName(QString::fromUtf8("Framelabel"));
        Framelabel->setMinimumSize(QSize(644, 484));
        Framelabel->setMaximumSize(QSize(644, 484));
        Framelabel->setFrameShape(QFrame::WinPanel);
        Framelabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(Framelabel);


        gridLayout->addLayout(verticalLayout_2, 1, 0, 1, 3);

        Valoreslabel = new QLabel(Debug);
        Valoreslabel->setObjectName(QString::fromUtf8("Valoreslabel"));

        gridLayout->addWidget(Valoreslabel, 2, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);


        retranslateUi(Debug);

        QMetaObject::connectSlotsByName(Debug);
    } // setupUi

    void retranslateUi(QDialog *Debug)
    {
        Debug->setWindowTitle(QApplication::translate("Debug", "Debug", 0, QApplication::UnicodeUTF8));
        CannycheckBox->setText(QApplication::translate("Debug", "Canny", 0, QApplication::UnicodeUTF8));
        SalvarButton->setText(QString());
        label->setText(QApplication::translate("Debug", "Threahold", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Debug", "Max Value", 0, QApplication::UnicodeUTF8));
        Framelabel->setText(QApplication::translate("Debug", "<Backspace para iniciar a camera> ", 0, QApplication::UnicodeUTF8));
        Valoreslabel->setText(QApplication::translate("Debug", "Valores", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Debug: public Ui_Debug {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEBUG_H
