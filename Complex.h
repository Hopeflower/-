#include<iostream>
using namespace std;

class Complex
{
	double real;
	double image;
public:
	Complex(double r = 0, double i = 0) :real(r), image(i) {}

	//复数类的数据初始化
	double Real() { return real; }

	double Image() { return image; }

	//各种运算函数。

	Complex operator+(Complex &);

	Complex operator+(double);

	Complex operator-(Complex &);

	Complex operator-(double);

	Complex operator*(Complex &);

	Complex operator/(Complex &);

	double  modpower();

	Complex operator=(Complex);

	friend ostream& operator<<(ostream&ostr, const Complex&C)
	{
		if (C.image != 0)
		{
			if (C.image> 0)
			{
				if (C.real == 0)
				{
					cout << C.image << "i" << endl;
				}
				else
				{
					ostr << C.real << "+" << C.image << "i" << endl;
				}
			}
			else
			{
				if (C.real == 0)
				{
					cout << "("<<C.image << ")"<<"i" << endl;
				}
				else
				{
					ostr << C.real << "+" << "(" << C.image << ")" << "i" << endl;
				}
				
			}
		}
		else
		{
			ostr << C.real << endl;
		}
		return(ostr);
	}

	Complex & operator[](int id) { return (*this); }

	const Complex & operator[](int id)const { return (*this); }
};

Complex Complex::operator+(Complex &c)
{

	Complex temp;

	temp.real = real + c.real;

	temp.image = image + c.image;

	return temp;
}

Complex Complex::operator+(double d)
{

	Complex temp;

	temp.real = real + d;

	temp.image = image;

	return temp;
}

Complex Complex::operator-(Complex &c)
{

	Complex temp;

	temp.real = real - c.real;

	temp.image = image - c.image;

	return temp;
}

Complex Complex::operator-(double d)
{

	Complex temp;

	temp.real = real - d;

	temp.image = image;

	return temp;
}

Complex Complex::operator*(Complex &c)
{

	Complex temp;

	temp.real = real*c.real - image*c.image;


	temp.image = real*c.image + image*c.real;

	return temp;
}

Complex Complex::operator/(Complex &c)
{

	Complex temp;

	if (c.real != 0 || c.image != 0)

	{
    	temp.real = real*(c.real/c.modpower())+image*(c.image/c.modpower());

		temp.image = -real*(c.image / c.modpower()) + image*(c.real / c.modpower());

	}
	else
	{
		temp.real = NULL;
		temp.image = NULL;
		cout << "除数无意义" << endl;
	}

	return temp;
}

double Complex::modpower()
{
	double  temp;	

	temp = real*real + image*image;

	return temp;
}

Complex Complex::operator=(Complex c)
{

	real = c.real;

	image = c.image;

	return *this;
}
