#include "stdafx.h"
#include "brailletranslate.h"
#include "liblouis.h"
#include <QFile>
#include <iostream>
using namespace std;
BrailleTranslate::BrailleTranslate(QWidget *parent)
	: QWidget(parent)
{
	setupUi(this);
	connectButtons();
}

BrailleTranslate::~BrailleTranslate()
{

}

void BrailleTranslate::onButtonSeclectFileTriggered()
{
	pathname = QFileDialog::getOpenFileName(0, tr("Open File"), "", "Text files (*.txt);;All files(*.*)");
	if(pathname.isEmpty())
	{
		buttonTranslate->setEnabled(false);
		return;
	}
		
	QFile plainTextFile;
	plainTextFile.setFileName(pathname);

	bool ret = plainTextFile.open(QIODevice::ReadOnly);
	if(ret == true)
	{
		QByteArray array = plainTextFile.readAll();
		QTextCodec *codec = QTextCodec::codecForName("GBK");
		QString str = codec->toUnicode(array);
		texteditPlain->setPlainText(str);
	}

	plainTextFile.close();

	buttonTranslate->setEnabled(true);
}

void BrailleTranslate::onButtonTranslateTriggered()
{
	QString pt = texteditPlain->toPlainText();
	int len = pt.length();
	const wchar_t *pt16 = (const wchar_t *)pt.utf16();
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

	texteditBraille->setPlainText(brl);
	/*const widechar in[5] = {0x4E00, 0x4E01, 0x4E03, 0x4E07, 0x4E08}; // UTF-16 ±‡¬Î: "“ª∂°∆ﬂÕÚ’…"
	widechar out[100];
	char space[100];
	memset(space, 0, sizeof(space));
	int in_len = 5;
	int out_len = 100;
	int ret = lou_translateString("D:/MyProject/BlinderReader/software/Chapter5/liblouis/liblouis-3.22.0-win64/share/liblouis/tables/zh-chn.ctb", in, &in_len, out, &out_len, NULL, space, dotsIO);
	cout << ret << endl;
	*/
}

void BrailleTranslate::connectButtons()
{
	connect(buttonSelectFile, SIGNAL(clicked()), SLOT(onButtonSeclectFileTriggered()));
	connect(buttonTranslate, SIGNAL(clicked()), SLOT(onButtonTranslateTriggered()));

	buttonTranslate->setEnabled(false);
}


