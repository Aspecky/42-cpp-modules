#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <cstddef>
#include <string>

class Character : public ICharacter {
  public:
	Character(const std::string &name = "Character");
	Character(const Character &other);
	~Character();

	Character &operator=(Character other);

	virtual std::string const &getName() const;
	virtual void equip(AMateria *materia);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter &target);

	static const size_t MAX_MATERIAS = 4;

  private:
	std::string name_;
	size_t nb_materias_;
	AMateria *materias_[Character::MAX_MATERIAS];
};
