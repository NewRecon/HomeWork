#include <iostream>
#include <string>
#include "Array.cpp"
#include "String.cpp"
#include "Student.cpp"
#include "Jurnal.cpp"
using namespace std;

int main()
{
	//int* ar = new int[10]{1,2,3,4,5,6,7,8,9,0};
	//Array <int> ar0(ar, 10);
	//ar0.show();
	//ar0.addend(11);
	//ar0.show();
	//Array <int> ar1=ar0;
	//ar1.addend(99);
	//cout << "ar0 - ";
	//ar0.show();
	//cout << "ar1 - ";
	//ar1.show();
	//String str0("privet");
	//str0.show();
	//String str1 = str0;
	//str1.delLastEl();
	//str1.show();
	Student st1("Leon","Kennedy","Scott");
	st1.setMarkMath(3);
	st1.setMarkMath(2);
	st1.setMarkMath(2);
	st1.setMarkRuss(4);
	st1.setMarkRuss(4);
	st1.setMarkRuss(3);
	st1.setMarkPhys(5);
	st1.setMarkPhys(5);
	st1.setMarkPhys(4);
	Student st2("Maria", "Switch", "Borisovna");
	st2.setMarkMath(4);
	st2.setMarkMath(4);
	st2.setMarkMath(5);
	st2.setMarkRuss(4);
	st2.setMarkRuss(4);
	st2.setMarkRuss(3);
	st2.setMarkPhys(5);
	st2.setMarkPhys(5);
	st2.setMarkPhys(4);
	Jurnal st;
	st.addSt(st1);
	st.addSt(st2);
	st.showJurnal();
	st.showDebtor();
}
