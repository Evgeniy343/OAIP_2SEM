#include <iostream>
#include <ctime>
#include <string>
#include <windows.h>
#include <map>
using namespace std;


struct Node   //Представление узлов дерева
{
	string info;
	int key;
	Node* left;
	Node* right;

	Node(int k, string info = "")
	{
		key = k;
		this->info = info;
		left = right = NULL;

	}
};


//unsigned char height(Node* p) // Помогает функции получить высоту даже для нулевых узлов
//{
//	if (p)
//	{
//		return p->height;
//	}
//	return 0;
//}
//
//
//void fixHeight(Node* p) // Исправляет высоту,если правая и левая высота одинаковые
//{
//	unsigned char Hleft = height(p->left);
//	unsigned char Hright = height(p->right);
//	if (Hleft > Hright)
//	{
//		p->height = Hleft + 1;
//
//	}
//	else if (Hright < Hleft)
//	{
//		p->height = Hright + 1;
//	}
//
//}
//
//int bFactor(Node* p) // Функция получения фактора баланса
//{
//	return height(p->right) - height(p->left);
//}
//
//
//Node* rotateRight(Node* p) // Вращение вправо 
//{
//	Node* newRoot = p->left;
//	p->left = newRoot->right;
//	newRoot->right = p;
//	fixHeight(p);
//	fixHeight(newRoot);
//	return newRoot;
//}
//
//Node* rotateLeft(Node* p) // Вращение влево 
//{
//	Node* newRoot = p->right;
//	p->left = newRoot->left;
//	newRoot->left = p;
//	fixHeight(p);
//	fixHeight(newRoot);
//	return newRoot;
//}
//
//Node* balance(Node* p)
//{
//	fixHeight(p);
//	if (bFactor(p) == 2)
//	{
//		if (bFactor(p->right) < 0)
//		{
//			p->right = rotateRight(p->right);
//		}
//		return rotateLeft(p);
//	}
//
//	if (bFactor(p) == -2)
//	{
//		if (bFactor(p->left) > 0)
//		{
//			p->left = rotateLeft(p->left);
//		}
//		return rotateRight(p);
//	}
//	return p;
//}

void run(Node* p, int* arr, int* cnt, string* inf)
{
	if (p)
	{
		run(p->right, arr, cnt, inf);  // cnt - хранит размер массива
		arr[*cnt] = p->key;
		inf[*cnt] = p->info;
		(*cnt)++;
		run(p->left, arr, cnt, inf);

	}
}

void Make_Blns(Node** p, int n, int key, int* a, string* inf)
{
	if (n == key)
	{
		*p = NULL;
		return;
	}

	else {
		int m = (n + key) / 2;
		*p = new Node(key, *inf);
		(*p)->key = a[m];
		(*p)->info = inf[m];
		Make_Blns(&(*p)->left, n, m, a, inf);
		Make_Blns(&(*p)->right, m + 1, key, a, inf);
	}

}

Node* add(Node* p, int k, string inf = "") // Ищет нужное место и вставляет туда узел
{
	if (!p) return new Node(k, inf);
	if (k < p->key)
		p->left = add(p->left, k, inf);
	else if (k > p->key)
		p->right = add(p->right, k, inf);
	return p;
}

void find(Node* p, int key)
{
	if (!p)
	{
		cout << "Такого значение нет в дереве" << endl;
		return;
	}

	if (key < p->key)
	{
		find(p->left, key);
	}
	if (key > p->key)
	{
		find(p->right, key);
	}
	if (key == p->key)
	{
		cout << to_string(p->key) + " " + p->info << endl;
		return;
	}

}

void view(Node* p, int lev) //Горизонтальный вывод дерева
{
	if (p)
	{
		view(p->right, lev + 5);
		for (int i = 0; i < lev; i++)
		{
			cout << " ";
		}
		cout << to_string(p->key) + " " << endl; /*+ p->info*/
		view(p->left, lev + 5);
	}

}


void viewPreOrder(Node* p)
{ // Вывод - Левая ветка - Правая ветка
	if (p) {
		cout << to_string(p->key) + " - " + p->info + '\n';
		viewPreOrder(p->left);
		viewPreOrder(p->right);
	}
}


void viewPostOrder(Node* p)
{ //  Левая ветка - Правая ветка - Вывод
	if (p) {
		viewPostOrder(p->left);
		viewPostOrder(p->right);
		cout << to_string(p->key) + " - " + p->info + '\n';
	}
}


void viewSort(Node* p)
{ //  Левая ветка - Вывод - Правая ветка 
	if (p) {
		viewSort(p->left);
		cout << to_string(p->key) + " - " + p->info + '\n';
		viewSort(p->right);
	}
}


Node* findMin(Node* p) { //  Функция поиска наименьшего узла
	if (p->left)
	{
		return findMin(p->left);
	}
	return p;
}

Node* removeMin(Node* p)
{ //  Функция удаления узла с наименьшим ключом 
	if (p->left == NULL)
		return p->right;
	p->left = removeMin(p->left);
	return p;
}

Node* remove(Node* p, int k) { // Удаление ключа из дерева
	if (!p)
	{
		return 0;
	}
	if (k < p->key)
	{
		p->left = remove(p->left, k);
	}
	else if (k > p->key)
	{
		p->right = remove(p->right, k);
	}
	else if (k == p->key)
	{
		Node* left = p->left;
		Node* right = p->right;
		delete p;
		if (!right)
		{
			return left;
		}
		Node* min = findMin(right);  //  Ищет минимальный узел в правом узле и сохраняет указатель *min
		min->right = removeMin(right); // - Удаляет минимальный узел в правом узле
		min->left = left;
		return min;     // Делает наш указатель новым узлом нашего дерева 
	}
	return p;
}


void Count(Node* p, map<int, int>& m, int level) // индивидуальное задание(контейнер map)
{
	m[level]++;
	if (p->left)  Count(p->left, m, level + 1);
	if (p->right) Count(p->right, m, level + 1);
}



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	Node* Root = NULL;
	while (true)
	{
		view(Root, 5);
		cout << "1.Заполнить дерево числами\n2.Найти информацию по заданному ключу\n";
		cout << "3.Удалить ключ из дерева\n4.Вывести информацию\n5.Индивидуальное задание\n6.Балансировка дерева\n7.Выход\n";
		int choose;
		cin >> choose;
		switch (choose)
		{
		case 1:
		{
			system("cls");
			cout << "1.Заполнить дерево рандомными числами: \n2.Ввести ключи: ";
			int option;
			string inf = "";
			cin >> option;
			if (option == 1)
			{
				int n;
				cout << "Введите количество ключей: ";
				cin >> n;
				for (int i = 0; i < n; i++)
				{
					Root = add(Root, rand() % 30, inf);
				}
			}
			else
			{
				int s;
				cout << "Сколько ключей вы хотите добавить?";
				cin >> s;
				for (int i = 0; i < s; i++)
				{
					int num;
					string inf;
					system("cls");
					cout << "Введите значение ключа: ";
					cin >> num;
					cout << "Ввеедите информацию: ";
					cin >> inf;
					Root = add(Root, num, inf);
				}
			}
			break;
		}
		case 2:
		{
			int fkey;
			cout << "Введите ключ, по которому будем искать: ";
			cin >> fkey;
			find(Root, fkey);
			system("pause");
			break;

		}
		case 3:
		{
			int dkey;
			cout << "Введите ключ, по которому хотите удалить :";
			cin >> dkey;
			system("cls");
			cout << "Старое дерево : " << endl;
			view(Root, 5);
			Root = remove(Root, dkey);
			cout << "Новое дерево : " << endl;
			view(Root, 0);
			system("pause");
			break;

		}
		case 4:
		{
			int option;
			cout << "1.Прямым обходом\n2.Обратным обходом\n3.В порядке возрстания\n";
			cin >> option;
			if (option == 1)
			{
				viewPreOrder(Root);
				system("pause");
			}
			else if (option == 2)
			{
				viewPostOrder(Root);
				system("pause");

			}
			else if (option == 3)
			{
				viewSort(Root);
				system("pause");
			}
			break;
		}
		case 5:
		{
			map<int, int> m;
			Count(Root, m, 0);
			for (auto i : m)  // range - based цикл , работает для перегруженных методов begin() и end()
			{
				cout << "На уровне " << i.first << " находится " << i.second << " узлов.\n";
			}
			break;

		}
		case 6:
		{
			system("cls");
			cout << "Исходное дерево: " << endl;
			view(Root, 5);
			cout << "Отбалансированное дерево: " << endl;


			int count = 0;
			int arr[256];
			string txt[256];
			run(Root, arr, &count, txt);
			for (int i = 0; i < count - 1; i++)
			{
				for (int j = i + 1; j < count; j++)
				{
					if (arr[i] > arr[j])
					{
						int temp = arr[i];
						arr[i] = arr[j];
						arr[j] = temp;

						string stemp = txt[i];
						txt[i] = txt[j];
						txt[j] = stemp;
					}
				}
			}
			Make_Blns(&Root, 0, count, arr, txt);

			break;
		}
		case 7:
		{
			cout << "Окончание работы...";
			return 0;
		}
		///////////////
		}


	}

}

