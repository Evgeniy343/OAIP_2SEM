#include <iostream>
#include <math.h>
#include <windows.h>

using namespace std;

double func(int n)
{
	if (n == 2)
	{
		return(1 + 1 / (pow(n, 2) - 1));
	}
	if (n == 0)
	{
		return 0;
	}
		return(1 + 1 / (pow(n, 2) - 1)) * func(n - 2);
}


int main()
{
	system("chcp 1251>nul");
	int  choice;
	int p;
	double y = 1;
	P:cout << "Введите чётное n >= 2: ";
	cin >> p;
	if (p <= 2 || p%2 != 0)
	{
		goto P;
	}
	cout << "1.Рекурсия" << endl;
	cout << "2.Цикл" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		cout << func(p);
		break;
	}
	case 2:
	{
		for (int i = p; i >= 2; i -= 2)
		{
			y = y * (1 + 1 / (pow(i, 2) - 1));
		}
		cout << y;
		break;
	}
	}
	return 0;
}

