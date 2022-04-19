#include<iostream>
#include<windows.h>
#include<ctime>

using namespace std;

struct List
{
public:
	List();
	~List();
	void push_back(int data);
	int GetSize() { return size; }
	void View_head();
	void View_end();
	void pop_front();
	void push_front(int data);
	void clear();
	int& operator[](const int index);
private:
	int size;
	struct Node
	{
		Node* pNext;
		Node* pPrev;
		int data;
		Node(int data = 0, Node * pNext = nullptr, Node * pPrev = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
			this->pPrev = pPrev;
		}
	};
	Node* head;
	Node* tail;
};

List::List()
{
	size = 0;
	head = nullptr;
	tail = nullptr;
}

List::~List()
{
}

void List::push_back(int data)
{
	if (head == nullptr)
	{
		head = new Node(data);
		tail = head;
	}
	else
	{
		Node* current = this->head;
		while (current->pNext != 0)
		{
			current = current->pNext;
		}
		current->pNext = new Node(data, nullptr, current);
		tail = current->pNext;
	}
	size++;
}


void List::pop_front()
{
	if (size == 1)
	{
		Node* tmp = head;
		head = nullptr;
		tail = head;
	}
	if (size > 1)
	{
		Node* tmp = head;
		head = nullptr;
		head = tmp->pNext;
		head->pPrev = nullptr;
		delete tmp;
	}
	size--;
}

void List::push_front(int data)
{
	Node* r = head;
	head = nullptr;
	head = new Node(data);
	while (tail->pPrev != 0)
	{
		tail = tail->pPrev;
	}
	head->pNext = tail;
	tail->pPrev = head;
	head->pPrev = nullptr;
	r->pPrev = head;
	head->pNext = r;
	while (tail->pNext != 0)
	{
		tail = tail->pNext;
	}
	size++;
}

void List::View_head()
{

	for (Node* current = head; current != 0; current = current->pNext)
	{
		cout << current->data << " ";
	}
}

void List::View_end()
{
	for (Node* current = tail; current != 0; current = current->pPrev)
	{
		cout << current->data << " ";
	}
}

void List::clear()
{
	while (size)
	{
		pop_front();
	}
}


int& List::operator[](const int index)
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





int menu();



int main()
{
	time(NULL);
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	List lst;
menu:int choice = menu();
	system("cls");
	switch (choice)
	{
	case 1:
	{
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
		lst.View_head();
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
		lst.View_end();
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
		int numb;
		cout << "Введите число:";
		cin >> numb;
		lst.push_front(numb);
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
		int numb;
		cout << "Введите число:";
		cin >> numb;
		lst.push_back(numb);
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
		int n = 0, m = 0;
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
	}


	return 0;
}













int menu()
{
	cout << "1.Создание" << endl;
	cout << "2.Просмотр с начала" << endl;
	cout << "3.Просмотр с конца" << endl;
	cout << "4.Добавление в начало" << endl;
	cout << "5.Добавление в конец" << endl;
	cout << "6.Индивидуальное задание" << endl;
	cout << "7.Выход" << endl;
	int choice;
Y:cin >> choice;
	if (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7)
	{
		cout << "Введите ещё раз" << endl;
		goto Y;
	}
	else return choice;
}