/*
Sam Assaf
6150748
COMP 345
Individual Assignment 3
*/

#include "Character.h"
#include "Dice.h"
#include "CharacterObserver.h"
#include <iostream>
#include <string>
#include <vector>
using namespace::std;

vector<CharacterObserver*> characterObservers;

//Fighter constructor
Character::Character (int raceChoice, int levelChoice) 

{

	race = raceChoice;

	strength = 0, dexterity = 0, constitution = 0, intelligence = 0, wisdom = 0, charisma = 0;
	strRaceMod = 0, dexRaceMod = 0, conRaceMod = 0, intRaceMod = 0, wisRaceMod = 0, chaRaceMod = 0;
	strMod = 0, dexMod = 0, conMod = 0, intMod = 0, wisMod = 0, chaMod = 0;
	armorClass = 0, armorBonus = 0, shieldBonus = 0;
	baseAttackBonus = 0, meleeAttackBonus = 0, rangedAttackBonus = 0;
	sizeMod = 0;
	hitPoints = 0;
	type = "";
	level = 1;

	for(i=0; i<6; ++i){
		results[i]= dice.roll_4d6();
	}

	for(i=0; i<6; i++){
		for(j=0; j<6; ++j) 
		{
			if (results[j] > max) {
				max = results[j];
				indexFound = j;
			}
		}

		results[indexFound] = 0;
		sortedResults[i] = max;
		max = 0;
	}

	//Set race modifiers
	switch (race) {

		//Human
		case 1 : 
			//Nothing
		break;

		//Dwarf
		case 2 :
			conRaceMod = 2;
			chaRaceMod = -2;
		break;

		//Elf
		case 3 :
			dexRaceMod = 2;
			conRaceMod = -2;
		break;

		//Gnome
		case 4 :
			conRaceMod = 2;
			strRaceMod = -2;
			
			sizeMod = 1;
		break;

		//Half-Elf
		case 5 : 
			//Nothing
		break;
		
		//Half-Orc
		case 6 :
			strRaceMod = 2;
			intRaceMod = -2;
			chaRaceMod = -2;
		break;

		//Halfling
		case 7 :
			dexRaceMod = 2;
			strRaceMod = -2;
			
			sizeMod = 1;
		break;

		//Invalid class
		default : 
			//Nothing
		break;
	}
		
	strength = strRaceMod;
	dexterity = dexRaceMod;
	constitution = conRaceMod;
	intelligence = intRaceMod;
	wisdom = wisRaceMod;
	charisma = chaRaceMod;

	//Hit Points

	hitPoints = dice.roll_d10() + conMod;

	//Armor Class

	armorClass = 10 + armorBonus + shieldBonus;

	//Attack Bonus

	baseAttackBonus = 1;

	meleeAttackBonus = baseAttackBonus + strMod + sizeMod;

	rangedAttackBonus = baseAttackBonus + dexMod + sizeMod;

	//Damage Bonus

	//Character has no inventory therefore does not have a Damage bonus 

	for (i=1; i<levelChoice; i++) {

		levelUp();

	}

}

//Abilities and modifiers

void Character::setStrength(int s) {
	
	strength = s;
	meleeAttackBonus -= strMod; //remove current strMod
	strMod = -5 + (strength/2);
	meleeAttackBonus += strMod; //add current strMod
	Notify();

}

void Character::setDexterity(int d) {

	dexterity = d;
	rangedAttackBonus -= dexMod; //remove current dexMod
	dexMod = -5 + (dexterity/2);
	rangedAttackBonus += dexMod; //add current dexMod
	Notify();

}

void Character::setConstitution(int c) {

	constitution = c;
	hitPoints -= conMod; //remove current conMod
	conMod = -5 + (constitution/2);
	hitPoints += conMod; //add new conMond
	Notify();

}

void Character::setIntelligence(int i) {

	intelligence = i;
	intMod = -5 + (intelligence/2);
	Notify();

}

void Character::setWisdom(int w) {

	wisdom = w;
	wisMod = -5 + (wisdom/2);
	Notify();

}

void Character::setCharisma(int c) {

	charisma = c;
	chaMod = -5 + (charisma/2);
	Notify();

}

void Character::setType(string t) {

	type = t;

}

//Attach an observer
void Character::Attach(class CharacterObserver* observer){

	characterObservers.push_back(observer);

}
  
//Detach an observer
void Character::Detach(class CharacterObserver* observer){

	for (int i = 0; i < characterObservers.size(); i++) {

		if (characterObservers[i] == observer) {

			characterObservers.erase(characterObservers.begin() + i);

		}

	}

}
 
//Notify observers
void Character::Notify(){

	for each (class CharacterObserver* characterObserver in characterObservers) {

		characterObserver->Update(this);

	}

}

//Level-up the character
void Character::levelUp() {

	level++;

	baseAttackBonus++;

	meleeAttackBonus = baseAttackBonus + strMod + sizeMod;

	rangedAttackBonus = baseAttackBonus + dexMod + sizeMod + rangePenalty;

	hitPoints = hitPoints + dice.roll_d10() + conMod; 

}

//Display fighter stats
void Character::display() {

	cout << endl;
	cout << "Race: ";

	switch(race)
	{

	case 1:
		cout << "Human";
	break;

	case 2:
		cout << "Dwarf";
	break;

	case 3:
		cout << "Elf";
	break;

	case 4:
		cout << "Gnome";
	break;

	case 5:
		cout << "Half-Elf";
	break;

	case 6:
		cout << "Half-Orc";
	break;

	case 7:
		cout << "Halfling";
	break;

	default:
		//Nothing
	break;

	}

	cout << endl;

	cout << "Class: Fighter" << endl;
	cout << endl;
	
	cout << "Type: " << type << endl;
	cout << "Level: " << level << endl;
	cout << endl;

	cout << "Strength: " << strength << " ";
	if (strMod > -1)
		cout << "+";
		cout << strMod << endl;

	cout << "Dexterity: " << dexterity << " ";
	if (dexMod > -1)
		cout << "+";
		cout << dexMod << endl;

	cout << "Constitution: " << constitution << " ";
	if (conMod > -1)
		cout << "+";
		cout << conMod << endl;

	cout << "Intelligence: " << intelligence << " ";
	if (intMod > -1)
		cout << "+";
		cout << intMod << endl;

	cout << "Wisdom: " << wisdom << " ";
	if (wisMod > -1)
		cout << "+";
		cout << wisMod << endl;

	cout << "Charisma: " << charisma << " ";
	if (chaMod > -1)
		cout << "+";
		cout << chaMod << endl;

	cout << endl;

	cout << "HP: " << hitPoints << endl;

	cout << "Armor Class: " << armorClass << endl;

	cout << endl;

	cout << "Melee Attack Bonus: " << meleeAttackBonus << endl;

	cout << "Ranged Attack Bonus: " << rangedAttackBonus << endl;

}