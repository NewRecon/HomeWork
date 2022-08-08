#pragma once
class Fire_mage : public Mage
{
private:
	int fire_damage;
public:
	Fire_mage(string nickname, int mana, int fire_damage) : Mage(nickname, mana)
	{
		this->fire_damage = fire_damage;
	}
	void show_info()
	{
		cout << "Fire ";
		Mage::show_info();
		cout << "fire damage = " << fire_damage << endl;
	}
	void skill()
	{
		cout << "Fire mage burn all around himself." << endl;
	}
};

