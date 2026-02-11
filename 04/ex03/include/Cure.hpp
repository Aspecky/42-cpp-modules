#pragma once
#include "AMateria.hpp"

class Cure : public AMateria {
  public:
	Cure();
	Cure(const Cure &other);
	virtual ~Cure();

	Cure &operator=(const Cure &other);
	virtual void use(ICharacter &target);
	virtual Cure *clone() const;
};
