#include "Singleton.h"
#include <iostream>

class TestClass
{
public:
	TestClass(){};
	~TestClass(){};

public:
	int GetValue()
	{
		return 5;
	}
};

int main()
{
	bemong::Singleton<TestClass> pTestClass;
	int nTest = pTestClass.Instance().GetValue();

	std::cout << "Value : " << nTest << std::endl;

	return 0;
}
