#include<iostream>
#include<ctime>
#include<windows.h>

using namespace std;

struct list
{
private:
	struct Node
	{
	public:
		Node* pNext;
		int data;
		Node(int data = 0, Node * pNext = nullptr)
		{
			this->pNext = pNext;
			this->data = data;
		}
	};
	int size;
	Node* head;
public:
	list();
	~list();
	void push_back(int data);
	int GetSize() { return size; }
	int& operator[](const int index);
	void pop_front();
	void clear();
	void Sort_Info();
	void Sort_Adress();
	void push_front();
	int pop_back();
	void individ_on_ten(int min);
	//void sort();
	int minimum();
};

list::list()
{
	size = 0;
	head = nullptr;
}


list::~list()
{
}



void list::push_back(int data)
{
	if (head == nullptr)
	{
		head = new Node(data);
	}
	else
	{
		Node* current = this->head;
		while (current->pNext != 0)
		{
			current = current->pNext;
		}
		current->pNext = new Node(data);
	}
	size++;
}


int& list::operator[](const int index)
{
	int counter = 0;
	Node* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}


void list::pop_front()
{
	Node* tmp = head;
	head = head->pNext;
	delete tmp;
	size--;
}


void list::clear()
{
	while (size)
	{
		pop_front();
	}
}

void list::Sort_Info()
{
	Node* tmp = nullptr;
	Node* i;
	int r = 0;
	for (int j = 0; j < size; j++)
	{
		for (i = head; i->pNext != tmp; i = i->pNext)
		{
			if (i->data > i->pNext->data)
			{
				r = i->data;
				i->data = i->pNext->data;
				i->pNext->data = r;
			}
		}
	}

}


void list::Sort_Adress()
{
	Node** p = &head;
	Node* t = NULL;
	Node* t1;
	Node* r;
	if ((*p)->pNext->pNext == NULL) return;
	do {
		for (t1 = *p; t1->pNext->pNext != t; t1 = t1->pNext)
			if (t1->pNext->data > t1->pNext->pNext->data) {
				r = t1->pNext->pNext;
				t1->pNext->pNext = r->pNext;
				r->pNext = t1->pNext;
				t1->pNext = r;
			}
		t = t1->pNext;
	} while ((*p)->pNext->pNext != t);
}

void list::push_front()
{
	Node* r = head;
	head = nullptr;
	head = new Node(1);
	head->pNext = r;
	size++;
}

int list::pop_back()
{
	int numb = 0;
		Node* current = this->head;
		while (current->pNext->pNext != 0)
		{
			current = current->pNext;
		}
		numb = current->pNext->data;
		current->pNext = NULL;
	size--;
	return numb;
}

void list::individ_on_ten(int min)
{
	Node* current = this->head;
	while (current->pNext->data != min)
	{
		current = current->pNext;
	}
	if (current->pNext->pNext == NULL)
	{
		current->pNext = NULL;
	}
	else
	{
		current->pNext = current->pNext->pNext;
	}
	while (current->pNext != nullptr)
	{
		current = current->pNext;
	}

	Node* last = new Node(5);
	last->data = current->data;
	current->data = min;
	current->pNext = new Node(last->data);
}

int list::minimum()
{
	int min = 0;
	Node* current2 = head;
	Node* current1 = head;
	min = current1->data;
	while (true)
	{
		if (min > current2->data)
		{
			min = current2->data;
		}
		if (current2->pNext == NULL)
		{
			break;
		}
		current2 = current2->pNext;
	}
	return min;
}

//void list::sort()
//{
//	Node* pivot = this->head;
//	for (int i = 0; i < size; i++)
//	{
//		Node* right = pivot->pNext;
//		for (int j = 0; j < size; j++)
//		{
//			if (pivot->data > right->data)
//			{
//				Node* current = new Node(5);
//				current->data = pivot->data;
//				pivot->data = pivot->pNext->data;
//				pivot->data = current->data;
//			}
//			right = right->pNext;
//		}
//		pivot = pivot->pNext;
//	}
//}









int menu();


int main()
{
	time(NULL);
	list lst;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
menu:int choice = menu();
	system("cls");
	switch (choice)
	{
	case 1:
	{
		int choice;
		int n;
		cout << "N: ";
		cin >> n;
		while (n != 0)
		{
			lst.push_back(10 + rand() % 20);
			n--;
		}
	ch1:cout << "1.Вернуться в меню: ";
		cin >> choice;
		system("cls");
		if (choice == 1)
		{
			goto menu;
		}
		else
		{
			goto ch1;
		}
		break;
	}
	case 2:
	{
		int choice;
		for (int i = 0; i < lst.GetSize(); i++)
		{
			cout << lst[i] << "  ";
		}
		cout << endl;
	ch2:cout << "1.Вернуться в меню: ";
		cin >> choice;
		system("cls");
		if (choice == 1)
		{
			goto menu;
		}
		else
		{
			goto ch2;
		}
		break;
	}
	case 3:
	{
		int choice;
		int k;
		cout << "Введите число: ";
		cin >> k;
		lst.push_back(k);
	ch3:cout << "1.Вернуться в меню: ";
		cin >> choice;
		system("cls");
		if (choice == 1)
		{
			goto menu;
		}
		else
		{
			goto ch3;
		}
		break;
	}
	case 4:
	{
		int n = 0, m = 0;
		int choice;
		double average = 0, sum = 0;
		for (int i = 0; i < lst.GetSize(); i++)
		{
			sum += lst[i];
			m++;
		}
		average = sum / m;
		int* mass = new int[m];
		for (int i = 0; i < m; i++)
		{
			mass[i] = lst[i];
		}
		lst.clear();
		for (int i = 0; i < m; i++)
		{
			if (mass[i] < average)
			{
				n++;
			}
			else
			{
				lst.push_back(mass[i]);
			}
		}
		cout << "Кол-во чисел меньше среднего значения: " << n;
		cout << endl;
	ch4:cout << "1.Вернуться в меню: ";
		cin >> choice;
		system("cls");
		if (choice == 1)
		{
			goto menu;
		}
		else
		{
			goto ch4;
		}
		break;
	}
	case 5:
	{
		lst.Sort_Info();
		//	for (int j = 0; j < lst.GetSize(); j++)
		//	{
		//		for (int i = 0; i < lst.GetSize(); i++)
		//		{
		//			if (i + 1 == lst.GetSize())
		//			{
		//				break;
		//			}
		//			if (lst[i] > lst[i + 1])
		//			{
		//				int tmp = lst[i];
		//				lst[i] = lst[i + 1];
		//				lst[i + 1] = tmp;
		//			}
		//		}
		//	}
	ch5:cout << "1.Вернуться в меню: ";
		cin >> choice;
		system("cls");
		if (choice == 1)
		{
			goto menu;
		}
		else
		{
			goto ch5;
		}
		break;
	}
	case 6:
	{
		int choice;
		lst.push_front();
		lst.Sort_Adress();
		lst.pop_front();
	ch6:cout << "1.Вернуться в меню: ";
		cin >> choice;
		system("cls");
		if (choice == 1)
		{
			goto menu;
		}
		else
		{
			goto ch6;
		}
		break;
	}
	case 7:
	{
		int choice;
		int numb = lst.pop_back();
		cout << numb << endl;
	ch7:cout << "1.Вернуться в меню: ";
		cin >> choice;
		system("cls");
		if (choice == 1)
		{
			goto menu;
		}
		else
		{
			goto ch7;
		}
		break;
	}
case 8:
{
	int choice;
	//int mass[100];
	//for (int i = 0; i < lst.GetSize(); i++)
	//{
	//	mass[i] = lst[i];
	//}
	//int n = lst.GetSize();
	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//	{
	//		if (j + 1 == n)
	//		{
	//			break;
	//		}
	//		if (mass[j] > mass[j + 1])
	//		{
	//			int tmp = mass[j];
	//			mass[j] = mass[j + 1];
	//			mass[j + 1] = tmp;
	//		}
	//	}
	//}
	int min = lst.minimum();
	lst.individ_on_ten(min);
ch8:cout << "1.Вернуться в меню: ";
	cin >> choice;
	system("cls");
	if (choice == 1)
	{
		goto menu;
	}
	else
	{
		goto ch8;
	}
	break;
}
	}

	return 0;
}



int menu()
{
	cout << "1.Создание" << endl;
	cout << "2.Просмотр" << endl;
	cout << "3.Добавление" << endl;
	cout << "4.Индивидуальное задание" << endl;
	cout << "5.Сортировка с обменом данными" << endl;
	cout << "6.Сортировка с обменом адресов" << endl;
	cout << "7.Удаление в конце" << endl;
	cout << "8.Наименьший элемент переставить на предпоследнее место" << endl;
	cout << "9.Выход" << endl;
	int choice;
Y:cin >> choice;
	if (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7 && choice !=8 && choice != 9)
	{
		cout << "Введите ещё раз" << endl;
		goto Y;
	}
	else return choice;
}
