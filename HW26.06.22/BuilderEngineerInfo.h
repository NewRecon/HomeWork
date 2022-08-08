#pragma once
class BuilderEngineerInfo : public Builder
{
private:
	std::string name;
	std::string phone;
	std::string office;
public:
	BuilderEngineerInfo() {}
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
	EngineerInfo* get()
	{
		EngineerInfo* buf = new EngineerInfo;
		buf->setInfo(name + " : " + phone + " : " + office);

		return buf;
	}
};

