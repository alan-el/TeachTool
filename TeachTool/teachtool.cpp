#include "stdafx.h"
#include "teachtool.h"
#include "java_methods.h"
#include "brailletranslate.h"

#include <QAction>
#include <QMenuBar>
#include <QAxObject>
TeachTool::TeachTool(QWidget *parent)
	: QMainWindow(parent)
{
	setupUi(this);
	createActions();
	createMenuBar();
	setButtons();
}

TeachTool::~TeachTool()
{
}

void TeachTool::onButtonSlideExtract()
{
	/* Call Java method to Extract Texts in PPT */
	int str_length = pathname.length();
	std::string str = pathname.toStdString();
	const char *ch = str.c_str();
	const char *tail = (ch + str_length - 1) - 4;

	if(strcmp(tail + 1, ".ppt") == 0)
	{
		JavaMethods::createJVM();
		slidesNum = JavaMethods::pptTextExtractor(ch, false);
		JavaMethods::pptPictExtractor(ch, false);
	}
	else if(strcmp(tail, ".pptx") == 0)
	{
		JavaMethods::createJVM();
		slidesNum = JavaMethods::pptTextExtractor(ch, true);
		JavaMethods::pptPictExtractor(ch, true);
	}

	buttonSlideTransform->setEnabled(true);

//	for(int i = 1; i <= slidesNum; i++)
//		comboBoxSlideIndex->addItem(QString::number(i), NULL);
}

void TeachTool::onButtonSlideTransform()
{
	BrailleTranslate *transWindow = new BrailleTranslate(nullptr, pathnameNoExtension, slidesNum);
	transWindow->show();
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

	buttonSlideExtract->setEnabled(true);

	for(int i = pathname.length() - 1; i >= 0; i--)
	{
		if(pathname.at(i) == '.')
		{
			pathnameNoExtension = pathname.left(i);
			break;
		}
	}

	QDir textDir(pathnameNoExtension + "/texts");
	if(textDir.exists())
	{
		QFile tf(pathnameNoExtension + "/texts/slides_num.txt");
		if(tf.exists())
		{
			bool ret = tf.open(QIODevice::ReadOnly);
			if(ret == true)
			{
				QByteArray array = tf.readAll();
				QTextCodec *codec = QTextCodec::codecForName("GBK");
				QString str = codec->toUnicode(array);
				slidesNum = str.toInt();
			}
		}
	}
}
void TeachTool::onActionTransTriggered()
{
	
}
void TeachTool::createActions()
{
	m_actionOpen = new QAction(tr("&Open"), this);
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
	connect(buttonSlideExtract, SIGNAL(clicked()), SLOT(onButtonSlideExtract()));
	connect(buttonSlideTransform, SIGNAL(clicked()), SLOT(onButtonSlideTransform()));

	buttonSlideExtract->setEnabled(false);
	/* TODO È¥µô×¢ÊÍ */
	//buttonSlideTransform->setEnabled(false);
}
