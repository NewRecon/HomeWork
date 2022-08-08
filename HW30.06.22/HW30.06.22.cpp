#include <iostream>
#include "Doubly_linked_list.cpp"

#define task 3

#if task == 1

template <typename T>
class Queue
{
private:
	Doubly_linked_list<T> list;
	int counter = 0;
public:
	Queue(){}
	Queue(T& object)
	{
		list.addToHead(object);
		counter++;
	}
	int size()
	{
		return this->list.counter;
	}
	bool empty()
	{
		if (counter == 0) return true;
		else return false;
	}
	T front()
	{
		if (counter != 0) return list.showFront();
		else throw "Empty queue.";
	}
	T back()
	{
		if (counter != 0) return list.showBack();
		else throw "Empty queue.";
	}
	void pop()
	{
		if (counter != 0)
		{
			list.deleteFromHead();
			counter--;
		}
		else std::cout << "Error pop(). Empty queue.";
	}
	void push(T& object)
	{
		list.addToTail(object);
		counter++;
	}
};

int main()
{
	int a = 10, b = 5, c = 2;
	Queue<int> q;
	q.push(b);
	q.push(c);
	std::cout << q.back() << std::endl;
	std::cout << q.front() << std::endl;
	q.pop();
	std::cout << q.back() << std::endl;
	std::cout << q.front() << std::endl;
	q.pop();
	std::cout << q.empty() << std::endl;
	q.pop();
}

#elif task == 2

int main()
{
	int a = 10, b = 5, c = 2;
	int d=10, e=5, f=10;
	Doubly_linked_list<int> list1;
	list1.addToHead(a);
	list1.addToHead(b);
	list1.addToHead(c);
	list1.show();
	Doubly_linked_list<int> list2;
	list2.addToHead(d);
	list2.addToHead(e);
	list2.addToHead(f);
	list2.show();
	Doubly_linked_list<int> list3 = list1 * list2;
	list3.show();
}

#elif task == 3

class Human
{
private:
	std::string name;
	int age;
public:
	Human(std::string name, int age)
	{
		this->name = name;
		this->age = age;
	}
};

template <typename T>
class Array
{
private:
	Doubly_linked_list<T> list;
	int size;
public:
	Array(int size)
	{
		this->size = size;
		for (int i = 0; i < size; i++)
		{
			list.addToTail();
		}
	}
	int getSize()
	{
		return this->size;
	}
	void setSize(int size, int grow = 1)
	{
		if (this->size > size)
		{
			for (int i = this->size; i > size; i--)
			{
				list.deleteFromTail();
			}
		}
		else if (this->size < size)
		{
			for (int i = this->size; i < size; i++)
			{
				list.addToTail();
			}
		}
		this->size = size;
	}
};

int main()
{
	Human h1("Loli", 32);
	Array<Human> ar(2);
}

#endif