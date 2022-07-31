#include "stdafx.h"
#include "teachtool.h"
#include <QtWidgets/QApplication>

#include <iostream>
using namespace std;
/*
void doTestCPP (JNIEnv *e, jobject o) {
	std::cout << "C++callback activated" << std::endl;
	jfieldID f_uid = e->GetFieldID (e->GetObjectClass (o), "uid", "I");
	if (f_uid)
		std::cout << "UID data member: " << e->GetIntField (o, f_uid) << std::endl;
	else std::cout << "UID not found" << std::endl;
}

JNINativeMethod methods[]{ { (char *)"doTest", (char *)"()V", (void *)&doTestCPP } };  // mapping table

		if (env->RegisterNatives (cls2, methods, 1) < 0) {                        // register it
			if (env->ExceptionOccurred ())                                        // verify if it's ok
				cerr << " OOOOOPS: exception when registreing naives" << endl;
			else
				cerr << " ERROR: problem when registreing naives" << endl;
		}
*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TeachTool w;
    w.show();
    return a.exec();
}
