#pragma once

#include <QWidget>
#include "ui_brailletranslate.h"

class BrailleTranslate : public QWidget, public Ui::BrailleTranslateClass
{
	Q_OBJECT

public:
	BrailleTranslate(QWidget *parent, const QString &dir, int slidesNum);
	~BrailleTranslate();
private slots:
	void displayPlainText(int index);
	void onButtonTransformClicked();
	void onButtonInsertBrailleClicked();
	void onButtonDotClicked();

private:

	typedef enum 
	{
		brailleDotNone	= 0x00000000,
		brailleDot1		= 0x00000001,
		brailleDot2		= 0x00000002,
		brailleDot3		= 0x00000004,
		brailleDot4		= 0x00000008,
		brailleDot5		= 0x00000010,
		brailleDot6		= 0x00000020,
		brailleDot7		= 0x00000040,
		brailleDot8		= 0x00000080,
	}brailleDots_t;

	void connectButtons();
	void updateLabelBraille();

	QString exFileDir;

	QList <QString> textBlocks;

	int curBraKeyBorSta;
};
