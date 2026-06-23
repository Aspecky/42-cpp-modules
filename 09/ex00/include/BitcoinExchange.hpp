#include <fstream>
#include <map>
#include <string>

class BitcoinExchange {
  public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	~BitcoinExchange();

	BitcoinExchange &operator=(BitcoinExchange other);

	void loadDatabase(std::ifstream &file);
	void processInput(std::ifstream &file);

  private:
	std::map<std::string, double> data_;
};
