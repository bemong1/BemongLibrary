#include "UtilString.h"

#include <iostream>
#include <string>

int main()
{
	bemong::String pString;

	std::string strTest = pString.StringFormat("%d, %d", 3, 4);

	std::cout << "StringFormat : " << strTest << std::endl;

	return 0;
}
