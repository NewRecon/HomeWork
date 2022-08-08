#pragma once
class Engineer
{
private:
	std::string name;
	std::string phone;
	std::string office;
public:
	void setName(std::string name)
	{
		this->name = name;
	}
	void setPhone(std::string phone)
	{
		this->phone = phone;
	}
	void setOffice(std::string office)
	{
		this->office = office;
	}
	void print()
	{
		std::cout << name << " " << phone << " " << office << std::endl;
	}
};

