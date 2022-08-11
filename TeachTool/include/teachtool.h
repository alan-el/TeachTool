#pragma once

#include <QMainWindow>
#include "ui_teachtool.h"

class TeachTool : public QMainWindow, public Ui::TeachToolClass
{
	Q_OBJECT

public:
	TeachTool(QWidget *parent = nullptr);
	~TeachTool();

private slots:
	void onActionOpenTriggered();
	void onActionTransTriggered();
	void onButtonTextExtract();
	void onButtonPictExtract();

private:
	void createActions();
	void createMenuBar();
	void setButtons();

	QAction *m_actionOpen;
	QAction *m_actionTrans;
	QAction *m_actionClose;
	QAction *m_actionQuit;
	QAction *m_actionAbout;
	QMenu *m_menuRecentFiles;
	/* TODO 
	QStringList m_recentFilesList;*/

	QString pathname;
};
