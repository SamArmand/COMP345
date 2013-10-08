/*
Sam Assaf
6150748
COMP 345
Individual Assignment 3
*/

#ifndef CREATOR_H
#define CREATOR_H

#include "CharacterBuilder.h"
#include "Character.h"

class Creator {
        public:
                void setCharacterBuilder(CharacterBuilder* characterBuilder);
 
                Character* getCharacter();
 
                void createCharacter(int race, int level);
 
        private:
                CharacterBuilder* characterBuilder;
};

#endif