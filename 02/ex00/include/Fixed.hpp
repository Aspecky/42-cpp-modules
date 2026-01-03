#pragma once

#define FRACTIONAL_BITS 8

class Fixed {
  public:
	Fixed();
	Fixed(const Fixed &other);
	~Fixed();

	Fixed &operator=(const Fixed &other);

	int getRawBits() const;
	void setRawBits(int raw);

  private:
	static int point;
	int fp;
};
