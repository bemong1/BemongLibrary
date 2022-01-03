#include "ExceptionMgr.h"

#include <memory>
#include <vector>

class TestClass
{
public:
	TestClass(){};
	~TestClass(){};

public:
	int InvalidArrayAccess(int& nX)
	{
		std::vector<int> vecTest;
		int nTest = vecTest.at(nX);

		return 0;
	}

	int Run()
	{
		bemong::ExceptionMgr<TestClass> excep(*this);

		int nX = 2;

		std::string strStdExceptionMessage;
		strStdExceptionMessage = excep.Exception(&TestClass::InvalidArrayAccess, nX);

		std::cout << strStdExceptionMessage << std::endl;
	
		return 0;
	}
};

int main()
{
	std::shared_ptr<TestClass> pTestClass = std::make_shared<TestClass>();
	pTestClass->Run();

	return 0;
}
