#include <iostream>
#include <vector>

template <typename T>
struct Node
{
	T data;
	Node* parent = nullptr;
	Node* left = nullptr;
	Node* right = nullptr;
	int min;
	int max;
};

template <typename T>
class Tree
{
private:
	Node<T>* root = nullptr;
	void create(std::vector<Node<T>*> vector)
	{
		std::vector<Node<T>*> newVector;
		Node<T>* buf;
		for (int i = 0, n=0; i < vector.size(); i+=2)
		{
			buf = new Node<T>;
			buf->data = vector[i]->data + vector[i + 1]->data;
			buf->left = vector[i];
			buf->right = vector[i + 1];
			buf->min = vector[i]->min;
			buf->max = vector[i + 1]->max;
			vector[i]->parent = buf;
			vector[i + 1]->parent = buf;
			newVector.push_back(buf);
			std::cout << newVector[n++]->data << " ";
		}
		std::cout << std::endl;
		if (newVector.size() != 1)
		{
			create(newVector);
		}
		else
		{
			root = newVector[0];
			std::cout << std::endl << "min - " << root->min << " max - " << root->max;
		}
	}
public:
	Tree(T* array)
	{
		int size = _msize(array) / sizeof(array[0]);
		std::vector<Node<T>*> vector;
		Node<T>* buf;
		for (int i = 0, n=0; i < size; i++)
		{
			buf = new Node<T>;
			buf->data = array[i];
			buf->min = i;
			buf->max = i;
			vector.push_back(buf);
			std::cout << vector[n++]->data << " ";
		}
		int i = 0;
		while (pow(2, i) < vector.size())
		{
			i++;
		}
		if (vector.size() < pow(2, i))
		{
			Node<T>* node;
			int d = pow(2, i) - vector.size();
			for (int j = 0; j < d; j++)
			{
				node = new Node<T>{ 0 };
				node->max = vector.size();
				node->min = vector.size();
				vector.push_back(node);
				std::cout << vector[vector.size() - 1]->data << " ";
			}
		}
		std::cout << std::endl;
		create(vector);
	}

	// замена элемента
	void set(int index, T& value)
	{
		Node<T>* buf = root;
		while (buf->min != index || buf->max != index) // пока отрезок ноды не сравняется с индексом
		{
			if (index >= buf->left->min && index <= buf->left->max) // если индекс находится в левой ветке (min ноды меньше индекса max ноды больше индекса)
			{
				buf = buf->left;
			}
			else buf = buf->right;
		}
		
		buf->data = value; // замена элемента

		while (buf->parent != nullptr) // пока не закончатся родители: переходим к родителю и приравниваем данные к сумме данных ветвей
		{
			buf = buf->parent;
			buf->data = buf->left->data + buf->right->data;
		}
	}

	// нахождение суммы на отрезке
	// время исполнения вышло O(log n) даже с учётом использования списка
	T& sum(int left, int right, Node<T>* buf = nullptr)
	{
		T result = 0;
		if (buf == nullptr) buf = root;
		int midle = (buf->max - buf->min) / 2 + buf->min; // находим середину отрезка у ноды
		if ((left <= buf->min && right >= buf->max) || (buf->left == nullptr && buf->right == nullptr)) // если нода полностью входит в искомый промежуток или если нода является листом дерева, то добавляем в сумму
		{
			result += buf->data;
		}
		else if (left <= midle && right > midle ) // если искомый промежуток лежит и в левой и в правой части ноды
		{
			result += sum(left, right, buf->left);
			result += sum(left, right, buf->right);
		}
		else if (left >= midle) // если отрезок в правой части ноды
		{
			result += sum(left, right, buf->right);
		}
		else if (right <= midle) // если в левой
		{
			result += sum(left, right, buf->left);
		}
		return result;
	}
}; 

int main()
{
	//int* ar = new int[8]{ 3,1,2,5,6,8,3,2 };
	int* ar = new int[13]{0,1,2,3,4,5,6,7,8,9,10,11,12};
	Tree<int> tree(ar);
	int value = 8;
	//tree.set(5, value);
	std::cout << std::endl;
	std::cout << tree.sum(6, 7);
}