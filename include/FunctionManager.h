#pragma once
#include "PythonHandler.h"
#include "boost/any.hpp"
#include <algorithm>

using boost::any_cast;

//responsible for setting up PythonArgLists for python functions
class FunctionManager {
public:
	FunctionManager();
	FunctionManager(std::string);
	FunctionManager(FunctionManager&);

	~FunctionManager();

	//boost::any execute() { return 1; };
	void setConfigLine(std::string);
	void updateParameters(std::string);
	PyObject* execute() { return py_handler.execute(); };

	bool isGood() { return good && py_handler.isGood(); };
	const std::string getConfigLine() { return config_line; };

private:
	void configure();
	PyObject* convert(std::string);

	std::string config_line;

	std::string file_name;
	std::string function_name;

	PythonHandler py_handler;
	PythonArgList py_args;

	bool good = true;
};