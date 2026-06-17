#include <cstddef>
#include <stdexcept>

template <typename T> void swap(T &a, T &b)
{
	T tmp = a;
	a	  = b;
	b	  = tmp;
}

template <typename T> class Array {
  public:
	Array(unsigned int n = 0) : size_(n), array_(n > 0 ? new T[n]() : NULL)
	{
	}

	~Array()
	{
		delete[] array_;
	}

	Array(const Array &other)
		: size_(other.size_), array_(size_ > 0 ? new T[size_] : NULL)
	{
		for (unsigned int i = 0; i < size_; i++) {
			array_[i] = other.array_[i];
		}
	}

	Array &operator=(Array other)
	{
		swap(other);
		return *this;
	}

	void swap(Array &other)
	{
		::swap(array_, other.array_);
		::swap(size_, other.size_);
	}

	T &operator[](unsigned int index)
	{
		if (index >= size_) {
			throw std::out_of_range("Array: index out of bounds");
		}
		return array_[index];
	}

	const T &operator[](unsigned int index) const
	{
		if (index >= size_) {
			throw std::out_of_range("Array: index out of bounds");
		}
		return array_[index];
	}

	unsigned int size() const
	{
		return size_;
	}

  private:
	unsigned int size_;
	T			*array_;
};
