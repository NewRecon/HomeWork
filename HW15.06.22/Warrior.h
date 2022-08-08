#pragma once
class Warrior : public Player
{
private:
	int strength;
	int protection;
public:
	Warrior(string nickname, int strength, int protection) : Player(nickname)
	{
		this->strength = strength;
		this->protection = protection;
	}
	void show_info()
	{
		cout << "Warrior ";
		Player::show_info();
		cout << "strength = " << strength << endl;
		cout << "protection = " << protection << endl;
	}
	void skill()
	{
		cout << "Warrior hit the enemies." << endl;
	}
};

