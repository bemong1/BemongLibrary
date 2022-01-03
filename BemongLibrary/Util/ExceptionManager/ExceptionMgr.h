#pragma once

#include <iostream>
#include <functional>
#include <opencv2/core.hpp>

namespace bemong
{
	template <class TClass>
	class ExceptionMgr
	{
	public:
		ExceptionMgr() = default;
		ExceptionMgr(const TClass& tClass);
		~ExceptionMgr() = default;

	private:
		TClass m_tClass;

	public:
		int SetClassObject(const TClass& tClass);

		template <typename T, typename... Types>
		std::string Exception(T&& pFunc, Types&... args);

	private:
		template <typename T>
		std::string TryCatchException(T& pFunc);
	};

	class ExceptionMgrBase
	{
	public:
		ExceptionMgrBase() {};
		~ExceptionMgrBase() {};

	public:
		template <typename T, typename... Types>
		std::string Exception(T&& pFunc, Types&... args);

	private:
		template <typename T>
		std::string TryCatchException(T& pFunc);
	};
}
#include "ExceptionMgr.hpp"

