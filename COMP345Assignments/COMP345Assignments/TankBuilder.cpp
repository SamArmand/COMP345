/*
Sam Assaf
6150748
COMP 345
Individual Assignment 3
*/

#include "TankBuilder.h"
#include "CharacterBuilder.h"
#include "Character.h"

//Distributes points according to Tank preferences
void TankBuilder::buildAttributes() {

	character->setType("Tank");
	character->setConstitution(character->sortedResults[0]);
	character->setDexterity(character->sortedResults[1]);
	character->setStrength(character->sortedResults[2]);
	character->setIntelligence(character->sortedResults[3]);
	character->setWisdom(character->sortedResults[4]);
	character->setCharisma(character->sortedResults[5]);

}