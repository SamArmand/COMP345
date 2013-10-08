/*
Sam Assaf
6150748
COMP 345
Individual Assignment 3
*/

#ifndef CHARACTERBUILDER_H
#define CHARACTERBUILDER_H
#include "Character.h"

class CharacterBuilder {
        
		public:
                Character* getCharacter();
 
                void createNewCharacter(int race, int level);
 
                virtual void buildAttributes() = 0;
 
        protected:
                Character* character;
};

#endif