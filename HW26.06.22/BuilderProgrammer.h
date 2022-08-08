#pragma once

class BuilderProgrammer : public Builder
{
private:
	Programmer* prog = new Programmer;

public:
	BuilderProgrammer(){}
	~BuilderProgrammer()
	{
		delete prog;
	}
	void setName(std::string name) override
	{
		this->prog->setName(name);
	}
	void setPhone(std::string phone) override
	{
		this->prog->setPhone(phone);
	}
	void setOffice(std::string office) override
	{
		this->prog->setOffice(office);
	}
	Programmer* get()
	{
		Programmer* buf = this->prog;

		this->prog = new Programmer;

		return buf;
	}
};

