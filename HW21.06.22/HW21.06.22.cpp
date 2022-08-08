#include <iostream>
#include "Stack.cpp"

void check(std::string str)
{
	Stack<char> bracket(20);
	bool flag = true;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '(' || str[i] == '{' || str[i] == '[')
		{
			if (str[i] == '(') bracket.push(str[i] + 1);
			else bracket.push(str[i] + 2);
		}
		if (str[i] == ')' || str[i] == '}' || str[i] == ']')
		{
			if (bracket.top() != str[i])
			{
				for (int j = 0; j <= i; j++)
				{
					std::cout << str[j];
				}
				std::cout << " - no opening bracket for '" << str[i] << "'" << std::endl;
				flag = false;
				break;
			}
			bracket.pop();
		}
		if (str[i] == ';' && !bracket.empty())
		{
			for (int j = 0; j < i; j++)
			{
				std::cout << str[j];
			}
			std::cout << " - no closing bracket '" << bracket.top() << "'" << std::endl;
			flag = false;
			break;
		}
	}
	if (flag) std::cout << "Correct";
}

int main()
{
	std::string str = "([x-y-z{}*[x+2y)-{z+4x)];";
	check(str);
}