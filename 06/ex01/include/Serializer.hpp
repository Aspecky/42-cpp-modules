#include <stdint.h>

struct Data {
	int _;
};

class Serializer {
  public:
	static uintptr_t serialize(Data *ptr);
	static Data	 *deserialize(uintptr_t raw);

  private:
	Serializer();
};
