#include<iostream>
#include"Calc.h"
using namespace std;
void menu1()
{
	cout << endl;
	cout << "       ┏〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓┓" << endl;
	cout << "       ┃      ★★★★★★★复数的类以及复数计算器★★★★★★★  ┃" << endl;
	cout << "       ┃                   1.  复数功能                           ┃" << endl;
	cout << "       ┃                   2.  复数计算器                         ┃" << endl;
	cout << "       ┃                   3.  退出程序                           ┃" << endl;
	cout << "       ┗〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓┛" << endl;
	cout << "                       <><注意：用字符用代替复数><>" << endl;
	cout << endl;
}
void menu2()
{
	cout << endl;
	cout << "       ┏〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓┓" << endl;
	cout << "       ┃      ★★★★★★★复数功能★★★★★★★                ┃" << endl;
	cout << "       ┃                   1.  复数相加“+”                      ┃" << endl;
	cout << "       ┃                   2.  复数相加“-”                      ┃" << endl;
	cout << "       ┃                   3.  复数相加“*”                      ┃" << endl;
	cout << "       ┃                   4.  复数相加“/”                      ┃" << endl;
	cout << "       ┃                   5.  复数比较大小                       ┃" << endl;
	cout << "       ┃                   6.  复数模比较大小                     ┃" << endl;
	cout << "       ┃                   7.  退出程序                           ┃" << endl;
	cout << "       ┗〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓┛" << endl;
	cout << endl;
}

void main()
{
	const int MAX_SIZE = 100;
	while (1)
	{
		menu1();
		int num1;
		cin >> num1;
		switch (num1)
		{
		case 1:
		{
			menu2();
			int i = 1;
			while (i)
			{
				cout<< "<><请选择功能(1-“+” 2-“-” 3-“*” 4-“/” 5-“比较大小”6-“比较模的大小”7-“退出”)><>: ";
				int num2;
				cin >> num2;
				switch (num2)
				{
				case 1:
				{
					cout << "★★★★★★★复数相加★★★★★★★" << endl;
					double a, b, c, d;
					cout << "输入加数：" << endl;
					cin >> a >> b;
					Complex c1(a, b);
					cout << "输入被加数：" << endl;
					cin >> c >> d;
					Complex c2(c, d);
					cout << c1 + c2 << endl;
					break;
				}
				case 2:
				{
					cout << "★★★★★★★复数相减★★★★★★★" << endl;
					double a, b, c, d;
					cout << "输入减数：" << endl;
					cin >> a >> b;
					Complex c1(a, b);
					cout << "输入被减数：" << endl;
					cin >> c >> d;
					Complex c2(c, d);
					cout << c1 - c2 << endl;
					break;
				}
				case 3:
				{
					cout << "★★★★★★★复数相乘★★★★★★★" << endl;
					double a, b, c, d;
					cout << "输入乘数：" << endl;
					cin >> a >> b;
					Complex c1(a, b);
					cout << "输入被乘数：" << endl;
					cin >> c >> d;
					Complex c2(c, d);
					cout << c1 * c2 << endl;
					break;
				}
				case 4:
				{
					cout << "★★★★★★★复数相除★★★★★★★" << endl;
					double a, b, c, d;
					cout << "输入除数：" << endl;
					cin >> a >> b;
					Complex c1(a, b);
					cout << "输入被除数：" << endl;
					cin >> c >> d;
					Complex c2(c, d);
					cout << c1 / c2 << endl;
					break;
				}
				case 5:
				{
					cout << "★★★★★★★复数比较★★★★★★★" << endl;
					double a, b, c, d;
					cout << "输入复数c1：" << endl;
					cin >> a >> b;
					Complex c1(a, b);
					cout << "输入复数c2：" << endl;
					cin >> c >> d;
					Complex c2(c, d);
					if (c1.Real() == 0 && c2.Real() == 0|| c1.Image() == 0 && c2.Image() == 0)
					{
						if (c1.Real() > c2.Real()||c1.Image()>c2.Image())
						{
							cout << "c1>c2"<<endl;
						}
						else if (c1.Real() == c2.Real()&&c1.Image()==c2.Image())
						{
							cout << "c1=c2" << endl;
						}
						else
						{
							cout << "c1<c2";
						}
					}
					break;
				}
				case 6:
				{
					cout << "★★★★★★★复数模比较★★★★★★★" << endl;
					double a, b, c, d;
					cout << "输入复数c1：" << endl;
					cin >> a >> b;
					Complex c1(a, b);
					cout << "输入复数c2：" << endl;
					cin >> c >> d;
					Complex c2(c, d);
					if (c1.modpower() > c2.modpower())
					{
						cout << "c1>c2" << endl;
					}
					else if (c1.modpower() == c2.modpower())
					{
						cout << "c1=c2" << endl;
					}
					else
					{
						cout << "c1<c2" << endl;
					}
					break;
				}
				case 7:
				{
					cout << endl;
					cout << "<><复数类操作退出成功！><>" << endl;
					i = 0;
					break;
				}
				default:
					break;
				}
			}
		}
		case 2:
		{
			int x = 0;
			int y = 0;
			double a,b;
			char ch[MAX_SIZE];
			char s[MAX_SIZE];
			Complex *Z;
			Z = new Complex[MAX_SIZE];
			cout << "输入代表复数的字符和复数，输入#结束:注意#输入0 0" << endl;
			while (s[x - 1] != '#')
			{
				cout << "输入代表字符：";
				cin >> s[x];
				cout << "输入复数:";
				cin >> a>>b;
				Complex C(a, b);
				Z[x] = C;
				x++;
			}
			cout << "输入计算式子，输入#结束：注意#前输入 “+”" << endl;
			while (ch[y - 1] != '#')
			{
				cin >> ch[y];
				y++;
			}
			clac exp1(ch, s, Z);
			cout << "结果为："<<exp1.result();
			break;
			
		}
		case 3:
		{
			cout << endl;
			cout << "<><退出成功！><>" << endl;
			exit(0);
		}
		default:
			break;
		}
	}
}
