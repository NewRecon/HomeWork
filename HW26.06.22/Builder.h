#pragma once

class Builder
{
public:
	virtual void setName(std::string name) = 0;
	virtual void setPhone(std::string phone) = 0;
	virtual void setOffice(std::string phone) = 0;
};

