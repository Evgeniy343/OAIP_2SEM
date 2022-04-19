#include <iostream>
#include <math.h>
#include <string.h>
#include <windows.h>
#include <fstream>
#include<string>


using namespace std;




struct Student {
	char name[50];
	int year, group;
	int physics, math, informatics, chemistry;
	double average_mark;
	Student(const char* a = "NULL", int b = 0, int c = 0, int d = 0, int e = 0, int f = 0, int g = 0)
	{
		strcpy_s(name, a);
		year = b;
		group = c;
		physics = d;
		math = e;
		informatics = f;
		chemistry = g;
		average_mark = (e + f + g + d) / 4.0;
	}
	void Print1()
	{
		cout << "Фамилия и инициалы: " << name << endl << "  Год рождения: " << year << endl << "  Группа: " << group << endl << "  Физика: " << physics << endl << "  Математика: " << math << endl << "  Информатика: " << informatics << endl << "  Химия: " << chemistry << endl << "  Средний балл: " << average_mark << endl << endl;
	}
};

fstream file;
int menu();
Student students[100];
Student Sozdanie();
void Print();
void Savedata();

Student Rewrite(int y)
{
	cout << "Введите фамилию и инициалы: ";
	gets_s(students[y].name);
	cout << "Введите год рождения: ";
	cin >> students[y].year;
	cout << "Введите номер группы: ";
	cin >> students[y].group;
	cout << "Введите оценку по физике: ";
	cin >> students[y].physics;
	cout << "Введите оценку по математике: ";
	cin >> students[y].math;
	cout << "Введите оценку по информатике: ";
	cin >> students[y].informatics;
	cout << "Введите оценку по химии: ";
	cin >> students[y].chemistry;
	Student result = Student(students[y].name, students[y].year, students[y].group, students[y].physics, students[y].math, students[y].informatics, students[y].chemistry);
	return result;
}


int main()
{
menu:system("chcp 1251>nul");
	int i = 0;
	int n = 0;
	file.open("myBsuir.txt", fstream::in | fstream::out);
	while (file.read((char*)& students[i], sizeof(Student)))
	{
		i++;
		n++;
	}
	file.close();
	int choice = menu();	

	switch (choice) {
	case 1:
	{
	newstudent:cin.ignore();
		Student stud;
		stud = Sozdanie();
		file.open("myBsuir.txt", fstream::in | fstream::out | fstream::app);
		file.write((char*)& stud, sizeof(Student));
		file.close();
		int t;
		cout << "1.Хотите создать ещё одного студента" << endl;
		cout << "2.Вернуться в меню" << endl;
		cin >> t;
		if (t == 1)
		{
			goto newstudent;
		}
		if (t == 2)
		{
			system("cls");
			goto menu;
		}
		break;
	}
	case 2:
	{
		cout << endl;
		Print();

		int t;
	P:
		cout << "1.Вернуться в меню" << endl;
		cin >> t;
		if (t != 1)
		{
			system("cls");
			goto P;
		}
		if (t == 1)
		{
			system("cls");
			goto menu;
		}
		break;

	}
	case 3:
	{
	editstudent:
		file.open("myBsuir.txt", ios::trunc);
		file.close();
		system("cls");
		cin.ignore();
		int result;
		char surname[50];
	Search_stud:
		cout << "Поиск студента: ";
		gets_s(surname);
		for (int j = 0; j < 100; j++)
		{
			result = strcmp(students[j].name, surname);
			if (result == 0)
			{
				cout << "Данные изменяемого студента:" << endl;
				students[j].Print1();
				students[j] = Rewrite(j);
				system("cls");
				cout << "Новые данные студента:" << endl;
				students[j].Print1();
				break;
			}
		}
		if (result != 0)
		{
			cout << "Студент не найден,повторите попытку" << endl;
			goto Search_stud;
		}
		Savedata();
		int t;
		cout << "1.Хотите редактировать ещё одного студента" << endl;
		cout << "2.Вернуться в меню" << endl;
		cin >> t;
		if (t == 1)
		{
			goto editstudent;
		}
		if (t == 2)
		{
			system("cls");
			goto menu;
		}
		break;
	}
	case 4:
	{
		system("cls");
		int group;
		cout << "Введите интересующую вас группу:";
		cin >> group;
		for (int i = 0; i < 100; i++)
		{
			if (students[i].group == group && students[i].average_mark < 4)
			{
				students[i].Print1();
			}

		}
		int t;
		cout << "1.Вернуться в меню" << endl;
		cin >> t;
		if (t == 1)
		{
			system("cls");
			goto menu;
		}
		break;
	}
	case 5:
	{
		system("cls");
		cout << "Спасибо за работу!";
		break;
	}
	
	}


	return 0;
}



int menu()
{
	cout << "1.Создание" << endl;
	cout << "2.Просмотр" << endl;
	cout << "3.Коррекция" << endl;
	cout << "4.Индивидуальное задание" << endl;
	cout << "5.Выход" << endl;
	int choice;
Y:cin >> choice;
	if (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5)
	{
		cout << "Введите ещё раз" << endl;
		goto Y;
	}
	else return choice;
}




Student Sozdanie()
{
	char name[50];
	int year, group, physics, math, informatics, chemistry;
	system("cls");
	cout << "Введите фамилию и инициалы: ";
	gets_s(name);
	cout << "Введите год рождения: ";
	cin >> year;
	cout << "Введите номер группы: ";
	cin >> group;
	cout << "Введите оценку по физике: ";
	cin >> physics;
	cout << "Введите оценку по математике: ";
	cin >> math;
	cout << "Введите оценку по информатике: ";
	cin >> informatics;
	cout << "Введите оценку по химии: ";
	cin >> chemistry;
	Student result = Student(name, year, group, physics, math, informatics, chemistry);
	return result;
}



void Print()
{
	system("cls");
	for (int i = 0; i < 100; i++)
	{
		int result = strcmp(students[i].name, "NULL");
		if (result == 0)
		{
			break;
		}
		students[i].Print1();
	}

}

void Savedata()
{
	file.open("myBsuir.txt");
	for (int i = 0; i < 100; i++)
	{
		int result = strcmp(students[i].name, "NULL");
		if (result == 0)
		{
			break;

		}
		file.write((char*)& students[i], sizeof(Student));
	}
	file.close();

}