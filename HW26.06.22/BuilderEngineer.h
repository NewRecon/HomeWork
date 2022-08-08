#pragma once
class BuilderEngineer : public Builder
{
private:
	Engineer* eng = new Engineer;

public:
	BuilderEngineer() {}
	~BuilderEngineer()
	{
		delete eng;
	}
	void setName(std::string name) override
	{
		this->eng->setName(name);
	}
	void setPhone(std::string phone) override
	{
		this->eng->setPhone(phone);
	}
	void setOffice(std::string office) override
	{
		this->eng->setOffice(office);
	}
	Engineer* get()
	{
		Engineer* buf = this->eng;

		this->eng = new Engineer;

		return buf;
	}
};

