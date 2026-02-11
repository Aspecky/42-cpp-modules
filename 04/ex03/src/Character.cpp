#include "Character.hpp"
#include "AMateria.hpp"
#include <cstddef>
#include <iostream>
#include <string>
#include <utility>

Character::Character(const std::string &name)
	: name_(name), nb_materias_(0), materias_()
{
}

Character::Character(const Character &other)
	: name_(other.name_), nb_materias_(other.nb_materias_), materias_()
{
	for (size_t i = 0; i < MAX_MATERIAS; ++i) {
		AMateria *materia = other.materias_[i];
		if (materia) {
			materias_[i] = materia->clone();
		}
	}
}

Character::~Character()
{
	for (size_t i = 0; i < nb_materias_; ++i) {
		delete materias_[i];
	}
}

Character &Character::operator=(Character other)
{
	std::swap(name_, other.name_);
	std::swap(materias_, other.materias_);
	std::swap(nb_materias_, other.nb_materias_);
	return *this;
}

std::string const &Character::getName() const
{
	return name_;
}

void Character::equip(AMateria *materia)
{
	if (!materia) {
		return;
	}

	if (nb_materias_ == MAX_MATERIAS) {
		std::cout << name_ << "'s inventory is full\n";
		return;
	}

	size_t idx = 0;
	for (size_t i = MAX_MATERIAS; i-- > 0;) {
		if (materias_[i] == NULL) {
			idx = i;
		}
		else if (materias_[i] == materia) {
			return;
		}
	}

	materias_[idx] = materia;
	++nb_materias_;
	std::cout << name_ << " has equipped " << materia->getType() << "\n";
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= int(MAX_MATERIAS)) {
		std::cout << "idx: " << idx << " is out of range\n";
		return;
	}

	if (materias_[idx] == NULL) {
		return;
	}

	materias_[idx] = NULL;
	--nb_materias_;
	std::cout << name_ << " has unequipped slot " << idx << "\n";
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= int(MAX_MATERIAS)) {
		std::cout << "idx: " << idx << " is out of range\n";
		return;
	}

	if (materias_[idx] == NULL) {
		return;
	}

	materias_[idx]->use(target);
}
