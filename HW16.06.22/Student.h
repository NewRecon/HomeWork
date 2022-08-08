#pragma once
class Student
{
protected:
	string firstName;
	string lastName;
	int* math = new int[0];
	int* russ = new int[0];
	int* liter = new int[0];
	int size_math=0;
	int size_russ=0;
	int size_liter=0;
	static int count;
public:
	Student(){}
	Student(string firstName, string lastName)
	{
		this->firstName = firstName;
		this->lastName = lastName;
		count++;
	}
	Student(string firstName, string lastName, int* math, int* russ, int* liter) : Student(firstName, lastName)
	{
		this->size_math = _msize(math) / sizeof(math[0]);
		for (int i = 0; i < size_math; i++)
		{
			this->math[i] = math[i];
		}
		this->size_russ = _msize(russ) / sizeof(russ[0]);
		for (int i = 0; i < size_russ; i++)
		{
			this->russ[i] = russ[i];
		}
		this->size_liter = _msize(liter) / sizeof(liter[0]);
		for (int i = 0; i < size_liter; i++)
		{
			this->liter[i] = liter[i];
		}
	}
	~Student()
	{
		delete[]math;
		delete[]russ;
		delete[]liter;
	}
	static int getCount()
	{
		return count;
	}
	static void setCount(int c)
	{
		count = c;
	}
	void info()
	{
		cout << firstName << " " << lastName << endl;
		cout << "Math: ";
		for (int i = 0; i < size_math; i++)
		{
			cout << math[i] << " ";
		}
		cout << endl <<"Russ: ";
		for (int i = 0; i < size_russ; i++)
		{
			cout << russ[i] << " ";
		}
		cout << endl << "Liter: ";
		for (int i = 0; i < size_liter; i++)
		{
			cout << liter[i] << " ";
		}
		cout << endl;
	}
	void add_math_mark(int volume, int first, ...)
	{
		int* p = &first;
		int* buf = new int[size_math + volume];
		for (int i = 0; i < size_math; i++)
		{
			buf[i] = math[i];
		}
		for (int i = 0; i < volume; i++, p+=2)
		{
			buf[size_math + i] = *p;
		}
		delete[]math;
		math = buf;
		size_math+=volume;
	}
	void add_russ_mark(int volume, int first, ...)
	{
		int* p = &first;
		int* buf = new int[size_russ + volume];
		for (int i = 0; i < size_russ; i++)
		{
			buf[i] = russ[i];
		}
		for (int i = 0; i < volume; i++, p += 2)
		{
			buf[size_russ + i] = *p;
		}
		delete[]russ;
		russ = buf;
		size_russ += volume;
	}
	void add_liter_mark(int volume, int first, ...)
	{
		int* p = &first;
		int* buf = new int[size_liter + volume];
		for (int i = 0; i < size_liter; i++)
		{
			buf[i] = liter[i];
		}
		for (int i = 0; i < volume; i++, p += 2)
		{
			buf[size_liter + i] = *p;
		}
		delete[]liter;
		liter = buf;
		size_liter += volume;
	}
	Student& operator = (const Student& other)
	{
		delete[]math;
		delete[]russ;
		delete[]liter;

		this->firstName = other.firstName;
		this->lastName = other.lastName;
		this->size_math = other.size_math;
		this->size_russ = other.size_russ;
		this->size_liter = other.size_liter;
		this->math = new int[other.size_math];
		for (int i = 0; i < size_math; i++)
		{
			math[i] = other.math[i];
		}
		this->russ = new int[other.size_russ];
		for (int i = 0; i < size_russ; i++)
		{
			russ[i] = other.russ[i];
		}
		this->liter = new int[other.size_liter];
		for (int i = 0; i < size_liter; i++)
		{
			liter[i] = other.liter[i];
		}

		return *this;
	}
};

