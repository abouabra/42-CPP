#ifndef BitcoinExchange_HPP
#define BitcoinExchange_HPP

#include <iostream>
#include <map>
#include <algorithm>

class BitcoinExchange
{
	private:
		std::string data_filename;
		std::string input_filename;
		BitcoinExchange();
	public:
		BitcoinExchange(std::string filename);
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		void run();
};


std::map<int, float> read_and_parse_data_file(std::string filename);
void read_and_parse_input_file(std::string filename, std::map<int, float> data_map);

std::string& trim(std::string& s);

enum e_date
{
	year,
	month,
	day
};
#endif