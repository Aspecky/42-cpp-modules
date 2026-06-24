#include <cerrno>
#include <climits>
#include <cstddef>
#include <cstdlib>
#include <exception>
#include <string>
#include <utility>
#include <vector>

template <typename Container> void binaryInsert(Container &cont, int value)
{
	int left  = 0;
	int right = static_cast<int>(cont.size());

	while (left < right) {
		int mid = left + ((right - left) / 2);
		if (cont[mid] > value)
			right = mid;
		else
			left = mid + 1;
	}
	cont.insert(cont.begin() + left, value);
}

std::vector<size_t> jacobsthalSequence(size_t n);

template <typename Container> void mergeInsert(Container &arr)
{
	if (arr.size() < 2)
		return;

	std::vector<std::pair<int, int> > pairs;
	bool							 isArrOdd	 = (arr.size() % 2 != 0);
	int								 straggler = 0;

	if (isArrOdd)
		straggler = arr.back();

	for (size_t i = 0; i + 1 < arr.size(); i += 2) {
		if (arr[i] > arr[i + 1])
			pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
		else
			pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
	}

	if (pairs.size() > 1) {
		std::vector<int> largers;
		largers.reserve(pairs.size());
		for (size_t i = 0; i < pairs.size(); i++)
			largers.push_back(pairs[i].first);

		mergeInsert(largers);

		std::vector<std::pair<int, int> > sortedPairs;
		for (size_t i = 0; i < largers.size(); i++) {
			for (size_t j = 0; j < pairs.size(); j++) {
				if (pairs[j].first == largers[i]) {
					sortedPairs.push_back(pairs[j]);
					pairs.erase(
						pairs.begin() +
						static_cast<
							std::vector<std::pair<int, int> >::difference_type>(
							j));
					break;
				}
			}
		}
		pairs = sortedPairs;
	}

	Container		 mainChain;
	std::vector<int> pend;

	for (size_t i = 0; i < pairs.size(); i++) {
		mainChain.push_back(pairs[i].first);
		pend.push_back(pairs[i].second);
	}

	if (!pend.empty())
		mainChain.insert(mainChain.begin(), pend[0]);

	if (pend.size() > 1) {
		std::vector<size_t> jacob = jacobsthalSequence(pend.size() - 1);
		std::vector<bool>	inserted(pend.size(), false);
		inserted[0] = true;

		for (size_t i = 0; i < jacob.size(); i++) {
			size_t idx = jacob[i];
			if (idx < pend.size() && !inserted[idx]) {
				binaryInsert(mainChain, pend[idx]);
				inserted[idx] = true;
			}
		}

		for (size_t i = 1; i < pend.size(); i++) {
			if (!inserted[i])
				binaryInsert(mainChain, pend[i]);
		}
	}

	if (isArrOdd)
		binaryInsert(mainChain, straggler);

	arr = mainChain;
}

template <typename Container> class PmergeMe {
  public:
	PmergeMe()
	{
	}

	PmergeMe(const PmergeMe &other) : cont_(other.cont_)
	{
	}

	PmergeMe &operator=(const PmergeMe &other)
	{
		if (this != &other) {
			cont_ = other.cont_;
		}
		return *this;
	}

	~PmergeMe()
	{
	}

	void parse(int ac, char **av)
	{
		for (int i = 1; i < ac; i++) {
			std::string s(av[i]);

			if (s.empty()) {
				throw PmergeMeException();
			}

			char *end = 0;
			errno	  = 0;
			long n	  = std::strtol(s.c_str(), &end, 10);
			if (*end != '\0' || errno == ERANGE || n < 0 || n > INT_MAX) {
				throw PmergeMeException();
			}
			cont_.push_back(static_cast<int>(n));
		}

		if (cont_.empty()) {
			throw PmergeMeException();
		}
	}

	void sort()
	{
		mergeInsert(cont_);
	}

	Container get() const
	{
		return cont_;
	}

	class PmergeMeException : public std::exception {
	  public:
		virtual const char *what() const throw()
		{
			return "Error";
		}
	};

  private:
	Container cont_;
};


inline std::vector<size_t> jacobsthalSequence(size_t n)
{
	std::vector<size_t> seq;
	if (n == 0) {
		return seq;
	}

	size_t j1 = 1;
	size_t j2 = 3;
	while (j1 <= n) {
		seq.push_back(j1);
		size_t next = j2 + (2 * j1);
		j1			= j2;
		j2			= next;
	}
	return seq;
}
