#include "Driver.h"

Driver::~Driver()
{
	delete[]orders;
}

std::string Driver::getName()
{
	return driverName;
}

std::string Driver::getPhone()
{
	return phone;
}

bool Driver::getStatus()
{
	return status;
}

float Driver::getWallet()
{
	return wallet;
}

float Driver::getProfit()
{
	return profit;
}

void Driver::addOrder(std::string pointA, std::string pointB, float km, int hour, int min)
{
	Order order(pointA, pointB, km, hour, min);
	int wallet = order.calculation();
	this->wallet += wallet;
	profit += wallet*0.85;
	if (orders == nullptr) orders = new Order[0];
	ordersCount++;
	Order* buf = new Order[ordersCount];
	for (int i = 0; i < ordersCount - 1; i++)
	{
		buf[i] = orders[i];
	}
	buf[ordersCount - 1] = order;
	delete[]orders;
	orders = buf;
	status = false;
}

void Driver::showOrders()
{
	std::cout << "Point A" << " : " << "Point B" << " : " << "KM" << " : "
		<< "Time" << " : " << "cost" << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
	for (int i = 0; i < ordersCount; i++)
	{
		orders[i].info();
	}
}

void Driver::setName(std::string name)
{
	driverName = name;
}

void Driver::setPhone(std::string phone)
{
	this->phone = phone;
}

void Driver::setWallet(float cost)
{
	wallet = cost;
}
