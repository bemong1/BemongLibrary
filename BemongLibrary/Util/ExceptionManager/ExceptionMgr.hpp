#include "ExceptionMgr.h"

template <class TClass>
bemong::ExceptionMgr<TClass>::ExceptionMgr(const TClass& tClass)
{
	SetClassObject(tClass);
}

template <class TClass>
int bemong::ExceptionMgr<TClass>::SetClassObject(const TClass& tClass)
{
	m_tClass = tClass;
	return 0;
}

template <class TClass> template <typename T, typename... Types>
std::string bemong::ExceptionMgr<TClass>::Exception(T&& pFunc, Types&... args)
{
	auto binderFunction= std::bind(pFunc, m_tClass, std::ref<Types>(args)...);

	return TryCatchException(binderFunction);
}

template <class TClass> template <typename T>
std::string bemong::ExceptionMgr<TClass>::TryCatchException(T& binderFunction)
{
	std::string strError;

	try
	{
		binderFunction();
		strError = "Run OK.";
	}
	catch (cv::Exception& e)
	{
		strError = std::string(e.what());
		return strError;
	}
	catch (std::exception& e)
	{
		strError = "C++STL Error : " + std::string(e.what());
		return strError;
	}

	return strError;
}


template <typename T, typename... Types>
std::string bemong::ExceptionMgrBase::Exception(T&& pFunc, Types&... args)
{
	auto binderFunction = std::bind(pFunc, std::ref<Types>(args)...);

	return TryCatchException(binderFunction);
}

template <typename T>
std::string bemong::ExceptionMgrBase::TryCatchException(T& binderFunction)
{
	std::string strError;

	try
	{
		binderFunction();
		strError = "Run OK.";
	}
	catch (cv::Exception& e)
	{
		strError = "OpenCV Exception : " + std::string(e.what());
		return strError;
	}
	catch (std::exception& e)
	{
		//const char* szErrMsg = e.what();
		strError = "C++STL Exception : " + std::string(e.what());
		return strError;
	}

	return strError;
}
