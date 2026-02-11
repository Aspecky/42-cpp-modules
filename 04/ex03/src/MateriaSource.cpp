#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include <cstddef>
#include <iostream>
#include <string>
#include <utility>

MateriaSource::MateriaSource() : size_(0), materias_()
{
}

MateriaSource::MateriaSource(const MateriaSource &other)
	: size_(other.size_), materias_()
{
	for (size_t i = 0; i < size_; i++) {
		materias_[i] = other.materias_[i]->clone();
	}
}

MateriaSource::~MateriaSource()
{
	for (size_t i = 0; i < size_; i++) {
		delete materias_[i];
	}
}

MateriaSource &MateriaSource::operator=(MateriaSource other)
{
	std::cout << "Called MateriaSource::operator=" << std::endl;
	std::swap(size_, other.size_);
	std::swap(materias_, other.materias_);
	return *this;
}

void MateriaSource::learnMateria(AMateria *materia)
{
	if (!materia) {
		return;
	}

	if (size_ == MateriaSource::MAX_MATERIA) {
		std::cout << "MateriaSource inventory is full\n";
		return;
	}

	materias_[size_] = materia;
	++size_;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (size_t i = 0; i < size_; i++) {
		AMateria *m = materias_[i];
		if (m->getType() == type) {
			return m->clone();
		}
	}
	return NULL;
}
