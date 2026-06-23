#include <string>

class RPN {
  public:
	RPN();
	~RPN();
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);

	void evaluate(const std::string &expression);
};
