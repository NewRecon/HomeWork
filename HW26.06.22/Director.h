#pragma once
class Director
{
public:
	void create(Builder* builder, std::string name, std::string phone, std::string office)
	{
		builder->setName(name);
		builder->setPhone(phone);
		builder->setOffice(office);
	}
};

	

