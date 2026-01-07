#pragma once

#include <string>

#define BRAIN_IDEAS_COUNT 100

class Brain {
  public:
	Brain();
	Brain(const Brain &other);
	~Brain();

	Brain &operator=(const Brain &other);

	const std::string &ideas(int index) const;
	void ideas(int index, const std::string &idea);

  private:
	std::string ideas_[BRAIN_IDEAS_COUNT];
};
