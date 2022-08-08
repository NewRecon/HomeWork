#pragma once

struct CashElement
{
	int id;
	std::string data;
	std::string date;
};

class Proxy
{
private:
	std::string path;
	LinkedList<CashElement> cash;

	int stringToInt(std::string str)
	{
		int n = 0;
		for (int i = 0; str[i] != '\0'; i++)
		{
			n = n*10 + (str[i] - 48);
		}
		return n;
	}

	std::string intToString(int n)
	{
		std::string str = "";
		int k = 0;
		int buf = n;
		while (buf > 0)
		{
			k++;
			buf /= 10;
		}
		for (int i = k - 1, l; n > 0; i--)
		{
			l = n / pow(10, i);
			n = n - l * pow(10, i);
			str += l + 48;
		}
		return str;
	}

	CashElement* searchInFile(int id)
	{
		ifstream in{ path };
		if (in.is_open())
		{
			CashElement* buf = new CashElement;
			std::string str;
			std::string bufStr;
			std::string bufStr2 = "";
			int n = 0;
			while (getline(in, str))
			{
				bufStr = "";
				for (int i = 0; str[i] != ' ' && str[i] != '\0'; i++)
				{
					bufStr += str[i];
				}
				n = stringToInt(bufStr);
				if (n == id)
				{
					for (int i = bufStr.size()+1; i < str.size(); i++)
					{
						bufStr2 += str[i];
					}
					buf->id = id;
					buf->data = bufStr2;
					break;
				}
			}
			in.close();
			return buf;
		}
		else
		{
			in.close();
			throw "file not found";
		}
	}
public:
	Proxy(std::string path)
	{
		this->path = path;
	}
	std::string getData(int id)
	{
		std::string str = "data not found";
		CashElement* element = cash.searchData(id);
		if (element != nullptr)
		{
			std::string str = cash.searchData(id)->data;
		}
		else
		{
			cash.addToHead(searchInFile(id));
			str = cash.gethead()->data;
		}
		return str;
	}
};

