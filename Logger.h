#pragma once
#include <utility>
#include <chrono>
#include <string>
template<class Derived>
class Logger
{
public:
	template <class... Ts>
	void Log(Ts&&... args);
};

template <class Derived>
template <class ... Ts>
void Logger<Derived>::Log(Ts&&... args)
{
	using namespace std::chrono;
	const std::time_t time_now = system_clock::to_time_t(system_clock::now());
	
	std::string prefix = "TIME: " + std::string(std::ctime(&time_now)) + "[";
	std::string postfix = "]\n";

	static_cast<Derived*>(this)->Log(prefix, std::forward<Ts>(args)..., postfix);
}
