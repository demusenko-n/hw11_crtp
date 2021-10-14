#pragma once
#include <fstream>

#include "Logger.h"


class FileLogger : public Logger<FileLogger>
{
	std::ofstream& stream;
public:
	FileLogger(std::ofstream& ostream) : stream(ostream) {}

	template <class... Ts>
	void Log(Ts&&... args);
};

template <class ... Ts>
void FileLogger::Log(Ts&&... args)
{
	(stream << ... << std::forward<Ts>(args));
}
