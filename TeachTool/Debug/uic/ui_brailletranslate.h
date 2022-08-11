/********************************************************************************
** Form generated from reading UI file 'brailletranslate.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BRAILLETRANSLATE_H
#define UI_BRAILLETRANSLATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BrailleTranslateClass
{
public:
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer;
    QPushButton *buttonSelectFile;
    QPushButton *buttonTranslate;
    QGridLayout *gridLayout;
    QLabel *labelPlainText;
    QPlainTextEdit *texteditBraille;
    QLabel *labelBrailleText;
    QPlainTextEdit *texteditPlain;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *BrailleTranslateClass)
    {
        if (BrailleTranslateClass->objectName().isEmpty())
            BrailleTranslateClass->setObjectName(QString::fromUtf8("BrailleTranslateClass"));
        BrailleTranslateClass->resize(647, 483);
        gridLayout_3 = new QGridLayout(BrailleTranslateClass);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalSpacer = new QSpacerItem(20, 318, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 2, 0, 1, 1);

        buttonSelectFile = new QPushButton(BrailleTranslateClass);
        buttonSelectFile->setObjectName(QString::fromUtf8("buttonSelectFile"));

        gridLayout_2->addWidget(buttonSelectFile, 0, 0, 1, 1);

        buttonTranslate = new QPushButton(BrailleTranslateClass);
        buttonTranslate->setObjectName(QString::fromUtf8("buttonTranslate"));

        gridLayout_2->addWidget(buttonTranslate, 1, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        labelPlainText = new QLabel(BrailleTranslateClass);
        labelPlainText->setObjectName(QString::fromUtf8("labelPlainText"));

        gridLayout->addWidget(labelPlainText, 0, 1, 1, 1);

        texteditBraille = new QPlainTextEdit(BrailleTranslateClass);
        texteditBraille->setObjectName(QString::fromUtf8("texteditBraille"));

        gridLayout->addWidget(texteditBraille, 3, 1, 1, 1);

        labelBrailleText = new QLabel(BrailleTranslateClass);
        labelBrailleText->setObjectName(QString::fromUtf8("labelBrailleText"));

        gridLayout->addWidget(labelBrailleText, 2, 1, 1, 1);

        texteditPlain = new QPlainTextEdit(BrailleTranslateClass);
        texteditPlain->setObjectName(QString::fromUtf8("texteditPlain"));

        gridLayout->addWidget(texteditPlain, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 1, 3, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);


        retranslateUi(BrailleTranslateClass);

        QMetaObject::connectSlotsByName(BrailleTranslateClass);
    } // setupUi

    void retranslateUi(QWidget *BrailleTranslateClass)
    {
        BrailleTranslateClass->setWindowTitle(QCoreApplication::translate("BrailleTranslateClass", "BrailleTranslate", nullptr));
        buttonSelectFile->setText(QCoreApplication::translate("BrailleTranslateClass", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        buttonTranslate->setText(QCoreApplication::translate("BrailleTranslateClass", "\347\277\273\350\257\221", nullptr));
        labelPlainText->setText(QCoreApplication::translate("BrailleTranslateClass", "\346\230\216\346\226\207", nullptr));
        labelBrailleText->setText(QCoreApplication::translate("BrailleTranslateClass", "\347\233\262\346\226\207", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BrailleTranslateClass: public Ui_BrailleTranslateClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BRAILLETRANSLATE_H
