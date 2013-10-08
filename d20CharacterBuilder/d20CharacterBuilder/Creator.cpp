/*
Sam Assaf
6150748
COMP 345
Individual Assignment 3
*/

#include "CharacterBuilder.h"
#include "Creator.h"
#include "Character.h"

void Creator::setCharacterBuilder(CharacterBuilder* characterBuilder) {
	this->characterBuilder = characterBuilder;
}

//Returns the character created by the CharacterBuilder
Character* Creator::getCharacter() {
	return characterBuilder->getCharacter();
}
 
//Tells the CharacterBuilder to create a new character
void Creator::createCharacter(int race, int level) {
	characterBuilder->createNewCharacter(race, level);
	characterBuilder->buildAttributes();
}
