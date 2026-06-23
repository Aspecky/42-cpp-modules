#include "BitcoinExchange.hpp"
#include <cctype>
#include <cerrno>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <utility>

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
	: data_(other.data_)
{
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange other)
{
	std::swap(data_, other.data_);
	return *this;
}

static bool isValidDate(const std::string &str)
{
	if (str.size() != 10 || str[4] != '-' || str[7] != '-') {
		return false;
	}

	struct tm t = {};
	t.tm_year	= std::atoi(str.substr(0, 4).c_str()) - 1900;
	t.tm_mon	= std::atoi(str.substr(5, 2).c_str()) - 1;
	t.tm_mday	= std::atoi(str.substr(8, 2).c_str());
	t.tm_hour	= 12; // avoid midnight DST transitions
	t.tm_isdst	= -1; // let the system determine DST

	int year  = t.tm_year;
	int month = t.tm_mon;
	int day	  = t.tm_mday;

	if (std::mktime(&t) == -1) {
		return false;
	}

	return t.tm_year == year && t.tm_mon == month && t.tm_mday == day;
}
static std::string trim(const std::string &str)
{
	std::string::size_type start = 0;
	std::string::size_type end	 = str.size();

	while (start < end &&
		   std::isspace(static_cast<unsigned char>(str[start]))) {
		++start;
	}

	while (end > start &&
		   std::isspace(static_cast<unsigned char>(str[end - 1]))) {
		--end;
	}

	return str.substr(start, end - start);
}

void BitcoinExchange::loadDatabase(std::ifstream &file)
{
	std::string line;

	if (!std::getline(file, line)) {
		throw std::runtime_error("database file is empty");
	}
	if (line != "date,exchange_rate") {
		throw std::runtime_error("invalid database header");
	}

	while (std::getline(file, line)) {
		if (line.empty()) {
			continue;
		}

		size_t comma = line.find(',');
		if (comma == std::string::npos) {
			std::cerr << "Error: bad database line => " << line << std::endl;
			continue;
		}

		std::string date	= trim(line.substr(0, comma));
		std::string rateStr = trim(line.substr(comma + 1));

		if (!isValidDate(date)) {
			std::cerr << "Error: bad database date => " << line << std::endl;
			continue;
		}

		errno		  = 0;
		char  *endPtr = NULL;
		double rate	  = std::strtod(rateStr.c_str(), &endPtr);
		if (*endPtr != '\0') {
			std::cerr << "Error: expected EOL => " << line << std::endl;
			continue;
		}

		if (errno == ERANGE) {
			std::cerr << "Error: " << rateStr << " is outside the double range"
					  << std::endl;
			continue;
		}

		data_[date] = rate;
	}
	if (data_.empty()) {
		throw std::runtime_error("no data in data.csv");
	}
}

void BitcoinExchange::processInput(std::ifstream &file)
{
	std::string line;

	if (!std::getline(file, line)) {
		throw std::runtime_error("input file file is empty");
	}
	if (line != "date | value") {
		throw std::runtime_error("invalid input file header");
	}

	while (std::getline(file, line)) {
		if (line.empty()) {
			continue;
		}

		size_t pipe = line.find('|');
		if (pipe == std::string::npos) {
			std::cerr << "Error: bad input line => " << line << std::endl;
			continue;
		}

		std::string date	 = trim(line.substr(0, pipe));
		std::string valueStr = trim(line.substr(pipe + 1));

		if (!isValidDate(date)) {
			std::cerr << "Error: bad input file date => " << date << std::endl;
			continue;
		}

		errno		  = 0;
		char  *endPtr = NULL;
		double value  = std::strtod(valueStr.c_str(), &endPtr);

		if (*endPtr != 0) {
			std::cerr << "Error: " << valueStr
					  << " is not a valid number in the input file"
					  << std::endl;
			continue;
		}

		if (errno == ERANGE || 0 > value || value > 1000) {
			std::cerr << "Error: " << valueStr
					  << " is not in the [0, 1000] range" << std::endl;
			continue;
		}

		std::map<std::string, double>::iterator it = data_.lower_bound(date);

		if (it == data_.end() || it->first != date) {
			if (it == data_.begin()) {
				std::cerr << "Error: no rate available for date => " << date
						  << std::endl;
				continue;
			}
			--it;
		}

		std::cout << date << " => " << value << " = " << value * it->second
				  << std::endl;
	}
}
