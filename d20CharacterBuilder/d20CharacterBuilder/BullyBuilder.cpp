/*
Sam Assaf
6150748
COMP 345
Individual Assignment 3
*/

#include "BullyBuilder.h"
#include "CharacterBuilder.h"
#include "Character.h"

void BullyBuilder::buildAttributes() {

	character->setType("Bully");
	character->setStrength(character->sortedResults[0]);
	character->setConstitution(character->sortedResults[1]);
	character->setDexterity(character->sortedResults[2]);
	character->setIntelligence(character->sortedResults[3]);
	character->setWisdom(character->sortedResults[4]);
	character->setCharisma(character->sortedResults[5]);

}