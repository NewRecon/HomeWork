#pragma once
#include "Car.h"
class Taxi
{
private:
	Car* cars = nullptr;
	int carsCount = 0;
	float profit = 0;
public:
	Taxi(){}
	~Taxi();
	void run();
	void addCar(std::string carNumber, std::string model, std::string color,
		std::string driverName, std::string phone);
	void delCar(int a);
	void showAllCars();
	void showFreeCars();
	void Order(int id, std::string pointA, std::string pointB, float km, int hour, int min);
	void showOrders(int id);
	void getProfit();
	void showDriver(std::string num);
};