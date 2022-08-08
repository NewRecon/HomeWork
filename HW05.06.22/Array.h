#pragma once
template <typename T>
class Array
{
private:
	T* ar;
	int size = 0;
public:
	Array()
	{

	}
	Array(T* ar, int size)
	{
		this->ar = ar;
		this->size = size;
	}
	~Array()
	{
		cout << "del";
		delete[]ar;
	}
	Array(const Array& ar2)	//Конструктор копирования с переписыванием значений динамической памяти
	{
		this->size = ar2.size;
		ar = new T[size];
		for (int i = 0; i < size; i++)
		{
			ar[i] = ar2.ar[i];
		}
	}
	void addend(T n)
	{
		T* buf = new T[size + 1];
		for (int i = 0; i < size; i++)
		{
			buf[i] = ar[i];
		}
		buf[size] = n;
		delete[]ar;
		ar = buf;
		size++;
	}
	void addend(T* ar)
	{
		int size2 = _msize(ar) / sizeof(ar[0]);
		T* buf = new T[size + size2];
		for (int i = 0; i < size; i++)
		{
			buf[i] = ar[i];
		}
		for (int i = size, k = 0; k < size2; i++)
		{
			buf[i] = ar.ar[k++];
		}
		delete[]ar;
		ar = buf;
		size += size2;
	}
	void addend(Array ar)
	{
		T* buf = new T[size + ar.size];
		for (int i = 0; i < size; i++)
		{
			buf[i] = ar[i];
		}
		for (int i = size, k=0; k < ar.size; i++)
		{
			buf[i] = ar.ar[k++];
		}
		delete[]ar;
		ar = buf;
		size += ar.size;
	}
	inline void show()
	{
		for (int i = 0; i < size; i++)
		{
			cout << ar[i] << " ";
		}
		cout << endl;
	}
};

