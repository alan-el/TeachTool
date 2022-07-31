#include "stdafx.h"
#include "teachtool.h"
#include "java_methods.h"

#include <QAction>
#include <QMenuBar>

TeachTool::TeachTool(QWidget *parent)
	: QMainWindow(parent)
{
	setupUi(this);
	createActions();
	createMenuBar();
	setButtons();
}

TeachTool::~TeachTool()
{}

void TeachTool::onButtonTextExtract()
{
	/* Call Java method to Extract Texts in PPT*/
	int str_length = pathname.length();
	std::string str = pathname.toStdString();
	const char *ch = str.c_str();

	const char *p = ch + str_length - 1 - 4;
	if(strcmp(p + 1, ".ppt") == 0)
	{
		JavaMethods::createJVM();
		JavaMethods::pptTextExtractor(ch, false);
		JavaMethods::destroyJVM();
	}
	else if(strcmp(p, ".pptx") == 0)
	{
		JavaMethods::createJVM();
		JavaMethods::pptTextExtractor(ch, true);
		JavaMethods::destroyJVM();
	}
}

void TeachTool::onButtonPictExtract()
{
}

void TeachTool::onActionOpenTriggered()
{
	pathname = QFileDialog::getOpenFileName(0, tr("Open PPT(X) File"), "", "Presentation files (*.ppt *.pptx);;All files(*.*)");
	if(pathname.isEmpty())
		return;

	/** Show PPT in QAxWidget 
	 *	
	 *	TODO Get Slides Change events (Signals)
	 */
	axWidget->setControl(pathname);

	buttonTextExtract->setEnabled(true);
	buttonPictExtract->setEnabled(true);

	/*
	QString s = axWidget->generateDocumentation();
	QFile file;
	file.setFileName("C:\\Users\\Alan\\Desktop\\pptx.html");
	if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
		QTextStream stream(&file);
		stream << s << "\n";
		file.close();
	}*/
	
}

void TeachTool::createActions()
{
	m_actionOpen = new QAction(tr("&Open..."), this);
	m_actionClose = new QAction(tr("Close"), this);
	m_actionQuit = new QAction(tr("&Quit"), this);

	m_menuRecentFiles = new QMenu(tr("Recent files"), this);

	m_actionAbout = new QAction(tr("&About..."), this);

	connect(m_actionOpen, SIGNAL(triggered()), SLOT(onActionOpenTriggered()));

	/*
	char dir[1000];
	GetCurrentDirectory(1000, (LPWSTR)dir);*/
	/*TODO
	connect(m_actionClose, SIGNAL(triggered()), SLOT(onActionCloseTriggered()));
	connect(m_actionQuit, SIGNAL(triggered()), qApp, SLOT(quit()));
	connect(m_actionAbout, SIGNAL(triggered()), SLOT(onActionAboutTriggered()));*/
}

void TeachTool::createMenuBar()
{
	QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
	fileMenu->addAction(m_actionOpen);
}

void TeachTool::setButtons()
{
	connect(buttonTextExtract, SIGNAL(clicked()), SLOT(onButtonTextExtract()));
	connect(buttonPictExtract, SIGNAL(clicked()), SLOT(onButtonPictExtract()));

	buttonTextExtract->setEnabled(false);
	buttonPictExtract->setEnabled(false);
}
