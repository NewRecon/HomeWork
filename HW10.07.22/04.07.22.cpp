#include <iostream>
#include "Proxy.cpp"

int main()
{
	Proxy file("C:\\Users\\Взрослая академия\\Documents\\Shabanov\\C++\\04.07.22\\FileManager.txt");
	std::cout << file.getData(3);
}