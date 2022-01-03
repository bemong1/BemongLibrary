#include "Pimpl.h"

//Define Private
class bemong::Pimpl::PrivateMember
{
public:
	PrivateMember()
	{
		//Initial Sample Variable
		m_nTest = 0; 
		m_strTest = "";
	};

public:
	//Sample Variable (It's actually a private member)
	int m_nTest;
	std::string m_strTest;

public:
	//Sample Method (It's actually a private member)
	int getInt(int& nTest);
	int getString(std::string& strTest);

	int setInt(const int& nInt);
	int setString(const std::string& strString);
};

//Implementation Private Member
int bemong::Pimpl::PrivateMember::getInt(int& nTest)
{
	nTest = m_nTest;
	return 0;
}

int bemong::Pimpl::PrivateMember::getString(std::string& strTest)
{
	strTest = m_strTest;
	return 0;
}

int bemong::Pimpl::PrivateMember::setInt(const int& nTest)
{
	m_nTest = nTest;
	return 0;
}

int bemong::Pimpl::PrivateMember::setString(const std::string& strTest)
{
	m_strTest = strTest;
	return 0;
}

//Wrapper (Public Method)
bemong::Pimpl::Pimpl()
	:m_privateMember(spimpl::make_impl<PrivateMember>())
{

}


int bemong::Pimpl::GetInt(int& nTest)
{
	int nRet = m_privateMember->getInt(nTest);
	return nRet;
}

int bemong::Pimpl::GetString(std::string& strTest)
{
	int nRet = m_privateMember->getString(strTest);
	return nRet;
}

int bemong::Pimpl::SetInt(const int& nInt)
{
	int nRet = m_privateMember->setInt(nInt);
	return nRet;
}

int bemong::Pimpl::SetString(const std::string& strString)
{
	int nRet = m_privateMember->setString(strString);
	return nRet;
}

