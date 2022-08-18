#pragma once

#include <jni.h>
class JavaMethods
{
public:
	static void createJVM();
	static void destroyJVM();

	static int pptTextExtractor(const char *pathname, bool isPptx);
	static void pptPictExtractor(const char *pathname, bool isPptx);
};
