#pragma once
#include <string>
#include "Driver.h"
#include <iostream>
class Car
{
private:
	std::string carNumber;
	std::string model;
	std::string color;
	Driver driver;
public:
	Car(){}
	Car(std::string carNumber, std::string model, std::string color, std::string driverName,
		std::string phone);
	void showInfo();
	void addOrder(std::string pointA, std::string pointB, float km, int hour, int min);
	void showOrders();

	bool getStatus();
	float getWallet();
	std::string getNumber();

	void setWallet(float val);
	void showDriver();
};