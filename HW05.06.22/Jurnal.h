#pragma once
class Jurnal
{
private:
	Student* students;
	int size=0;
public:
	Jurnal()
	{

	}
	~Jurnal()
	{
		delete[]students;
	}
	Jurnal(const Jurnal& st2)
	{
		this->students = students;
		this->size = size;
	}
	void addSt(Student st)
	{
		Student* buf = new Student[size + 1];
		for (int i = 0; i < size; i++)
		{
			buf[i] = students[i];
		}
		buf[size] = st;
		delete[]students;
		students = buf;
		size++;
	}
	void delSt(Student st, int index)
	{
		Student* buf = new Student[size - 1];
		for (int i = 0; i < index; i++)
		{
			buf[i] = students[i];
		}
		for (int i = index; i < size; i++)
		{
			buf[i] = students[i + 1];
		}
		delete[]students;
		students = buf;
		size--;
	}
	void showDebtor()
	{
		cout << endl << "Debtors: " << endl;
		for (int i = 0; i < size; i++)
		{
			if (students[i].avgMath() < 3 || students[i].avgRuss() < 3 || students[i].avgPhys() < 3)
			{
				students[i].show();
			}
		}
	}
	void showJurnal()
	{
		for (int i = 0; i < size; i++)
		{
			students[i].show();
		}
	}
};

