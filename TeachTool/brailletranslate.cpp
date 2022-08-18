#include "stdafx.h"
#include "brailletranslate.h"
#include "liblouis.h"
#include <QFile>
#include <iostream>
#include <QTextCodec>
using namespace std;
BrailleTranslate::BrailleTranslate(QWidget *parent, const QString &dir, int slidesNum)
	: QWidget(parent)
{
	setupUi(this);
	connectButtons();

	exFileDir = dir + "/";

	for(int i = 1; i <= slidesNum; i++)
		comboBoxSlideIndex->addItem(QString::number(i), NULL);

}

BrailleTranslate::~BrailleTranslate()
{

}
void BrailleTranslate::displayPlainText(int index)
{
	if(index >= 0)
	{
		textBlocks.clear();
		texteditPlain->clear();
		texteditBraille->clear();
		index += 1;

		QString pathnamePrefix = exFileDir + "texts/slide" + QString::number(index);
		QString pathname;
		QFile plainTextFile;
		for(int i = 1; ; i++)
		{
			pathname = pathnamePrefix + "_text" + QString::number(i) + ".txt";
			plainTextFile.setFileName(pathname);
			
			if(plainTextFile.exists())
			{
				bool ret = plainTextFile.open(QIODevice::ReadOnly);
				if(ret == true)
				{
					QByteArray array = plainTextFile.readAll();
					QTextCodec *codec = QTextCodec::codecForName("GBK");
					QString str = codec->toUnicode(array);
					textBlocks.append(str);
					QString prefix = codec->toUnicode("Œƒ◊÷");
					texteditPlain->appendPlainText(prefix + QString::number(i) + ": " + textBlocks.last() + '\n');
				}
				plainTextFile.close();
				buttonSlideTransform->setEnabled(true);
			}
			else
				break;
		}
	}
}

void BrailleTranslate::onButtonTransformTriggered()
{
	foreach(QString tb , textBlocks)
	{
		int len = tb.length();
		const wchar_t *pt16 = (const wchar_t *)tb.utf16();
		widechar *in = new widechar[len];

		for(int i = 0; i < len; i++)
			in[i] = pt16[i];

		widechar *out = new widechar[len * 3];
		char *space = new char[len * 3];
		int in_len = len;
		int out_len = len * 3;
		int ret = lou_translateString("D:/MyProject/BlinderReader/software/Chapter5/liblouis/liblouis-3.22.0-win64/share/liblouis/tables/zhcn-g1.ctb", in, &in_len, out, &out_len, NULL, space, noContractions);
		cout << ret << endl;

		char16_t *brl16 = new char16_t[out_len];
		for(int i = 0; i < out_len; i++)
			brl16[i] = out[i];

		QString brl = QString::fromUtf16(brl16, out_len);
		delete[] in;
		delete[] out;
		delete[] space;

		texteditBraille->appendPlainText(brl + '\n');
	}
	
	//const widechar in[5] = {0x4E00, 0x4E01, 0x4E03, 0x4E07, 0x4E08}; // UTF-16 ±‡¬Î: "“ª∂°∆ﬂÕÚ’…"
	//widechar out[100];
	//char space[100];
	//memset(space, 0, sizeof(space));
	//int in_len = 5;
	//int out_len = 100;
	//int ret = lou_translateString("D:/MyProject/BlinderReader/software/Chapter5/liblouis/liblouis-3.22.0-win64/share/liblouis/tables/zh-chn.ctb", in, &in_len, out, &out_len, NULL, space, dotsIO);
	//cout << ret << endl;
	
}

void BrailleTranslate::connectButtons()
{
	connect(comboBoxSlideIndex, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &BrailleTranslate::displayPlainText);

	connect(buttonSlideTransform, &QPushButton::clicked, this, &BrailleTranslate::onButtonTransformTriggered);
	buttonSlideTransform->setEnabled(false);
	buttonModify->setEnabled(false);
}


