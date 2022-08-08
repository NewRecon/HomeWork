#include <iostream>
using namespace std;
#include "Player.cpp"
#include "Warrior.cpp"
#include "Mage.cpp"
#include "Fire_mage.cpp"

int main()
{
	Warrior warrior("Varian", 10, 5);
	Mage mage("Khadgar", 20);
	Fire_mage fire_mage("Milhouse", 15, 10);

	warrior.show_info();
	warrior.skill();
	cout << endl;
	mage.show_info();
	mage.skill();
	cout << endl;
	fire_mage.show_info();
	fire_mage.skill();
}

