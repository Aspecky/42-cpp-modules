#pragma once

#include <string>

class Harl {
  public:
	void complain(std::string level);

  private:
	static void (Harl::*funcs[4])(void);
	static std::string indices[4];

	void debug();
	void info();
	void warning();
	void error();
};
