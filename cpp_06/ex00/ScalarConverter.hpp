#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <exception>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &obj);
	ScalarConverter &operator=(const ScalarConverter &obj);
	~ScalarConverter();
public:
	static void convert(char *str);
};
enum e_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	UNKNOWN
};

#endif