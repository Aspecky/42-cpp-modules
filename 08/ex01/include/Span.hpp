#include <vector>

class Span {
  public:
	Span(unsigned int maxSize = 0);
	Span(const Span &other);
	~Span();

	Span &operator=(const Span &other);

	void addNumber(int n);

	void addRange(std::vector<int>::const_iterator begin,
				  std::vector<int>::const_iterator end);

	int shortestSpan() const;
	int longestSpan() const;

  private:
	unsigned int	 maxSize_;
	std::vector<int> vector_;
};
