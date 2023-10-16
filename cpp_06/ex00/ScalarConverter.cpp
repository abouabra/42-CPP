#include "ScalarConverter.hpp"
#include <algorithm>
#include <string>

ScalarConverter::ScalarConverter()
{
}
ScalarConverter::~ScalarConverter()
{
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj)
{
	(void) obj;
	return (*this);
}
ScalarConverter::ScalarConverter(const ScalarConverter &obj)
{
	(void) obj;
}

int check_for_special_cases(std::string str)
{
	if(str == "-inf" || str == "+inf" || str == "nan")
		return DOUBLE;
	if(str == "-inff" || str == "+inff" || str == "nanf")
		return FLOAT;
	return (-1);
}
int detect_type(const char *s)
{
	std::string	str(s);
	
	int type = check_for_special_cases(str);
	if(type != -1)
		return (type);

	if(str.length() == 1 && !isdigit(str[0]))
		return CHAR;
	if(str.find_first_not_of("-0123456789") == std::string::npos)
		return INT;
	if(str.find_first_not_of("-0123456789.") == std::string::npos)
	{
		if(std::count(str.begin(), str.end(), '.') == 1
			&& str[str.length() - 1] != '.')
			return DOUBLE;
	}
	if(str.find_first_not_of("-0123456789.f") == std::string::npos)
	{
		if(std::count(str.begin(), str.end(), '.') == 1
			&&	std::count(str.begin(), str.end(), 'f') == 1
			&&	str[str.length() - 1] == 'f')
			return FLOAT;
	}
	return UNKNOWN;
}
void display_char(char *str)
{
	char c;
	
	c = static_cast<char>(std::atoi(str));
	if(c < 32 || c > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << c << std::endl;
}
void ScalarConverter::convert(char *str)
{
	int type = detect_type(str);
	std::cout << "type: " << type << std::endl << std::endl;

	display_char(str);
	std::cout << "int: " << std::atoi(str) << std::endl;
	std::cout << "float: " << std::atof(str) << std::endl;
	std::cout << "double: " << std::atof(str) << std::endl;
}