#pragma once
#include <string>
#include "Order.h"
class Driver
{
private:
	std::string driverName;
	std::string phone;
	bool status = true; //true - free
	Order* orders = nullptr;
	int ordersCount = 0;
	float wallet = 0.f;
	float profit = 0;
public:
	Driver(){}
	~Driver();

	std::string getName();
	std::string getPhone();
	bool getStatus();
	float getWallet();
	float getProfit();


	void addOrder(std::string pointA, std::string pointB, float km, int hour, int min);
	void showOrders();

	void setName(std::string name);
	void setPhone(std::string phone);
	void setWallet(float cost);
};