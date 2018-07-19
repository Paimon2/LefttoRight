#pragma once
/**
Logger.h
*/
#include <iostream>
#include <fstream>
#include <iostream>
#include <string>

enum ErrorType {
	Info = 1,
	Warning = 2,
	Error = 3,
};


class Logger {
private:
	std::ofstream handle;
	int messagesLogged;
public:
	Logger();
	~Logger();
	void initLogger();
	void logMsg(std::string message, ErrorType error);
	void closeLogger();
};