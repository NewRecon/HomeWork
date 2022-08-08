#pragma once
class Fraction
{
private:
	int num;
	int den;
	//целая часть
	int integer = 0;
	//знак дроби (true + или false -)
	bool sign = true;
	//сокращение
	void reduce()
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
	//нахождение целой части
	void findeInteger()
	{
		if (den == 1 || num== den)
		{
			integer += num / den;
			num = 0;
			den = 0;
		}
		else if (num > den)
		{
			integer += num / den;
			num = num % den;
		}
	}
	//перевод дроби в неправильную
	int convers_to_improper()
	{
		if (!sign) return -(integer * den + num);
		else return integer * den + num;
	}
	//создать буферную дробь с учётом знака для дальнейших вычислений
	Fraction create_Buf()
	{
		Fraction buf(num, den);
		if (integer != 0)
		{
			buf.num = convers_to_improper();
		}
		else if (!sign)
		{
			if (!sign) buf.num = -num;
		}
		return buf;
	}
public:
	Fraction()
	{

	}
	Fraction(int num, int den)
	{
		this->num = num;
		this->den = den;
	}
	Fraction(int integer, int num, int den) : Fraction(num, den)
	{
		this->integer = integer;
	}
	Fraction(int integer, int num, int den, bool sign) : Fraction(integer, num, den)
	{
		this->sign = sign;
	}
	Fraction(int num, int den, bool sign) : Fraction(num, den)
	{
		this->sign = sign;
	}
	Fraction sum(Fraction f2)
	{
		Fraction buf1 = create_Buf();
		Fraction buf2 = f2.create_Buf();
		Fraction buf;
		int numR = buf1.num * buf2.den + buf2.num * buf1.den;
		if (numR < 0)
		{
			buf.num = -(numR);
			buf.sign = false;
		}
		else buf.num = numR;
		int denR = buf1.den * buf2.den;
		buf.den = denR;
		buf.reduce();
		buf.findeInteger();
		return buf;
	}
	Fraction dif(Fraction f2)
	{
		Fraction buf1 = create_Buf();
		Fraction buf2 = f2.create_Buf();
		Fraction buf;
		int numR = buf1.num * buf2.den - buf2.num * buf1.den;
		if (numR < 0)
		{
			buf.num = -(numR);
			buf.sign = false;
		}
		else buf.num = numR;
		int denR = buf1.den * buf2.den;
		buf.den = denR;
		buf.reduce();
		buf.findeInteger();
		return buf;
	}
	Fraction mult(Fraction f2)
	{
		Fraction buf1 = create_Buf();
		Fraction buf2 = f2.create_Buf();
		Fraction buf;
		int numR = buf1.num * buf2.num;
		if (numR < 0)
		{
			buf.num = -(numR);
			buf.sign = false;
		}
		else buf.num = numR;
		int denR = buf1.den * buf2.den;
		buf.den = denR;
		buf.reduce();
		buf.findeInteger();
		return buf;
	}
	Fraction del(Fraction f2)
	{
		Fraction buf1 = create_Buf();
		Fraction buf2 = f2.create_Buf();
		Fraction buf;
		int numR = buf1.num * buf2.den;
		if (numR < 0)
		{
			buf.num = -(numR);
			buf.sign = false;
		}
		else buf.num = numR;
		int denR = buf1.den * buf2.num;
		buf.den = denR;
		buf.reduce();
		buf.findeInteger();
		return buf;
	}
	void print()
	{
		if (sign)
		{
			if (integer != 0)
			{
				if (num == 0) cout << integer << endl;
				else cout << integer << " " << num << "/" << den << endl;
			}
			else cout << num << "/" << den << endl;
		}
		else
		{
			if (integer != 0)
			{
				if (num == 0) cout <<"-" << integer << endl;
				else cout << "-" << integer << " " << num << "/" << den << endl;
			}
			else cout << "-" << num << "/" << den << endl;
		}
	}

	Fraction operator + (const Fraction& f2)
	{
		return sum(f2);
	}
	Fraction operator - (const Fraction& f2)
	{
		return dif(f2);
	}
	Fraction operator * (const Fraction& f2)
	{
		return mult(f2);
	}
	Fraction operator / (const Fraction& f2)
	{
		return del(f2);
	}
};

