#pragma once
#include "Student.h"
#include "Excellent_student.h"
class School_class
{
private:
	string num;
	Student* students = nullptr;
	Excellent_student* ex_students = nullptr;
	int size_st = 0;
	int size_ex_st = 0;
public:
	School_class(){}
	School_class(string num)
	{
		this->num = num;
	}
	~School_class()
	{
		delete[]students;
		delete[]ex_students;
	}
	string getNum()
	{
		return num;
	}
	void add_st(Student& st)
	{
		Student* buf = new Student[size_st + 1];
		for (int i = 0; i < size_st; i++)
		{
			buf[i] = students[i];
		}
		buf[size_st] = st;
		delete[]students;
		students = buf;
		size_st++;
	}
	void add_ex_st(Excellent_student& st)
	{
		Excellent_student* buf = new Excellent_student[size_ex_st + 1];
		for (int i = 0; i < size_ex_st; i++)
		{
			buf[i] = ex_students[i];
		}
		buf[size_ex_st] = st;
		delete[]ex_students;
		ex_students = buf;
		size_ex_st++;
	}
	void print()
	{
		cout << "Students:" << endl << endl;
		for (int i = 0; i < size_st; i++)
		{
			cout << "\t";
			students[i].info();
		}
		if (size_ex_st!=0)
		{
			cout << endl << "Excellend students:" << endl << endl;
			for (int i = 0; i < size_ex_st; i++)
			{
				cout << "\t";
				ex_students[i].info();
			}
		}
	}
	School_class& operator = (const School_class& other)
	{
		delete[]students;
		delete[]ex_students;
		this->num = other.num;
		this->size_st = other.size_st;
		this->size_ex_st = other.size_ex_st;
		this->students = new Student[other.size_st];
		for (int i = 0; i < size_st; i++)
		{
			students[i] = other.students[i];
		}
		this->ex_students = new Excellent_student[other.size_ex_st];
		for (int i = 0; i < size_ex_st; i++)
		{
			ex_students[i] = other.ex_students[i];
		}
		return *this;
	}
};

