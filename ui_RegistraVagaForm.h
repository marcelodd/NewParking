/********************************************************************************
** Form generated from reading UI file 'RegistraVagaForm.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRAVAGAFORM_H
#define UI_REGISTRAVAGAFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_RegistraVagaForm
{
public:
    QGridLayout *gridLayout;
    QLabel *ImageVagalabel;
    QLineEdit *DescricaoVagaEdit;
    QPushButton *SalvarVagaButton;

    void setupUi(QDialog *RegistraVagaForm)
    {
        if (RegistraVagaForm->objectName().isEmpty())
            RegistraVagaForm->setObjectName(QString::fromUtf8("RegistraVagaForm"));
        RegistraVagaForm->resize(335, 326);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../Imagens/vaga.png"), QSize(), QIcon::Normal, QIcon::Off);
        RegistraVagaForm->setWindowIcon(icon);
        RegistraVagaForm->setModal(true);
        gridLayout = new QGridLayout(RegistraVagaForm);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        ImageVagalabel = new QLabel(RegistraVagaForm);
        ImageVagalabel->setObjectName(QString::fromUtf8("ImageVagalabel"));

        gridLayout->addWidget(ImageVagalabel, 0, 0, 1, 1);

        DescricaoVagaEdit = new QLineEdit(RegistraVagaForm);
        DescricaoVagaEdit->setObjectName(QString::fromUtf8("DescricaoVagaEdit"));

        gridLayout->addWidget(DescricaoVagaEdit, 1, 0, 1, 1);

        SalvarVagaButton = new QPushButton(RegistraVagaForm);
        SalvarVagaButton->setObjectName(QString::fromUtf8("SalvarVagaButton"));

        gridLayout->addWidget(SalvarVagaButton, 2, 0, 1, 1);


        retranslateUi(RegistraVagaForm);

        QMetaObject::connectSlotsByName(RegistraVagaForm);
    } // setupUi

    void retranslateUi(QDialog *RegistraVagaForm)
    {
        RegistraVagaForm->setWindowTitle(QApplication::translate("RegistraVagaForm", "Salvar Vaga", 0, QApplication::UnicodeUTF8));
        ImageVagalabel->setText(QString());
        SalvarVagaButton->setText(QApplication::translate("RegistraVagaForm", "PushButton", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RegistraVagaForm: public Ui_RegistraVagaForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRAVAGAFORM_H
