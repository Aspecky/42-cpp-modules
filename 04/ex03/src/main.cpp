#include "Character.hpp"
#include "Cure.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include <iostream>

void printSeparator(const std::string &title)
{
	std::cout << "\n========== " << title << " ==========\n" << std::endl;
}

void testBasicFunctionality()
{
	printSeparator("Test 1: Basic Functionality");

	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter *me = new Character("me");
	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter *bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
}

void testCharacterCopy()
{
	printSeparator("Test 2: Character Copy Constructor");

	Character *original = new Character("original");
	original->equip(new Ice());
	original->equip(new Cure());

	Character *copy = new Character(*original);
	ICharacter *target = new Character("target");

	std::cout << "Original character using materias:" << std::endl;
	original->use(0, *target);
	original->use(1, *target);

	std::cout << "\nCopied character using materias:" << std::endl;
	copy->use(0, *target);
	copy->use(1, *target);

	delete target;
	delete copy;
	delete original;
}

void testCharacterAssignment()
{
	printSeparator("Test 3: Character Assignment Operator");

	Character original("original");
	original.equip(new Ice());
	original.equip(new Cure());

	Character assigned("assigned");
	assigned.equip(new Ice());

	std::cout << "Before assignment, assigned character:" << std::endl;
	Character target("target");
	assigned.use(0, target);

	assigned = original;

	std::cout << "\nAfter assignment, assigned character:" << std::endl;
	assigned.use(0, target);
	assigned.use(1, target);
}

void testUnequip()
{
	printSeparator("Test 4: Unequip Functionality");

	Character character("test");
	AMateria *ice = new Ice();
	AMateria *cure = new Cure();

	character.equip(ice);
	character.equip(cure);

	ICharacter *target = new Character("target");

	std::cout << "Using materias before unequip:" << std::endl;
	character.use(0, *target);
	character.use(1, *target);

	std::cout << "\nUnequipping slot 0..." << std::endl;
	character.unequip(0);

	std::cout << "Using slot 0 after unequip (should do nothing):" << std::endl;
	character.use(0, *target);

	std::cout << "Using slot 1 after unequip:" << std::endl;
	character.use(1, *target);

	// Clean up unequipped materia (user's responsibility)
	delete ice;
	// Also cleanup cure (unequip it first)
	character.unequip(1);
	delete cure;
	delete target;
}

void testEquipLimit()
{
	printSeparator("Test 5: Equip More Than 4 Materias");

	Character character("test");
	AMateria *materias[5] = {NULL};

	std::cout << "Equipping 5 materias (max is 4)..." << std::endl;
	for (int i = 0; i < 5; i++) {
		materias[i] = (i % 2 == 0) ? static_cast<AMateria *>(new Ice())
								   : static_cast<AMateria *>(new Cure());
		std::cout << "Equipping materia " << i << "..." << std::endl;
		character.equip(materias[i]);
	}

	ICharacter *target = new Character("target");
	std::cout << "\nUsing all equipped materias:" << std::endl;
	for (int i = 0; i < 5; i++) {
		std::cout << "Slot " << i << ": ";
		character.use(i, *target);
	}

	// Clean up any materias that couldn't be equipped (5th one)
	for (int i = 4; i < 5; i++) {
		delete materias[i];   // Delete the materia that wasn't equipped
	}

	delete target;
}

void testLearnLimit()
{
	printSeparator("Test 6: Learn More Than 4 Materias");

	IMateriaSource *src = new MateriaSource();
	AMateria *materias[5] = {NULL};

	std::cout << "Learning 5 materias (max is typically 4)..." << std::endl;
	for (int i = 0; i < 5; i++) {
		materias[i] = (i % 2 == 0) ? static_cast<AMateria *>(new Ice())
								   : static_cast<AMateria *>(new Cure());
		std::cout << "Learning materia " << i << " (" << materias[i]->getType()
				  << ")..." << std::endl;
		src->learnMateria(materias[i]);
	}

	// Clean up materia that couldn't be learned (5th one)
	delete materias[4];

	delete src;
}

void testUnknownMateria()
{

	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << "Creating known materia 'ice':" << std::endl;
	AMateria *known = src->createMateria("ice");
	if (known)
		std::cout << "Created: " << known->getType() << std::endl;
	delete known;

	std::cout << "\nCreating unknown materia 'fire':" << std::endl;
	AMateria *unknown = src->createMateria("fire");
	if (unknown)
		std::cout << "Created: " << unknown->getType() << std::endl;
	else
		std::cout << "Failed to create unknown materia (expected)" << std::endl;

	delete src;
}

void testInvalidSlots()
{
	printSeparator("Test 8: Use Invalid Slot Indices");

	Character character("test");
	character.equip(new Ice());

	ICharacter *target = new Character("target");

	std::cout << "Using valid slot 0:" << std::endl;
	character.use(0, *target);

	std::cout << "\nUsing invalid slot -1:" << std::endl;
	character.use(-1, *target);

	std::cout << "\nUsing invalid slot 10:" << std::endl;
	character.use(10, *target);

	std::cout << "\nUnequipping invalid slot -1:" << std::endl;
	character.unequip(-1);

	std::cout << "\nUnequipping invalid slot 10:" << std::endl;
	character.unequip(10);

	delete target;
}

void testNullEquip()
{
	printSeparator("Test 9: Equip NULL Materia");

	Character character("test");

	std::cout << "Equipping NULL materia..." << std::endl;
	character.equip(NULL);

	std::cout << "Equipping valid materia..." << std::endl;
	character.equip(new Ice());

	ICharacter *target = new Character("target");
	character.use(0, *target);

	delete target;
}

void testMateriaLifecycle()
{
	printSeparator("Test 10: Materia Lifecycle Management");

	Character character("test");
	AMateria *ice1 = new Ice();
	AMateria *ice2 = new Ice();
	AMateria *cure1 = new Cure();

	std::cout << "Equipping 3 materias..." << std::endl;
	character.equip(ice1);
	character.equip(ice2);
	character.equip(cure1);

	ICharacter *target = new Character("target");
	std::cout << "\nUsing all materias:" << std::endl;
	character.use(0, *target);
	character.use(1, *target);
	character.use(2, *target);

	std::cout << "\nUnequipping slot 1..." << std::endl;
	character.unequip(1);

	std::cout << "Re-equipping slot 1 with new materia..." << std::endl;
	character.equip(new Cure());

	std::cout << "\nUsing all materias after re-equip:" << std::endl;
	character.use(0, *target);
	character.use(1, *target);
	character.use(2, *target);

	// Clean up the unequipped materia
	delete ice2;
	delete target;
}

int main()
{
	testBasicFunctionality();
	testCharacterCopy();
	testCharacterAssignment();
	testUnequip();
	testEquipLimit();
	testLearnLimit();
	testUnknownMateria();
	testInvalidSlots();
	testNullEquip();
	testMateriaLifecycle();

	std::cout << "\n========== All Tests Complete ==========\n" << std::endl;
}
