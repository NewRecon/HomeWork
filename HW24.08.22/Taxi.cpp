#include "Taxi.h"

Taxi::~Taxi()
{
	delete[] cars;
}

void Taxi::run()
{
	int id = 0, km, hour, min;
	std::string pointA, pointB, num;
	bool flag = true;
	while (flag)
	{
		int val=-1;
		while (val < 0 || val > 8)
		{
			std::cout << "1.Show all cars" << std::endl;
			std::cout << "2.Show free cars" << std::endl;
			std::cout << "3.Show drivers" << std::endl;
			std::cout << "4.Order" << std::endl;
			std::cout << "5.Show driver orders" << std::endl;
			std::cout << "6.Show profit" << std::endl;
			std::cout << "7.Delete car and driver" << std::endl;
			std::cout << "8.Add car and driver" << std::endl;
			std::cout << "0.Exit" << std::endl << std::endl;
			std::cout << "Enter action number: ";
			std::cin >> val;
			switch (val)
			{
			case 0:
				flag = false;
				system("cls");
				std::cout << "Have a nice day!" << std::endl;
				system("pause");
				break;
			case 1:
				system("cls");
				showAllCars();
				if (carsCount == 0)
				{
					std::cout << "Park is empty!!!" << std::endl;
					system("pause");
					break;
				}
				system("pause");
				break;
			case 2:
				system("cls");
				showFreeCars();
				if (carsCount == 0)
				{
					std::cout << "Park is empty!!!" << std::endl;
					system("pause");
					break;
				}
				system("pause");
				break;
			case 3:
				system("cls");
				std::cout << "Input car number" << std::endl;
				std::cin >> num;
				system("cls");
				showDriver(num);
				system("pause");
				break;
			case 4:
				system("cls");
				showFreeCars();
				if (carsCount == 0)
				{
					std::cout << "Park is empty!!!" << std::endl;
					system("pause");
					break;
				}
				else
				{
					std::cout << std::endl << "Input car id: ";
					std::cin >> id;
					system("cls");
					std::cout << "Input point A: ";
					std::cin >> pointA;
					system("cls");
					std::cout << "Input point B: ";
					std::cin >> pointB;
					system("cls");
					std::cout << "Input distance (km): ";
					std::cin >> km;
					system("cls");
					std::cout << "Input hour: ";
					std::cin >> hour;
					system("cls");
					std::cout << "Input minutes" << std::endl;
					std::cout << hour << ":";
					std::cin >> min;
					Order(id, pointA, pointB, km, hour, min);
					break;
				}
			case 5:
				system("cls");
				showAllCars();
				if (carsCount == 0)
				{
					std::cout << "Park is empty!!!" << std::endl;
					system("pause");
					break;
				}
				std::cout << std::endl << "Input car id: ";
				std::cin >> id;
				system("cls");
				showOrders(id);
				system("pause");
				break;
			case 6:
				system("cls");
				getProfit();
				system("pause");
				break;
			case 7:
				system("cls");
				showAllCars();
				std::cout << std::endl << "Input car id: ";
				std::cin >> id;
				delCar(id);
				break;
			case 8:
				system("cls");
				std::cout << "Input car number" << std::endl;
				std::string carNumber="";
				std::cin >> carNumber;
				system("cls");
				std::cout << "Input model" << std::endl;
				std::string model="";
				std::cin >> model;
				system("cls");
				std::cout << "Input color" << std::endl;
				std::string color = "";
				std::cin >> color;
				system("cls");
				std::cout << "Input driver name" << std::endl;
				std::string driverName = "";
				std::cin >> driverName;
				system("cls");
				std::cout << "Input phone" << std::endl;
				std::string phone = "";
				std::cin >> phone;
				system("cls");
				addCar(carNumber, model, color, driverName, phone);
				break;
			}
			system("cls");
		}
	}
}

void Taxi::addCar(std::string carNumber, std::string model, std::string color,
	std::string driverName, std::string phone)
{
	Car car(carNumber, model, color, driverName, phone);
	if (cars == nullptr) cars = new Car[0];
	carsCount++;
	Car* buf = new Car[carsCount];
	for (int i = 0; i < carsCount-1; i++)
	{
		buf[i] = cars[i];
	}
	buf[carsCount-1] = car;
	delete[]cars;
	cars = buf;
}

void Taxi::delCar(int id)
{
	carsCount--;
	Car* buf = new Car[carsCount];
	int k = 0;
	for (int i = 0; i < id-1; i++)
	{
		buf[k++] = cars[i];
	}
	for (int i = id; i <= carsCount; i++)
	{
		buf[k++] = cars[i];
	}
	delete[]cars;
	cars = buf;
}

void Taxi::showAllCars()
{
	std::cout << "STATUS : Number : Name : Model : Color : Phone : Profit" << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
	for (int i = 0; i < carsCount; i++)
	{
		std::cout << i + 1 << " ";
		cars[i].showInfo();
	}
	std::cout << std::endl;
}

void Taxi::showFreeCars()
{
	std::cout << "STATUS : Number : Name : Model : Color : Phone : Profit" <<std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
	for (int i = 0; i < carsCount; i++)
	{
		std::cout << i + 1 << " ";
		if (cars[i].getStatus()) cars[i].showInfo();
	}
	std::cout << std::endl;
}

void Taxi::Order(int id, std::string pointA, std::string pointB, float km, int hour, int min)
{
	cars[id - 1].addOrder(pointA, pointB, km, hour, min);
}

void Taxi::showOrders(int id)
{
	cars[id-1].showOrders();
}

void Taxi::getProfit()
{
	for (int i = 0; i < carsCount; i++)
	{
		profit += cars[i].getWallet()*0.15;
	}
	std::cout << profit << std::endl;
}

void Taxi::showDriver(std::string num)
{
	for (int i = 0; i < carsCount; i++)
	{
		if (cars[i].getNumber() == num)
		{
			cars[i].showDriver();
		}
	}
}
