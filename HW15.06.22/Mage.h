#pragma once
class Mage : public Player
{
protected:
	int mana;
public:
	Mage(string nickname, int mana) : Player(nickname)
	{
		this->mana = mana;
	}
	void show_info()
	{
		cout << "Mage ";
		Player::show_info();
		cout << "mana = " << mana << endl;
	}
	void skill()
	{
		cout << "Mage cast the spell." << endl;
	}
};

