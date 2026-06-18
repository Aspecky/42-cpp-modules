#include "Span.hpp"
#include <algorithm>
#include <cstddef>
#include <iterator>
#include <stdexcept>
#include <vector>

Span::Span(unsigned int maxSize) : maxSize_(maxSize)
{
}

Span::Span(const Span &other) : maxSize_(other.maxSize_), vector_(other.vector_)
{
}

Span &Span::operator=(const Span &other)
{
	if (this != &other) {
		maxSize_ = other.maxSize_;
		vector_	 = other.vector_;
	}
	return *this;
}

Span::~Span()
{
}

void Span::addNumber(int n)
{
	if (vector_.size() >= maxSize_) {
		throw std::overflow_error("Span: already full");
	}
	vector_.push_back(n);
}

void Span::addRange(std::vector<int>::const_iterator begin,
					std::vector<int>::const_iterator end)
{
	size_t incoming = static_cast<size_t>(std::distance(begin, end));
	if (vector_.size() + incoming > maxSize_) {
		throw std::overflow_error("Span: not enough capacity for range");
	}
	vector_.insert(vector_.end(), begin, end);
}

int Span::shortestSpan() const
{
	if (vector_.size() < 2) {
		throw std::logic_error("Span: need at least 2 numbers");
	}

	std::vector<int> sorted(vector_);
	std::sort(sorted.begin(), sorted.end());

	int shortest = sorted[1] - sorted[0];
	for (size_t i = 1; i + 1 < sorted.size(); ++i) {
		shortest = std::min(shortest, sorted[i + 1] - sorted[i]);
	}

	return shortest;
}

int Span::longestSpan() const
{
	if (vector_.size() < 2) {
		throw std::logic_error("Span: need at least 2 numbers");
	}

	return *std::max_element(vector_.begin(), vector_.end()) -
		   *std::min_element(vector_.begin(), vector_.end());
}
