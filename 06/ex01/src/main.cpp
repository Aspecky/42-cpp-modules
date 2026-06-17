#include "Serializer.hpp"
#include <iostream>
#include <stdint.h>

int main()
{
	Data	 *original = new Data();
	uintptr_t raw =
		Serializer::serialize(original);
	Data *back = Serializer::deserialize(raw);

	std::cout << (original == back) << "\n"; // true

	delete original;
}
