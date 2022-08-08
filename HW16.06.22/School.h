#pragma once
class School
{
private:
	School_class* school = nullptr;
	int size = 0;
public:
	School(){}
	void add_clas(School_class& clas)
	{
		School_class* buf = new School_class[size + 1];
		for (int i = 0; i < size; i++)
		{
			buf[i] = school[i];
		}
		buf[size] = clas;
		delete[]school;
		school = buf;
		size++;
	}
	void show_school()
	{
		for (int i = 0; i < size; i++)
		{
			cout << "\tCLASS - " << school[i].getNum() << endl;
			school[i].print();
			cout << endl << "-------------------------------------------" << endl;
		}
	}
};

