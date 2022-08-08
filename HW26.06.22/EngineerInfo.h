#pragma once
class EngineerInfo
{
private:
	std::string info;
public:
	void setInfo(std::string info)
	{
		this->info = info;
	}
	void print()
	{
		std::cout << info << std::endl;
	}
};

