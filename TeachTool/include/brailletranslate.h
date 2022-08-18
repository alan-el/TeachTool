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
	void onButtonTransformTriggered();
private:
	void connectButtons();

	QString exFileDir;

	QList <QString> textBlocks;
};
