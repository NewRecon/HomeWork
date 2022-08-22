#include "Car.h"

Car::Car(std::string carNumber, std::string model, std::string color, std::string driverName,
	std::string phone)
{
	this->carNumber = carNumber;
	this->model = model;
	this->color = color;
	driver.setName(driverName);
	driver.setPhone(phone);
}

void Car::showInfo()
{
	std::string stat = "free";
	if (!driver.getStatus()) stat = "busy";

	std::cout << stat << " : " << carNumber << " : " << driver.getName() << " : " << model
		<< " : " << color << " : " << driver.getPhone() << " : " << driver.getProfit() << std::endl;
}

void Car::addOrder(std::string pointA, std::string pointB, float km, int hour, int min)
{
	driver.addOrder(pointA, pointB, km, hour, min);
}

void Car::showOrders()
{
	driver.showOrders();
}

bool Car::getStatus()
{
	return driver.getStatus();
}

float Car::getWallet()
{
	return driver.getWallet();
}

std::string Car::getNumber()
{
	return carNumber;
}

void Car::setWallet(float val)
{
	driver.setWallet(val);
}

void Car::showDriver()
{
	std::cout << driver.getName() << " : " << driver.getPhone() << std::endl;
}
