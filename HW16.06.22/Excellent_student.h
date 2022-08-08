#pragma once
class Excellent_student : public Student
{
private:
	int grants;
	static int ex_count;
	static int sum_grants;
public:
	Excellent_student(){}
	Excellent_student(string firstName, string lastName, int grants) : Student(firstName, lastName)
	{
		this->grants = grants;
		ex_count++;
		sum_grants += grants;
	}
	void info()
	{
		cout << firstName << " " << lastName << endl;
		cout << "Math: ";
		for (int i = 0; i < size_math; i++)
		{
			cout << math[i] << " ";
		}
		cout << endl << "Russ: ";
		for (int i = 0; i < size_russ; i++)
		{
			cout << russ[i] << " ";
		}
		cout << endl << "Liter: ";
		for (int i = 0; i < size_liter; i++)
		{
			cout << liter[i] << " ";
		}
		cout << endl << "grants - " << grants << endl;
	}
	static int getSum_grants()
	{
		return sum_grants;
	}
	static int getEx_count()
	{
		return ex_count;
	}
	Excellent_student& operator = (const Excellent_student& other)
	{
		delete[]math;
		delete[]russ;
		delete[]liter;

		this->grants = other.grants;
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

