#include <iostream>
#include "Proxy.cpp"

int main()
{
	Proxy file("C:\\Users\\99max\\Desktop\\IT\\C++\\!HW\\04.07.22\\FileManager.txt");
	std::cout << file.getData(3);
	std::cout << file.getData(3);
}