#include <iostream>
#include "Fraction.cpp"
using namespace std;

int main()
{
	Fraction f1(33, 33);
	Fraction f2(44, 88);
	f1.del(f2);
}