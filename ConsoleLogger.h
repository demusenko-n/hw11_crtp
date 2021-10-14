#pragma once
#include <iostream>
#include "Logger.h"

class ConsoleLogger : public Logger<ConsoleLogger>
{
public:
	template <class... Ts>
	void Log(Ts&&... args);
};

template <class ... Ts>
void ConsoleLogger::Log(Ts&&... args)
{
	(std::cout << ... << std::forward<Ts>(args));
}
