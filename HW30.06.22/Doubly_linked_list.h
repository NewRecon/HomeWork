#pragma once
template <typename T>
struct Node
{
	T data;
	Node* next = nullptr;
	Node* prev = nullptr;
};

template <typename T>
class Doubly_linked_list
{
private:
	Node<T>* root = nullptr;
	Node<T>* tail = nullptr;
	int counter = 0;
public:
	Doubly_linked_list() {}
	Doubly_linked_list(T& object)
	{
		Node<T>* node = new Node<T>{ object };
		root = node;
		tail = node;
		counter++;
	}

	void show()
	{
		if (counter != 0)
		{
			Node<T>* buf = root;
			while (buf->next != nullptr)
			{
				cout << buf->data << " ";
				buf = buf->next;
			}
			cout << buf->data << endl;
		}
		else cout << "list is empty" << endl;
	}

	void addToHead(T& object)
	{
		if (counter == 0)
		{
			Node<T>* node = new Node<T>{ object, root };
			tail = node;
			root = node;
			counter++;
		}
		else
		{
			Node<T>* node = new Node<T>{ object, root };
			root->prev = node;
			root = node;
			counter++;
		}
	}

	void addToTail(T& object)
	{
		if (counter == 0)
		{
			Node<T>* node = new Node<T>{ object, nullptr, tail };
			root = node;
			tail = node;
			counter++;
		}
		else
		{
			Node<T>* node = new Node<T>{ object, nullptr, tail };
			tail->next = node;
			tail = node;
			counter++;
		}
	}

	void deleteFromHead()
	{
		if (counter == 1)
		{
		deleteAll();
		}
		else if (counter != 0)
		{
			Node<T>* buf = root->next;
			delete root;
			root = buf;
			root->prev = nullptr;
			counter--;
		}
	}

	void deleteFromTail()
	{
		if (counter == 1)
		{
			deleteAll();
		}
		else if (counter != 0)
		{
			Node<T>* buf = tail->prev;
			delete tail;
			tail = buf;
			tail->next = nullptr;
			counter--;
		}
	}

	void deleteAll()
	{
		if (counter != 0)
		{
			Node<T>* buf = root;
			while (buf->next != nullptr)
			{
				buf = buf->next;
				delete root;
				root = buf;
				counter--;
			}
			delete root;
			root = nullptr;
			counter--;
		}
	}

	T showFront()
	{
		return root->data;
	}

	T showBack()
	{
		return tail->data;
	}

	Doubly_linked_list& copy (const Doubly_linked_list& other) // задание 2
	{
		Doubly_linked_list list;
		Node<T>* buf = other.root;
		for (int i = 0; i < other.counter; i++)
		{
			list.addToTail(buf->data);
			buf = buf->next;
		}
		list.counter = other.counter;
		return list;
	}

	Doubly_linked_list& operator + (const Doubly_linked_list& other) // задание 2
	{
		Doubly_linked_list list;
		Node<T>* buf = root;
		for (int i = 0; i < counter; i++)
		{
			list.addToTail(buf->data);
			buf = buf->next;
		}
		buf = other.root;
		for (int i = 0; i < other.counter; i++)
		{
			list.addToTail(buf->data);
			buf = buf->next;
		}
		list.counter = this->counter + other.counter;
		return list;
	}

	Doubly_linked_list& operator * (const Doubly_linked_list& other) // задание 2
	{
		Doubly_linked_list list;
		Node<T>* buf = root;
		Node<T>* buf2 = other.root;
		int size = max(this->counter, other.counter);
		int newCount = 0;
		for (int j = 0; j < this->counter; j++)
		{
			for (int i = 0; i < other.counter; i++)
			{
				if (buf->data == buf2->data)
				{
					list.addToTail(buf->data);
					newCount++;
					break;
				}
				buf2 = buf2->next;
			}
			buf2 = other.root;
			buf = buf->next;
		}
		list.counter = newCount;
		return list;
	}
};
