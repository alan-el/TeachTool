#pragma once

#include <QWidget>
#include "ui_brailletranslate.h"

class BrailleTranslate : public QWidget, public Ui::BrailleTranslateClass
{
	Q_OBJECT

public:
	BrailleTranslate(QWidget *parent = nullptr);
	~BrailleTranslate();
private slots:
	void onButtonSeclectFileTriggered();
	void onButtonTranslateTriggered();

private:
	void connectButtons();

	QString pathname;
};
