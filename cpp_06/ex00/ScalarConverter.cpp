#include "ScalarConverter.hpp"
#include <algorithm>
#include <cctype>
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

	if(str.length() == 1 && !std::isdigit(str[0]))
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
void display_char(char *str, int type)
{
	char c;
	std::string s(str);

	c = static_cast<char>(std::atoi(str));
	if(check_for_special_cases(s) != -1 || type == UNKNOWN)
		std::cout << "char: impossible" << std::endl;
	else if(s.length() == 1 && !std::isdigit(s[0]))
		std::cout << "char: '" << s << "'" << std::endl;
	else if(c < 32 || c > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c  << "'"<< std::endl;
}

void display_int(char *str, int type)
{
	int num;
	std::string s(str);

	num = static_cast<int>(std::atoi(str));
	if(check_for_special_cases(s) != -1 || type == UNKNOWN)
		std::cout << "int: impossible" << std::endl;
	else if(type == CHAR)
		std::cout << "int: " << static_cast<int>(str[0])  << std::endl;
	else
		std::cout << "int: " << num  << std::endl;
}

void display_float(char *str, int type)
{
	float num;
	std::string s(str);

	num = static_cast<float>(std::atof(str));
	if(check_for_special_cases(s) != -1 || type == UNKNOWN)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << num << "f" << std::endl;
}
void ScalarConverter::convert(char *str)
{
	int type = detect_type(str);
	std::cout << "type: " << type << std::endl << std::endl;

	display_char(str, type);
	display_int(str, type);
	display_float(str, type);
	// std::cout << "float: " << std::atof(str) << "f" << std::endl;
	std::cout << "double: " << std::atof(str) << std::endl;
}