#include<iostream>
#include<windows.h>
#include<fstream>
#include<conio.h>

using namespace std;


struct Employee
{
	char name[50], position[50];
	int depart_numb, date;
	Employee(const char* name = "NULL", const char* position = "NULL", int depart_numb = 0, int date = 0)
	{
		strcpy_s(this->name, name);
		strcpy_s(this->position, position);
		this->depart_numb = depart_numb;
		this->date = date;
	}
	void Printf()
	{
		cout << "ФИО:" << name << endl << "Должность:" << position << endl << "Номер отдела:" << depart_numb << endl << "Дата начала работы:" << date << endl << endl << endl;
	}

};

int Search(Employee *peoples, int n);
fstream file;
int menu();
Employee Create();
void quickSort(int left, int right, Employee* peoples);
void Sort_Vub(Employee *peoples, int n);
void Print2(Employee *peoples, int search);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int m;
	cout << "Введите кол-во студентов: ";
	cin >> m;
	Employee* peoples = new Employee[m];
	int n = 1;
	int choice = 0;
	string path = "4.txt";
	menu:int i = 0;
	file.open(path, fstream::in | fstream::out | fstream::app);
	n = 0;
	while (file.read((char*)& peoples[i], sizeof(Employee)))
	{
		i++;
		n++;
	}
	file.close();
choice = menu();
	cin.ignore();
	switch (choice)
	{
	case 1:
	{
		system("cls");
		for (int i = 0; i <= n; i++)
		{
			peoples[i] = Create();
			system("cls");
			file.open(path, fstream::in | fstream::out | fstream::app);
			file.write((char*)& peoples[i], sizeof(Employee));
			file.close();
			cout << "1.Хотите создать ещё одного сотрудника" << endl;
			cout << "2.Хотите вернуться в меню" << endl;
			cin >> choice;
			system("cls");
			cin.ignore();
			if (choice == 1)
			{
				n++;
			}
			if (choice == 2)
			{
				goto menu;
			}
		}
		break;
	}
	case 2:
	{
		system("cls");
		for (int i = 0; i < n; i++)
		{
			Employee people = peoples[i];
			people.Printf();
		}
		cout << "1.Хотите вернуться в меню" << endl;
		cin >> choice;
		system("cls");
		if (choice == 1)
		{
			goto menu;
		}
		break;
	}
	case 3:
	{
		system("cls");
		quickSort(0, n - 1, peoples);
		file.open(path, fstream::in | fstream::out | fstream::trunc);
		for (int i = 0; i < n; i++)
		{
			file.write((char*)& peoples[i], sizeof(Employee));
		}
		file.close();
		int number;
		cout << "Введите номер отдела:" << endl;
		cin >> number;
		for (int i = 0; i < n; i++)
		{
			Employee people = peoples[i];
			if (people.depart_numb == number)
			{
				people.Printf();
			}
		}
		cout << "1.Хотите вернуться в меню" << endl;
		cin >> choice;
		system("cls");
		if (choice == 1)
		{
			goto menu;
		}
	}
	case 4:
	{
		system("cls");
		for (int i = n; i <= n; i++)
		{
			peoples[i] = Create();
			system("cls");
			file.open(path, fstream::in | fstream::out | fstream::app);
			file.write((char*)& peoples[i], sizeof(Employee));
			file.close();
			cout << "1.Хотите добавить ещё одного сотрудника" << endl;
			cout << "2.Хотите вернуться в меню" << endl;
			cin >> choice;
			cin.ignore();
			system("cls");
			if (choice == 1)
			{
				n++;
			}
			if (choice == 2)
			{
				n++;
				goto menu;
			}
		}
		break;
	}
	case 5:
	{
		system("cls");
		Sort_Vub(peoples, n);
		file.open(path, fstream::in | fstream::out | fstream::trunc);
		for (int i = 0; i < n; i++)
		{
			file.write((char*)& peoples[i], sizeof(Employee));
		}
		file.close();
		for (int i = 0; i < n; i++)
		{
			Employee people = peoples[i];
			people.Printf();
		}
		cout << "1.Хотите вернуться в меню" << endl;
		cin >> choice;
		system("cls");
		if (choice == 1)
		{
			goto menu;
		}
		break;
	}
	case 6:
	{
		system("cls");
		file.open(path, fstream::in | fstream::out | fstream::trunc);
		file.close();
		cout << "1.Хотите вернуться в меню" << endl;
		cin >> choice;
		system("cls");
		if (choice == 1)
		{
			goto menu;
		}
		break;
	}
	case 7:
	{
		system("cls");
		er:for (int i = 0; i < n; i++)
		{
			Employee people = peoples[i];
			people.Printf();
		}
		int search = Search(peoples, n);
		if (search == -1)
		{
			goto er;
		}
		system("cls");
		ERR:Print2(peoples, search);
		int choice1 = 0;
		cout << "1.ФИО" << endl;
		cout << "2.Должность" << endl;
		cout << "3.Дата начала работы" << endl;
		cout << "4.Номер отдела" << endl;
		cout << "Введите характеристику, которую хотите изменить" << endl;
		cin >> choice1;
		system("cls");
		if (choice1 == 1)
		{
			cout << "Введите новое ФИО" << endl;
			cin.ignore();
			gets_s(peoples[search].name);
			goto file;
		}
		if (choice1 == 2)
		{
			cout << "Введите новую должность" << endl;
			cin.ignore();
			gets_s(peoples[search].position);
			goto file;
		}
		if (choice1 == 3)
		{
			cout << "Введите новую дату начала работы" << endl;
			cin >> peoples[search].date;
			goto file;
		}
		if (choice1 == 4)
		{
			cout << "Введите номер отдела" << endl;
			cin >> peoples[search].depart_numb;
			goto file;
		}
		if (choice1 != 1 && choice1 != 2 && choice1 != 3 && choice1 != 4)
		{
			cout << "Ошибка, введите снова" << endl;
			_getch();
			system("cls");
			goto ERR;
		}
		file:
		file.open(path, fstream::in | fstream::out | fstream::trunc);
		for (int i = 0; i < n; i++)
		{
			file.write((char*)& peoples[i], sizeof(Employee));
		}
		file.close();
		cout << "1.Хотите вернуться в меню" << endl;
		cin >> choice;
		system("cls");
		if (choice == 1)
		{
			goto menu;
		}
		break;
	}
	case 8:
	{
		search1:for (int i = 0; i < n; i++)
		{
			Employee people = peoples[i];
			people.Printf();
		}
		bool flag = false;
		int key,mid;
		cout << "Введите дату начала работы" << endl;
		cin >> key;
		int left = 0;
		int right = n;
		while (left <= right && flag == false)
		{
			mid = (left + right) / 2;
			if (peoples[mid].date == key)
			{
				flag = true;
				Print2(peoples, mid);
				break;
			}
			if (peoples[mid].date < key)
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}
		if (flag == false)
		{
			system("cls");
			cout << "Работник не найден!" << endl;
			_getch();
			system("cls");
			goto search1;
		}
		cout << "1.Хотите вернуться в меню" << endl;
		cin >> choice;
		system("cls");
		if (choice == 1)
		{
			goto menu;
		}
		break;
	}
	case 9:
	{
		break;
	}
	}
	return 0;
	delete[]peoples;
	system("pause");
}


Employee Create()
{
	char name[50], position[50];
	int depart_numb, date;
	cout << "Введите ФИО" << endl;
	gets_s(name);
	cout << "Введите должность" << endl;
	gets_s(position);
	cout << "Введите номер отдела" << endl;
	cin >> depart_numb;
	cout << "Введите дату начала работы" << endl;
	cin >> date;
	Employee result = Employee(name,position,depart_numb,date);
	return result;
}


int menu()
{
	cout << "1.Создание" << endl;
	cout << "2.Просмотр" << endl;
	cout << "3.Сортировка Quicksort" << endl;
	cout << "4.Добавить" << endl;
	cout << "5.Сортировка прямого выбора" << endl;
	cout << "6.Удаление всех студентов" << endl;
	cout << "7.Редактирование" << endl;
	cout << "8.Бинарный поиск" << endl;
	cout << "9.Выход" << endl;
	int choice;
Y:cin >> choice;
	if (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7 && choice != 8 && choice != 9)
	{
		cout << "В	ведите ещё раз" << endl;
		goto Y;
	}
	else return choice;
}


void quickSort(int left, int right, Employee *peoples)
{
	int pivot; 
	int i = left; 
	int j = right; 
	Employee Pivot = peoples[left];
	pivot = peoples[left].date;
	while (left < right) 
	{
		while ((peoples[right].date >= pivot) && (left < right))
			right--; 
		if (left != right) 
		{
			peoples[left] = peoples[right];
			left++; 
		}

		while ((peoples[left].date <= pivot) && (left < right))
			left++; 
		if (left != right) 
		{
			peoples[right] = peoples[left]; 
			right--; 
		}
	}
	peoples[left] = Pivot; 
	pivot = left;
	left = i;
	right = j;
	if (left < pivot) 
		quickSort(left, pivot - 1, peoples);
	if (right > pivot)
		quickSort(pivot + 1, right, peoples);
}






void Sort_Vub(Employee *peoples, int n)
{
	Employee r;
	int i_min, i, j;
	for (i = 0; i < n - 1; i++) {
		i_min = i;
		for (j = i + 1; j < n; j++)
			if (peoples[i_min].date > peoples[j].date) i_min = j;
		if (i_min != i) {
			r = peoples[i_min];    peoples[i_min] = peoples[i];     peoples[i] = r;
		}
	}
}





int Search(Employee *peoples, int n)
{
	char x[50];
	search:cout << "Поиск:" << endl;
	cin.getline(x, 50);
	int i,kod = 0;
	for (i = 0; i < n; i++)
	{
		if (strcmp(peoples[i].name, x) == 0)
		{
			kod = 1;
			break;
		}
	}
	if (kod == 0)
	{
		system("cls");
		cout << "Работник не найден!" << endl;
		_getch();
		system("cls");
		return -1;
	}
	return i;
}


void Print2(Employee *peoples,int search)
{
	cout << "ФИО:" << peoples[search].name << endl << "Должность:" << peoples[search].position << endl << "Номер отдела:" << peoples[search].depart_numb << endl << "Дата начала работы:" << peoples[search].date << endl << endl << endl;
}

