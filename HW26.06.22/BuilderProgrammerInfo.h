#pragma once
class BuilderProgrammerInfo : public Builder
{
private:
	std::string name;
	std::string phone;
	std::string office;
public:
	BuilderProgrammerInfo() {}
	void setName(std::string name) override
	{
		this->name = name;
	}
	void setPhone(std::string phone) override
	{
		this->phone = phone;
	}
	void setOffice(std::string office) override
	{
		this->office = office;
	}
	ProgrammerInfo* get()
	{
		ProgrammerInfo* buf = new ProgrammerInfo;
		buf->setInfo(name + " : " + phone + " : " + office);

		return buf;
	}
};

