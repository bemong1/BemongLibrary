#include "TestClass.h"

#include "DesignPattern/Singleton/Singleton.h"

TestClass::TestClass()
{

}

TestClass::~TestClass()
{

}

int TestClass::ExceptionTest()
{
	int nX = 3;
	int nY = 3;

	bemong::ExceptionMgr<TestClass> excep(*this);

	//Exception Error and Crash
	//InvalidArrayAccess(nX);
	//InvalidPixelAccess(nX, nY);

	std::string strStdExceptionMessage;
	std::string strOpenCVExceptionMessage;

	strStdExceptionMessage = excep.Exception(&TestClass::InvalidArrayAccess, nX);
	strOpenCVExceptionMessage = excep.Exception(&TestClass::InvalidPixelAccess, nX, nY);

	std::cout << strStdExceptionMessage << std::endl;
	std::cout << strOpenCVExceptionMessage << std::endl;

	return 0;
}

int TestClass::SingletonTest()
{
	int nX = 3;
	int nY = 3;

	bemong::Singleton<bemong::ExceptionMgr<TestClass>> excep;
	excep.Instance().SetClassObject(*this);

	std::string strStdExceptionMessage;
	std::string strOpenCVExceptionMessage;

	strStdExceptionMessage = excep.Instance().Exception(&TestClass::InvalidArrayAccess, nX);
	strOpenCVExceptionMessage = excep.Instance().Exception(&TestClass::InvalidPixelAccess, nX, nY);

	std::cout << strStdExceptionMessage << std::endl;
	std::cout << strOpenCVExceptionMessage << std::endl;

	return 0;
}

int TestClass::InvalidPixelAccess(int& nX, int& nY)
{
	cv::Mat mImage;// = cv::imread("test.jpg"); //Wrong File
	int nTest = mImage.at<int>(0, 0);

	return 0;
}

int TestClass::InvalidArrayAccess(int& nX)
{
	nX = 2;

	std::vector<int> vecTest;
	int nTest = vecTest.at(1);

	return 0;
}
