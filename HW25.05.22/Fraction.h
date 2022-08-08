#pragma once
class Fraction
{
private:
	int num;
	int den;
	void reduce(int& num, int& den)
	{
		if (num > den)
		{
			for (int i = den; i > 0; i--)
			{
				if (num % i == 0 && den % i == 0)
				{
					num /= i;
					den /= i;
					break;
				}
			}
		}
		else
		{
			for (int i = num; i > 0; i--)
			{
				if (num % i == 0 && den % i == 0)
				{
					num /= i;
					den /= i;
					break;
				}
			}
		}
	}
	void findeInteger(int num, int den)
	{
		if (den == 1)
		{
			cout << num / den << endl;
		}
		else if (num > den)
		{
			cout << num / den << " * " << num % den << "/" << den << endl;
		}
		else
		{
			cout << num << "/" << den << endl;
		}
	}
public:
	Fraction()
	{
		int num, den;
		cout << "input num: ";
		cin >> num;
		this->num = num;
		cout << "input den: ";
		cin >> den;
		this->den = den;
	}
	Fraction(int num, int den)
	{
		this->num = num;
		this->den = den;
	}
	void sum(Fraction f2)
	{
		int numR = num * f2.den + f2.num * den;
		int denR = den * f2.den;
		reduce(numR, denR);
		findeInteger(numR, denR);
	}
	void razn(Fraction f2)
	{
		int numR = num * f2.den - f2.num * den;
		int denR = den * f2.den;
		reduce(numR, denR);
		findeInteger(numR, denR);
	}
	void mult(Fraction f2)
	{
		int numR = num * f2.num;
		int denR = den * f2.den;
		reduce(numR, denR);
		findeInteger(numR, denR);
	}
	void del(Fraction f2)
	{
		int numR = num * f2.den;
		int denR = den * f2.num;
		reduce(numR, denR);
		findeInteger(numR, denR);
	}
};

