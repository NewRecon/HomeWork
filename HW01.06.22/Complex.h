#pragma once
template <typename T>
class Complex
{
private:
	T a;
	T b;
public:
	Complex()
	{

	}
	Complex(T a, T b)
	{
		this->a = a;
		this->b = b;
	}
	void print()
	{
		if (b < 0)
		{
			cout << "z = " << a << b << "i" << endl;
		}
		else cout << "z = " << a << "+" << b << "i" << endl;
	}

	Complex operator + (const Complex& other)
	{
		Complex buf(a+other.a, b+other.b);
		return buf;
	}
	Complex operator - (const Complex& other)
	{
		Complex buf(a - other.a, b - other.b);
		return buf;
	}
	Complex operator * (const Complex& other)
	{
		Complex buf(a*other.a - b*other.b, a*other.b+other.a*b);
		return buf;
	}
	Complex operator / (const Complex& other)
	{
		float bufA = (a * other.a + b * other.b) / ((other.a * other.a) + (other.b * other.b));
		float bufB = (b * other.a - a * other.b) / ((other.a * other.a) + (other.b * other.b));
		Complex buf(bufA, bufB);
		return buf;
	}
};

