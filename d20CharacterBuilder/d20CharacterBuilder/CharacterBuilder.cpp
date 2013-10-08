/*
Sam Assaf
6150748
COMP 345
Individual Assignment 3
*/

#include "CharacterBuilder.h"
#include "Character.h"

Character* CharacterBuilder::getCharacter() {
        return character;
}

//Creates a new character
void CharacterBuilder::createNewCharacter(int race, int level) {
        character = new Character(race, level);
}