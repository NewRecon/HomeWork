#include <iostream>
#include "Student.cpp"
#include "Excellent_student.cpp"
#include "School_class.cpp"
#include "School.cpp"
using namespace std;

int Student::count = 0;
int Excellent_student::ex_count = 0;
int Excellent_student::sum_grants = 0;

int main()
{
	Student st1("Jhon", "Brik");
	st1.add_math_mark(1, 5);
	st1.add_math_mark(3, 4, 4, 3);
	st1.add_russ_mark(3, 5, 4, 3);
	st1.add_liter_mark(5, 4, 4, 3, 5, 4);
	Excellent_student st2("Maria", "Falk", 3500);
	st2.add_math_mark(3, 5, 4, 5);
	st2.add_russ_mark(3, 5, 5, 5);
	st2.add_liter_mark(5, 4, 5, 5, 5, 5);
	Student st3("Lui", "Stefani");
	st3.add_math_mark(3, 5, 4, 5);
	st3.add_russ_mark(4, 5, 3, 3, 4);
	st3.add_liter_mark(5, 4, 5, 3, 5, 3);
	Excellent_student st4("Gans", "Robenson", 4000);
	st4.add_math_mark(4, 5, 5, 5, 5);
	st4.add_russ_mark(3, 5, 5, 5);
	st4.add_liter_mark(5, 4, 5, 5, 5, 5);
	Student st5("Ashab", "Momedov");
	st5.add_math_mark(3, 5, 4, 5);
	st5.add_russ_mark(4, 3, 3, 5, 4);
	st5.add_liter_mark(5, 4, 5, 3, 5, 3);
	Student st6("Jhon", "Karter");
	st6.add_math_mark(3, 5, 4, 5);
	st6.add_russ_mark(4, 5, 3, 5, 4);
	st6.add_liter_mark(5, 4, 5, 3, 5, 3);
	Student st7("Liam", "Karter");
	st7.add_math_mark(3, 3, 4, 5);
	st7.add_russ_mark(4, 5, 3, 4, 4);
	st7.add_liter_mark(5, 4, 5, 3, 5, 3);
	Student st8("Boris", "Karter");
	st8.add_math_mark(3, 5, 4, 5);
	st8.add_russ_mark(4, 5, 3, 5, 4);
	st8.add_liter_mark(5, 4, 5, 3, 5, 3);
	Student st9("Kris", "Karter");
	st9.add_math_mark(3, 5, 4, 5);
	st9.add_russ_mark(4, 5, 3, 5, 4);
	st9.add_liter_mark(4, 4, 5, 3, 5);
	Student st10("Mike", "Yang");
	st10.add_math_mark(3, 5, 3, 5);
	st10.add_russ_mark(4, 5, 3, 5, 4);
	st10.add_liter_mark(5, 4, 5, 5, 5, 5);
	Student st11("Mason", "Smith");
	st11.add_math_mark(3, 5, 3, 5);
	st11.add_russ_mark(4, 5, 3, 5, 4);
	st11.add_liter_mark(5, 4, 5, 5, 5, 5);
	Student st12("Jacob", "Johnson");
	st12.add_math_mark(3, 5, 3, 5);
	st12.add_russ_mark(4, 5, 3, 5, 4);
	st12.add_liter_mark(5, 4, 5, 5, 5, 5);
	Student st13("William", "Williams");
	st13.add_math_mark(3, 5, 3, 5);
	st13.add_russ_mark(4, 5, 3, 5, 4);
	st13.add_liter_mark(5, 4, 5, 5, 5, 5);
	Student st14("Ethan", "Jones");
	st14.add_math_mark(3, 5, 3, 5);
	st14.add_russ_mark(4, 5, 3, 5, 4);
	st14.add_liter_mark(5, 4, 5, 5, 5, 5);
	Student st15("Michael", "Brown");
	st15.add_math_mark(3, 5, 3, 5);
	st15.add_russ_mark(4, 5, 3, 5, 4);
	st15.add_liter_mark(5, 4, 5, 5, 5, 5);
	Student st16("Alexander", "Davis");
	st16.add_math_mark(3, 5, 3, 5);
	st16.add_russ_mark(4, 5, 3, 5, 4);
	st16.add_liter_mark(5, 4, 5, 5, 5, 5);
	Student st17("Andrew", "Miller");
	st17.add_math_mark(3, 5, 3, 5);
	st17.add_russ_mark(4, 5, 3, 5, 4);
	st17.add_liter_mark(5, 4, 5, 5, 5, 5);
	Student st18("Brian", "Wilson");
	st18.add_math_mark(3, 5, 3, 5);
	st18.add_russ_mark(4, 5, 3, 5, 4);
	st18.add_liter_mark(5, 4, 5, 5, 5, 5);

	School_class class_8a("8A");
	class_8a.add_st(st1);
	class_8a.add_ex_st(st2);
	class_8a.add_st(st3);
	School_class class_8b("8B");
	class_8b.add_st(st5);
	class_8b.add_st(st6);
	class_8b.add_st(st7);
	School_class class_9a("9A");
	class_9a.add_st(st8);
	class_9a.add_ex_st(st4);
	class_9a.add_st(st9);
	class_9a.add_st(st10);
	School_class class_9b("9B");
	class_9b.add_st(st11);
	class_9b.add_st(st12);
	class_9b.add_st(st13);
	class_9b.add_st(st14);
	School_class class_9c("9C");
	class_9c.add_st(st15);
	class_9c.add_st(st16);
	class_9c.add_st(st17);
	class_9c.add_st(st18);

	School school;
	school.add_clas(class_8a);
	school.add_clas(class_8b);
	school.add_clas(class_9a);
	school.add_clas(class_9b);
	school.add_clas(class_9c);

	school.show_school();
	cout << endl;

	cout << "Total excellent students - " << Excellent_student::getEx_count() << endl;
	cout << endl;

	cout << "Sum of grants - " << Excellent_student::getSum_grants() << endl;
	cout << endl;

	cout << "Total students - " << Student::getCount() << endl;
}
