#include "Reader.hpp"
#include <cctype>
#include <cstddef>

inline bool digit(unsigned char c)
{
	return c >= '0' && c <= '9';
}

inline bool vchar(unsigned char c)
{
	return (c >= '!' && c <= '~');
}

inline bool octet(unsigned char /*c*/)
{
	return true;
}

inline bool sign(unsigned char c)
{
	return (c == '+' || c == '-');
}

inline bool whitespace(unsigned char c)
{
	return std::isspace(c);
}

// char = ( "'" octet "'" ) / octet
struct Char {
	const char *operator()(const char *pos, const char *end) const
	{
		Reader r(pos, static_cast<size_t>(end - pos));

		if (r.consume('\'')) {
			if (!r.consumeOne(octet)) {
				return 0;
			}
			if (!r.consume('\'')) {
				return 0;
			}
		}
		else {
			if (!r.consumeOne(octet)) {
				return 0;
			}
		}

		return r.pos;
	}
};

// int = [sign] 1*digit
struct Int {
	const char *operator()(const char *pos, const char *end) const
	{
		Reader r(pos, static_cast<size_t>(end - pos));

		r.consumeOne(sign);

		if (!r.consumeWhile(digit)) {
			return 0;
		}

		return r.pos;
	}
};

// double = [sign] ( ( *digit "." 1*digit ) / ( 1*digit "." *digit ) )
struct Double {
	const char *operator()(const char *pos, const char *end) const
	{
		Reader r(pos, static_cast<size_t>(end - pos));

		r.consumeOne(sign);

		if (r.consumeWhile(digit)) {
			if (!r.consume('.')) {
				return 0;
			}
			r.consumeWhile(digit);
		}
		else {
			if (!r.consume('.')) {
				return 0;
			}
			if (!r.consumeWhile(digit)) {
				return 0;
			}
		}

		return r.pos;
	}
};

// float = double "f"
struct Float {
	const char *operator()(const char *pos, const char *end) const
	{
		Reader r(pos, static_cast<size_t>(end - pos));

		if (!r.consumeRule(Double())) {
			return 0;
		}
		if (!r.consumeLiteral("f")) {
			return 0;
		}

		return r.pos;
	}
};

// pseudo-literal = [sign] "inf" / "nan" ["f"]
struct PseudoLiteral {
	const char *operator()(const char *pos, const char *end) const
	{
		Reader r(pos, static_cast<size_t>(end - pos));

		r.consumeOne(sign);

		if (!r.consumeLiteral("inf") && !r.consumeLiteral("nan")) {
			return 0;
		}

		r.consumeLiteral("f");

		return r.pos;
	}
};

// pseudo-float = pseudo-double "f"
// struct PseudoFloat {
// 	const char *operator()(const char *pos, const char *end) const
// 	{
// 		Reader r(pos, static_cast<size_t>(end - pos));

// 		if (!r.consumeRule(PseudoLiteral())) {
// 			return 0;
// 		}
// 		if (!r.consumeLiteral("f")) {
// 			return 0;
// 		}

// 		return r.pos;
// 	}
// };
