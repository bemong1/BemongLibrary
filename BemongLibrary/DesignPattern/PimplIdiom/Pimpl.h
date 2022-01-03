#pragma once

#include "spimpl.h"

#include <string>

namespace bemong
{
	class Pimpl
	{
	public:
		Pimpl();
		~Pimpl() {};

	public:
		int GetInt(int& nTest);
		int GetString(std::string& strTest);

		int SetInt(const int& nInt);
		int SetString(const std::string& strString);

	private:
		class PrivateMember;
		spimpl::impl_ptr<PrivateMember> m_privateMember;
	};
};
