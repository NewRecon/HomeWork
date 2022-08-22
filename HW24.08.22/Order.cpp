#include "Order.h"

float Order::calculation()
{
	if (((hour == 7 && min>=30 || hour >= 8) && hour < 10) || hour >= 17 && hour < 20)
	{
		cost = 52 + (30 * km);
	}
	else cost = 52 + (25 * km);
	return cost;
}

Order::Order(std::string pointA, std::string pointB, float km, int hour, int min)
{
	this->pointA = pointA;
	this->pointB = pointB;
	this->km = km;
	this->hour = hour;
	this->min = min;
	calculation();
}

void Order::info()
{
	std::cout << pointA << " : " << pointB << " : " << km << " : " << hour << ":" << min
		<< " : " << cost << std::endl;
}
