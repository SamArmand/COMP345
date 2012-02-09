/*
Sam Assaf
6150748
COMP 345
Individual Assignment 3
*/

#ifndef CHARACTEROBSERVER_H
#define CHARACTEROBSERVER_H
#include "Character.h"
#include <iostream>

class CharacterObserver
{
public:
	CharacterObserver();
	void Update(class Character* character);
};

#endif