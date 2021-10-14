COMPILER = g++
GFLAGS = -std=c++20
SOURCES = main.cpp FileLogger.h ConsoleLogger.h Logger.h
EXEC_FILENAME = prog.exe

all: compile
run: compile
	@./${EXEC_FILENAME}
compile: ${SOURCES}
	${COMPILER} ${SOURCES} -o ${EXEC_FILENAME} -w ${GFLAGS}
clear:
	rm -f *.o ${EXEC_FILENAME}
