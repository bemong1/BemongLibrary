#pragma once

#include <memory>
#include <mutex>

namespace bemong
{
	template<class TClass>
	class Singleton
	{
	public:
		Singleton() = default;
		~Singleton() = default;

		static TClass& Instance()
		{
			std::call_once(m_bCallOnceFlag, []()
			{
				m_tInstance = std::make_shared<TClass>();
			});
			return *m_tInstance;
		}

	private:
		Singleton(const Singleton&)
			= delete;
		Singleton(Singleton&&)
			= delete;
		Singleton& operator=(const Singleton&)
			= delete;
		Singleton& operator=(Singleton&&)
			= delete;

		static std::shared_ptr<TClass> m_tInstance;
		static std::once_flag m_bCallOnceFlag;
	};
}

template<class TClass>
std::once_flag bemong::Singleton<TClass>::m_bCallOnceFlag;

template<class TClass>
std::shared_ptr<TClass> bemong::Singleton<TClass>::m_tInstance;

