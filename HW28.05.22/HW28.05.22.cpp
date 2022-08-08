#include <iostream>
#include "String.cpp"
using namespace std;


int main()
{
	char* str = new char[]{"ell"};
	String a(str);
	char* str2 = new char[] {"_hello_"};
	String b(str2);
	a.print();
	b.print();
	cout << b.find_last_of(a);
}
