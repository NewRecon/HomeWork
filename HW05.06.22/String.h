#pragma once
class String
{
private:
	char* str;
	int size = 0;
public:
	String()
	{

	}
	String(char* str, int size)
	{
		this->str = str;
		this->size = size;
	}
	String(const char str2[])
	{
		for (int i = 0; str2[i] != '\0'; i++)
		{
			size++;
		}
		str = new char[size + 1];
		for (int i = 0; str2[i] != '\0'; i++)
		{
			str[i] = str2[i];
		}
		str[size] = '\0';
	}
	~String()
	{
		cout << "del" << " ";
		delete[]str;
	}
	String(const String& str2)
	{
		this->size = str2.size;
		str = new char[size+1];
		for (int i = 0; i < size+1; i++)
		{
			str[i] = str2.str[i];
		}
	}
	void delLastEl()
	{
		char* buf = new char[size];
		for (int i = 0; i < size-1; i++)
		{
			buf[i] = str[i];
		}
		buf[size-1] = '\0';
		delete[]str;
		str = buf;
		size--;
	}
	void show()
	{
		for (int i = 0; i < size; i++)
		{
			cout << str[i];
		}
		cout << endl;
	}
};

