#pragma once
#include <string>
#include<iostream>
class Order
{
private:
	std::string pointA;
	std::string pointB;
	int hour;
	int min;
	float km;
	float cost;
public:
	float calculation();
	Order(){}
	Order(std::string pointA, std::string pointB, float km, int hour, int min);
	void info();
};

