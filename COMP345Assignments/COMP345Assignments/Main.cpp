/*
Sam Assaf
6150748
COMP 345
Individual Assignment 3
*/

/*
Please note that this driver is purely for controlled testing purposes.
It does not prevent you from inputting an invalid choice.
*/

#include <iostream>
#include "Character.h"
#include "Creator.h"
#include "BullyBuilder.h"
#include "NimbleBuilder.h"
#include "TankBuilder.h"
#include <list>
using namespace::std;

int main()
{
	//Setting up Builders
	Creator creator;
    CharacterBuilder* bullyBuilder = new BullyBuilder();
    CharacterBuilder* nimbleBuilder = new NimbleBuilder();
	CharacterBuilder* tankBuilder = new TankBuilder();

	int race, level, type, attribute, value;
	int hold; //nothing, just to hold the promp to view output

	cout << "Character Races: " << endl << endl;
	cout << "1. Human" << endl;
	cout << "2. Dwarf" << endl;
	cout << "3. Elf" << endl;
	cout << "4. Gnome" << endl;
	cout << "5. Half-Elf" << endl;
	cout << "6. Half-Orc" << endl;
	cout << "7. Halfling" << endl << endl;

	cout << "Which race would you like your character to belong to?: ";
	cin >> race;

	cout << "Character Types: " << endl << endl;
	cout << "1. Bully" << endl;
	cout << "2. Nimble" << endl;
	cout << "3. Tank" << endl << endl;

	cout << endl;

	cout << "Which type would you like your character to belong to?: ";
	cin >> type;

	cout << "What level would you like your character to be?: ";
	cin >> level;

	//Decide which CharacterBuilder to use
	switch(type) {

		case 1:
			creator.setCharacterBuilder(bullyBuilder);
		break;

		case 2:
			creator.setCharacterBuilder(nimbleBuilder);
		break;

		case 3:
			creator.setCharacterBuilder(tankBuilder);
		break;

		default:
			//Nothing
		break;

	}

	//Create Character through Creator
    creator.createCharacter(race, level);
 
    Character* character = creator.getCharacter();
    character->display();


	//Modify character to show basic Observer functionality

	CharacterObserver* observer = new CharacterObserver();

	character->Attach(observer);

	cout << "Character Attributes: " << endl << endl;
	cout << "1. Strength" << endl;
	cout << "2. Dexterity" << endl;
	cout << "3. Constitution" << endl;
	cout << "4. Intelligence" << endl;
	cout << "5. Wisdom" << endl;
	cout << "6. Charisma" << endl << endl;

	cout << "Which attribute would you like to change?: ";
	cin >> attribute;
	cout << "Please input a new value for this attribute: ";
	cin >> value;

	cout << endl;

	switch (attribute) {

		case 1:
			character->setStrength(value);
		break;

		case 2:
			character->setDexterity(value);
		break;

		case 3:
			character->setConstitution(value);
		break;

		case 4:
			character->setIntelligence(value);
		break;

		case 5:
			character->setWisdom(value);
		break;

		case 6:
			character->setCharisma(value);
		break;

		default:
			//Nothing
		break;

	}

	cin >> hold;

	return 0;

}