#pragma once

#include <string>
#include <vector>

#include <opencv2/core.hpp>

#include "Util/ExceptionManager/ExceptionMgr.h"

class TestClass
{
public:
	TestClass();
	~TestClass();

public:
	int ExceptionTest();
	int SingletonTest();

	int InvalidPixelAccess(int& nX, int& nY);
	int InvalidArrayAccess(int& nX);
};
