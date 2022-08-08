#pragma once

template <typename T>
struct Node
{
	T* data = nullptr;
	Node* next = nullptr;
};

template <typename T>
class LinkedList
{
private:
	Node<T>* root = nullptr;
	int counter = 0;
public:
	LinkedList() {}
	LinkedList(T& object)
	{
		Node<T>* node = new Node<T>{ object };
		root = node;
		counter++;
	}

	void show()
	{
		if (counter != 0)
		{
			Node<T>* buf = root;
			while (buf->next != nullptr)
			{
				cout << buf->data;
				buf = buf->next;
			}
			cout << buf->data;
		}
		else cout << "list is empty" << endl;
	}

	void addToHead(T* object)
	{
		Node<T>* node = new Node<T>{ object, root };
		root = node;
		counter++;
	}

	void addToTail(T& object)
	{
		Node<T>* node = new Node<T>{ object };
		Node<T>* buf = root;
		while (buf->next != nullptr)
		{
			buf = buf->next;
		}
		buf->next = node;
		counter++;
	}

	void deleteFromHead()
	{
		if (counter != 0)
		{
			Node<T>* buf = root->next;
			delete root;
			root = buf;
			counter--;
		}
	}

	void deleteFromTail()
	{
		if (counter > 1)
		{
			Node<T>* buf = root->next;
			Node<T>* buf2 = root;
			while (buf->next != nullptr)
			{
				buf2 = buf;
				buf = buf->next;
			}
			delete buf;
			buf2->next = nullptr;
			counter--;
		}
		else if (counter == 1)
		{
			deleteFromHead();
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

	void addToPosition(T& object, int pos)
	{
		counter++;
		if (pos > counter) pos = counter;
		Node<T>* buf = root;
		for (int i = 1; i < pos - 1; i++)
		{
			buf = buf->next;
		}
		Node<T>* node;
		if (pos < 2)
		{
			node = new Node<T>{ object,  root };
			root = node;
		}
		else
		{
			node = new Node<T>{ object,  buf->next };
			buf->next = node;
		}
	}

	void deleteFromPosition(int pos)
	{
		if (pos <= 1)
		{
			deleteFromHead();
		}
		else if (pos >= counter)
		{
			deleteFromTail();
		}
		else
		{
			Node<T>* buf = root->next;
			Node<T>* buf2 = root;
			for (int i = 1; i < pos - 1; i++)
			{
				buf2 = buf;
				buf = buf->next;
			}
			buf2->next = buf->next;
			delete buf;
		}
	}

	int searchId(T& object)
	{
		Node<T>* buf = root;
		for (int i = 1; i <= counter; i++)
		{
			if (buf->data.id == object.id) return i;
			buf = buf->next;
		}
		return NULL;
	}

	T* searchData(int id)
	{
		Node<T>* buf = root;
		for (int i = 0; i < counter; i++)
		{
			if (buf->data->id == id) return buf->data;
			buf = buf->next;
		}
		return nullptr;
	}

	int searchAndSwap(T& object, int other)
	{
		Node<T>* buf = root;
		int count = 0;
		for (int i = 1; i <= counter; i++)
		{
			if (buf->data.getId() == object.getId())
			{
				buf->data.setId(other);
				count++;
			}
			buf = buf->next;
		}
		if (count == 0) return -1;
		return count;
	}

	void reverse()
	{
		Node<T>* buf = root;
		Node<T>* buf2 = nullptr;
		Node<T>* buf3 = nullptr;
		while (buf->next != nullptr)
		{
			buf = buf->next;
		}
		buf3 = buf;
		for (int i = 1; i < counter; i++)
		{
			buf = root->next;
			buf2 = root;
			while (buf->next != nullptr)
			{
				buf2 = buf;
				buf = buf->next;
			}
			buf->next = buf2;
			buf2->next = nullptr;
		}
		root = buf3;
	}

	T* gethead()
	{
		return root->data;
	}
};

