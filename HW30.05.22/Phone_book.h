#pragma once
class Phone_book
{
private:
	Abonent* book = new Abonent[0];
	int size = 0;
public:
	Phone_book()
	{

	}
	Phone_book(Abonent& ab)
	{
		addAb(ab);
	}
	~Phone_book()
	{
		delete[]book;
	}
	void addAb(Abonent& ab)
	{
		Abonent* buf = new Abonent[size + 1];
		for (int i = 0; i < size; i++)
		{
			buf[i] = book[i];
		}
		buf[size] = ab;
		delete[]book;
		book = buf;
		size++;
	}
	void delAb(int index)
	{
		if (index > size) index = size - 1;
		Abonent* buf = new Abonent[size - 1];
		for (int i = 0; i < index; i++)
		{
			buf[i] = book[i];
		}
		for (int i = index+1; i < size; i++)
		{
			buf[i-1] = book[i];
		}
		delete[]book;
		book = buf;
		size--;
	}
	int search_firstName(string firstName2)
	{
		for (int i = 0; i < size; i++)
		{
			if (book[i].getFirstName() == firstName2)
			{
				return i;
			}
		}
		return -1;
	}
	int search_lastName(string lastName2)
	{
		for (int i = 0; i < size; i++)
		{
			if (book[i].getLasttName() == lastName2)
			{
				return i;
			}
		}
		return -1;
	}
	int search_othestvo(string othestvo2)
	{
		for (int i = 0; i < size; i++)
		{
			if (book[i].getOthestvo() == othestvo2)
			{
				return i;
			}
		}
		return -1;
	}
	inline void print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << i + 1 << ". ";
			book[i].print();
		}
	}
	void addInfo(int index, string info)
	{
		if (index < 0 || index>size) return;
		book[index].setInfo(info);
	}
	void saveInFile(string path)
	{
		for (int i = 0; i < size; i++)
		{
			book[i].saveInFile(path);
		}
	}
	void readFile(string path)
	{
		string str;
		ifstream in{ path };
		if (in.is_open())
		{
			while (getline(in, str))
			{
				cout << str << endl;
			}
		}
		else cout << "Error";
		in.close();
	}
};

