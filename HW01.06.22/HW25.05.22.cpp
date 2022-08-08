#include <iostream>
#include "Fraction.cpp"
#include "Complex.cpp"
using namespace std;

int main()
{
	//Fraction f1(3,71,72, false);
	//Fraction f2(5,12);
	//Fraction f3 = f1/f2+f2*f1;
	//f1.print();
	//f2.print();
	//f3.print();
	//Fraction f4 = f3+f2;
	//f4.print();
	Complex<float> z1(3,4);
	Complex<float> z2(2,2);
	z1.print();
	z2.print();
	Complex<float> z3 = z1 / z2;
	z3.print();
}