#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "ConsoleLogger.h"
#include "FileLogger.h"

int main()
{
	std::ofstream stream("input.txt", std::ios_base::app);


	Logger<FileLogger>& fileLogger = *new FileLogger(stream);
	Logger<ConsoleLogger>& consoleLogger = *new ConsoleLogger();

	fileLogger.Log("Message in file");
	consoleLogger.Log("Message in console");

	delete& fileLogger;
	delete& consoleLogger;

	stream.close();

	return 0;
}
