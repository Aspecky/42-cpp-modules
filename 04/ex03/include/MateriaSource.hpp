#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include <cstddef>
#include <string>

class MateriaSource : public IMateriaSource {
  public:
	MateriaSource();
	MateriaSource(const MateriaSource &other);
	~MateriaSource();

	MateriaSource &operator=(MateriaSource other);

	virtual void learnMateria(AMateria *materia);
	virtual AMateria *createMateria(std::string const &type);

	static const size_t MAX_MATERIA = 4;

  private:
	size_t size_;
	AMateria *materias_[MateriaSource::MAX_MATERIA];
};
