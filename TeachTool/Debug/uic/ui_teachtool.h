/********************************************************************************
** Form generated from reading UI file 'teachtool.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEACHTOOL_H
#define UI_TEACHTOOL_H

#include <ActiveQt/QAxWidget>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TeachToolClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QAxWidget *axWidget;
    QPushButton *buttonTextExtract;
    QPushButton *buttonPictExtract;
    QSpacerItem *verticalSpacer;

    void setupUi(QMainWindow *TeachToolClass)
    {
        if (TeachToolClass->objectName().isEmpty())
            TeachToolClass->setObjectName(QString::fromUtf8("TeachToolClass"));
        TeachToolClass->resize(600, 400);
        centralWidget = new QWidget(TeachToolClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        axWidget = new QAxWidget(centralWidget);
        axWidget->setObjectName(QString::fromUtf8("axWidget"));

        gridLayout->addWidget(axWidget, 0, 0, 3, 1);

        buttonTextExtract = new QPushButton(centralWidget);
        buttonTextExtract->setObjectName(QString::fromUtf8("buttonTextExtract"));
        buttonTextExtract->setMaximumSize(QSize(93, 16777215));

        gridLayout->addWidget(buttonTextExtract, 0, 1, 1, 1);

        buttonPictExtract = new QPushButton(centralWidget);
        buttonPictExtract->setObjectName(QString::fromUtf8("buttonPictExtract"));
        buttonPictExtract->setMaximumSize(QSize(93, 16777215));

        gridLayout->addWidget(buttonPictExtract, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 218, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        TeachToolClass->setCentralWidget(centralWidget);

        retranslateUi(TeachToolClass);

        QMetaObject::connectSlotsByName(TeachToolClass);
    } // setupUi

    void retranslateUi(QMainWindow *TeachToolClass)
    {
        TeachToolClass->setWindowTitle(QCoreApplication::translate("TeachToolClass", "TeachTool", nullptr));
        buttonTextExtract->setText(QCoreApplication::translate("TeachToolClass", "\346\217\220\345\217\226\346\226\207\345\255\227", nullptr));
        buttonPictExtract->setText(QCoreApplication::translate("TeachToolClass", "\346\217\220\345\217\226\345\233\276\347\211\207", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TeachToolClass: public Ui_TeachToolClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHTOOL_H
