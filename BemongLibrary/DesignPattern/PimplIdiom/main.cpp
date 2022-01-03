#include "Pimpl.h"

#include <iostream>

int main()
{
	bemong::Pimpl* pPimpl = new bemong::Pimpl();

	int nTest = 1;
	std::string strTest = "input test";

	pPimpl->SetInt(nTest);
	pPimpl->SetString(strTest);

	int nTestOut = 0;
	std::string strTestOut = "";

	pPimpl->GetInt(nTestOut);
	pPimpl->GetString(strTestOut);

	std::cout << nTestOut << ", " << strTestOut << std::endl;

	delete pPimpl;

	return 0;
}


