#pragma once
class Player
{
protected:
	string nickname;
	int level = 1;
	int health = 100;
public:
	Player(string nickname)
	{
		this->nickname = nickname;
	}
	void show_info()
	{
		cout << nickname << " - " << level << " lv., health - " << health << endl;
	}
};

