#include "stdafx.h"
#include <QtWidgets>
#include <iostream>

#include "teachtool.h"
#include "liblouis.h"
using namespace std;

int main(int argc, char *argv[])
{
	/*const widechar in[5] = {0x4E00, 0x4E01, 0x4E03, 0x4E07, 0x4E08}; // UTF-16 编码: "一丁七万丈"
	widechar out[100];
	char space[100];
	memset(space, 0, sizeof(space));
	int in_len = 5;
	int out_len = 100;
	int ret = lou_translateString("D:/MyProject/BlinderReader/software/Chapter5/liblouis/liblouis-3.22.0-win64/share/liblouis/tables/zhcn-g1.ctb", in, &in_len, out, &out_len, NULL, space, dotsIO);
	cout << ret << endl;*/
	
    QApplication a(argc, argv);
    TeachTool w;
    w.show();
    return a.exec();
}


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
