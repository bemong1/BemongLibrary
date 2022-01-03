#include "TestClass.h"

#include "Util/ExceptionManager/ExceptionMgr.h"
#include "DesignPattern/PimplIdiom/Pimpl.h"

int FunctionTest(int& nX)
{
	std::vector<int> vecTest;
	vecTest.at(nX);

	return 0;
}

int PimplSample()
{
	//Pimpl Sample Test
	bemong::Pimpl* pPimpl = new bemong::Pimpl();

	int nTest = 1;
	std::string strTest = "input test";

	pPimpl->SetInt(nTest);
	pPimpl->SetString(strTest);

	int nTestOut = 0;
	std::string strTestOut = "";

	pPimpl->GetInt(nTestOut);
	pPimpl->GetString(strTestOut);

	delete pPimpl;

	return 0;
}

int ExceptionSample()
{
	//Exception Test for Function
	int nX = 5;

	//bemong::ExceptionMgrBase* pExcep = new bemong::ExceptionMgrBase();
	std::shared_ptr<bemong::ExceptionMgrBase> pExcep = 
		std::make_shared< bemong::ExceptionMgrBase>();
	std::string strExcepMessage = pExcep->Exception(FunctionTest, nX);
	std::cout << "Function Exception Message : " << strExcepMessage << std::endl;

	//Exception Test for Class
	std::shared_ptr<TestClass> pTestClass = 
		std::make_shared<TestClass>();
	pTestClass->ExceptionTest();

	return 0;
}

int SingletonSample()
{
	//Singleton and Exception Test
	TestClass* pTestClass = new TestClass();
	
	pTestClass->SingletonTest();

	delete pTestClass;

	return 0;
}

int main(void)
{
	while (1)
	{
		PimplSample();

		ExceptionSample();

		SingletonSample();
	}

	return 0;
}