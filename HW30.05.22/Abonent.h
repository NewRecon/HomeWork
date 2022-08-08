#pragma once
class Abonent
{
private:
	string firstName;
	string lastName;
	string otchestvo;
	string info;
	int homePhone;
	int workPhone;
	long long mobilePhome;
public:
	Abonent()
	{

	}
	Abonent(string firstName, string lastName, string otchestvo, int homePhone, int workPhone, long long mobilePhome)
	{
		this->firstName = firstName;
		this->lastName = lastName;
		this->otchestvo = otchestvo;
		this->homePhone = homePhone;
		this->workPhone = workPhone;
		this->mobilePhome = mobilePhome;
	}
	Abonent(string firstName, string lastName, string otchestvo, int homePhone, int workPhone, long long mobilePhome, string info) : Abonent(firstName, lastName, otchestvo, homePhone, workPhone, mobilePhome)
	{
		this->info = info;
	}
	string getFirstName()
	{
		return firstName;
	}
	string getLasttName()
	{
		return lastName;
	}
	string getOthestvo()
	{
		return otchestvo;
	}
	void setInfo(string info)
	{
		this->info = info;
	}
	inline void print()
	{
		cout << firstName << " " << lastName << " " << otchestvo << " \t home phone: " << homePhone << ", work phone: " << workPhone << ", mobile phone: " << mobilePhome << endl;
		cout << "info: " << info << endl << endl;
	}
	void saveInFile(string path)
	{
		ofstream out{ path, ios::app };
		out << firstName << " " << lastName << " " << otchestvo << " \t home phone: " << homePhone << ", work phone: " << workPhone << ", mobile phone: " << mobilePhome << endl;
		out << "info: " << info << endl << endl;
		out.close();

	}
};

