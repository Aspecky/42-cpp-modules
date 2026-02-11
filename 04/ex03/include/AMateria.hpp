#pragma once
#include <string>

class ICharacter;

class AMateria {
  public:
	AMateria(const std::string &type);
	AMateria(const AMateria &other);
	virtual ~AMateria();

	AMateria &operator=(const AMateria &other);

	virtual void use(ICharacter &target);
	const std::string &getType() const; // Returns the materia type
	virtual AMateria *clone() const = 0;

  protected:
	std::string type_;
};
