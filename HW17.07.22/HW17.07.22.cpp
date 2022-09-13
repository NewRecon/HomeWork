#include <iostream>
#include <list>

class Employee;

class Department
{
	std::string department;
	int payment;
public:
	Department(std::string department, int payment)
	{
		this->payment = payment;
		this->department = department;
	}
	void infoDepartment(std::string name, std::string phone)
	{
		std::cout << name << " : " << phone << " : " << department << " : " << payment << std::endl;
	}
	int getPayment()
	{
		return payment;
	}
	std::string getDepartment()
	{
		return department;
	}
};

class departamentFactory
{
	std::list<Department> cache;

	friend Employee;
public:
	Department& getFactory(std::string department, int payment)
	{
		if (cache.empty())
		{
			Department d(department, payment);
			cache.push_back(d);
			return cache.front();
		}
		else
		{
			std::list<Department>::iterator iter = cache.begin();

			for (int i = 0; i < cache.size(); i++)
			{
				if (iter->getPayment() == payment &&
					iter->getDepartment() == department)
					return *iter;
				else iter++;
			}

			Department d(department, payment);
			cache.push_back(d);
			return cache.back();
		}
	}
};

class Employee
{
	std::string name;
	std::string phone;
	Department* departament = nullptr;
public:

	Employee(std::string name, std::string phone, std::string department, int payment, departamentFactory& factory)
	{
		this->name = name;
		this->phone = phone;

		this->departament = &(factory.getFactory(department, payment));
	}
	void infoEmployee()
	{
		departament->infoDepartment(name, phone);
	}

};

class Office
{
	std::list<Employee> workers;
public:
	void add(Employee& emp)
	{
		workers.push_back(emp);
	}
	void showInfo()
	{
		std::list<Employee>::iterator iter = workers.begin();
		for (int i = 0; i < workers.size(); i++)
		{
			iter->infoEmployee();
			iter++;
		}
	}
};


int main()
{
	departamentFactory factory;

	Employee eng1("Denis", "345365343", "eng", 2000, factory);
	Employee eng2("Vika", "34123123", "eng", 2000, factory);
	Employee prog1("Max", "12344557", "prog", 2500, factory);
	Employee prog2("Masha", "3213123", "prog", 2500, factory);

	Office office;
	office.add(eng1);
	office.add(eng2);
	office.add(prog1);
	office.add(prog2);

	office.showInfo();
}