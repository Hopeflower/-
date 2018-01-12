#include<iostream>
#include"Calc.h"
using namespace std;
void menu1()
{
	cout << endl;
	cout << "       ��������������������������������������������������������������" << endl;
	cout << "       ��      �������︴�������Լ�������������������  ��" << endl;
	cout << "       ��                   1.  ��������                           ��" << endl;
	cout << "       ��                   2.  ����������                         ��" << endl;
	cout << "       ��                   3.  �˳�����                           ��" << endl;
	cout << "       ��������������������������������������������������������������" << endl;
	cout << "                       <><ע�⣺���ַ��ô��渴��><>" << endl;
	cout << endl;
}
void menu2()
{
	cout << endl;
	cout << "       ��������������������������������������������������������������" << endl;
	cout << "       ��      �������︴�����ܡ�������                ��" << endl;
	cout << "       ��                   1.  ������ӡ�+��                      ��" << endl;
	cout << "       ��                   2.  ������ӡ�-��                      ��" << endl;
	cout << "       ��                   3.  ������ӡ�*��                      ��" << endl;
	cout << "       ��                   4.  ������ӡ�/��                      ��" << endl;
	cout << "       ��                   5.  �����Ƚϴ�С                       ��" << endl;
	cout << "       ��                   6.  ����ģ�Ƚϴ�С                     ��" << endl;
	cout << "       ��                   7.  �˳�����                           ��" << endl;
	cout << "       ��������������������������������������������������������������" << endl;
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
				cout<< "<><��ѡ����(1-��+�� 2-��-�� 3-��*�� 4-��/�� 5-���Ƚϴ�С��6-���Ƚ�ģ�Ĵ�С��7-���˳���)><>: ";
				int num2;
				cin >> num2;
				switch (num2)
				{
				case 1:
				{
					cout << "�������︴����ӡ�������" << endl;
					double a, b, c, d;
					cout << "���������" << endl;
					cin >> a >> b;
					Complex c1(a, b);
					cout << "���뱻������" << endl;
					cin >> c >> d;
					Complex c2(c, d);
					cout << c1 + c2 << endl;
					break;
				}
				case 2:
				{
					cout << "�������︴�������������" << endl;
					double a, b, c, d;
					cout << "���������" << endl;
					cin >> a >> b;
					Complex c1(a, b);
					cout << "���뱻������" << endl;
					cin >> c >> d;
					Complex c2(c, d);
					cout << c1 - c2 << endl;
					break;
				}
				case 3:
				{
					cout << "�������︴����ˡ�������" << endl;
					double a, b, c, d;
					cout << "���������" << endl;
					cin >> a >> b;
					Complex c1(a, b);
					cout << "���뱻������" << endl;
					cin >> c >> d;
					Complex c2(c, d);
					cout << c1 * c2 << endl;
					break;
				}
				case 4:
				{
					cout << "�������︴�������������" << endl;
					double a, b, c, d;
					cout << "���������" << endl;
					cin >> a >> b;
					Complex c1(a, b);
					cout << "���뱻������" << endl;
					cin >> c >> d;
					Complex c2(c, d);
					cout << c1 / c2 << endl;
					break;
				}
				case 5:
				{
					cout << "�������︴���Ƚϡ�������" << endl;
					double a, b, c, d;
					cout << "���븴��c1��" << endl;
					cin >> a >> b;
					Complex c1(a, b);
					cout << "���븴��c2��" << endl;
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
					cout << "�������︴��ģ�Ƚϡ�������" << endl;
					double a, b, c, d;
					cout << "���븴��c1��" << endl;
					cin >> a >> b;
					Complex c1(a, b);
					cout << "���븴��c2��" << endl;
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
					cout << "<><����������˳��ɹ���><>" << endl;
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
			cout << "������������ַ��͸���������#����:ע��#����0 0" << endl;
			while (s[x - 1] != '#')
			{
				cout << "��������ַ���";
				cin >> s[x];
				cout << "���븴��:";
				cin >> a>>b;
				Complex C(a, b);
				Z[x] = C;
				x++;
			}
			cout << "�������ʽ�ӣ�����#������ע��#ǰ���� ��+��" << endl;
			while (ch[y - 1] != '#')
			{
				cin >> ch[y];
				y++;
			}
			clac exp1(ch, s, Z);
			cout << "���Ϊ��"<<exp1.result();
			break;
			
		}
		case 3:
		{
			cout << endl;
			cout << "<><�˳��ɹ���><>" << endl;
			exit(0);
		}
		default:
			break;
		}
	}
}
