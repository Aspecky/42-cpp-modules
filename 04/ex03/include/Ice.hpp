#pragma once
#include "AMateria.hpp"

class Ice : public AMateria {
  public:
	Ice();
	Ice(const Ice &other);
	virtual ~Ice();

	Ice &operator=(const Ice &other);
	virtual void use(ICharacter &target);
	virtual Ice *clone() const;
};
