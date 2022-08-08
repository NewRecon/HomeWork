#pragma once
class Student
{
private:
	string firstName;
	string lastName;
	string otchestvo;
	int* math;
	int* russ;
	int* phys;
	int sizeMath = 0;
	int sizeRuss = 0;
	int sizePhys = 0;
public:
	Student()
	{
		
	}
	Student(string firstName, string lastName, string otchestvo)
	{
		this->firstName = firstName;
		this->lastName = lastName;
		this->otchestvo = otchestvo;
	}
	~Student()
	{
		delete[]math;
		delete[]russ;
		delete[]phys;
	}
	Student(const Student& st2)
	{
		this->firstName = st2.firstName;
		this->lastName = st2.lastName;
		this->otchestvo = st2.otchestvo;
		this->sizeMath = st2.sizeMath;
		this->sizeRuss = st2.sizeRuss;
		this->sizePhys = st2.sizePhys;
		math = new int[sizeMath];
		for (int i = 0; i < sizeMath; i++)
		{
			math[i] = st2.math[i];
		}
		russ = new int[sizeRuss];
		for (int i = 0; i < sizeRuss; i++)
		{
			russ[i] = st2.russ[i];
		}
		phys = new int[sizePhys];
		for (int i = 0; i < sizePhys; i++)
		{
			phys[i] = st2.phys[i];
		}
	}
	void setMarkMath(int m)
	{
		int* buf = new int[sizeMath + 1];
		for (int i=0;i<sizeMath;i++)
		{
			buf[i] = math[i];
		}
		buf[sizeMath] = m;
		delete[]math;
		math = buf;
		sizeMath++;
	}
	void setMarkRuss(int m)
	{
		int* buf = new int[sizeRuss + 1];
		for (int i = 0; i < sizeRuss; i++)
		{
			buf[i] = russ[i];
		}
		buf[sizeRuss] = m;
		delete[]russ;
		russ = buf;
		sizeRuss++;
	}
	void setMarkPhys(int m)
	{
		int* buf = new int[sizePhys + 1];
		for (int i = 0; i < sizePhys; i++)
		{
			buf[i] = phys[i];
		}
		buf[sizePhys] = m;
		delete[]phys;
		phys = buf;
		sizePhys++;
	}
	void currentMarkMath(int index, int m)
	{
		math[index-1] = m;
	}
	void currentMarkRuss(int index, int m)
	{
		russ[index-1] = m;
	}
	void currentMarkPhys(int index, int m)
	{
		phys[index-1] = m;
	}
	void show()
	{
		cout << firstName << " " << lastName << " " << otchestvo << endl;
		cout << "Math: ";
		for (int i = 0; i < sizeMath; i++)
		{
			cout << math[i] << " ";
		}
		cout << endl << "Russ: ";
		for (int i = 0; i < sizeRuss; i++)
		{
			cout << russ[i] << " ";
		}
		cout << endl << "Phys: ";
		for (int i = 0; i < sizePhys; i++)
		{
			cout << phys[i] << " ";
		}
		cout << endl;
	}
	float avgMath()
	{
		float avg = 0;
		for (int i = 0; i < sizeMath; i++)
		{
			avg += math[i];
		}
		return avg / float(sizeMath);
	}
	float avgRuss()
	{
		float avg = 0;
		for (int i = 0; i < sizeRuss; i++)
		{
			avg += russ[i];
		}
		return avg / float(sizeRuss);
	}
	float avgPhys()
	{
		float avg = 0;
		for (int i = 0; i < sizePhys; i++)
		{
			avg += phys[i];
		}
		return avg / float(sizePhys);
	}

	void operator = (const Student& st2)
	{
		this->firstName = st2.firstName;
		this->lastName = st2.lastName;
		this->otchestvo = st2.otchestvo;
		this->sizeMath = st2.sizeMath;
		this->sizeRuss = st2.sizeRuss;
		this->sizePhys = st2.sizePhys;
		math = new int[sizeMath];
		for (int i = 0; i < sizeMath; i++)
		{
			math[i] = st2.math[i];
		}
		russ = new int[sizeRuss];
		for (int i = 0; i < sizeRuss; i++)
		{
			russ[i] = st2.russ[i];
		}
		phys = new int[sizePhys];
		for (int i = 0; i < sizePhys; i++)
		{
			phys[i] = st2.phys[i];
		}
	}
};

