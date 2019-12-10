#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
//#include "List.h"

using namespace std;

//template <typename T>
struct List
{
	struct Node
	{
		//конструктор узла
		Node(int data = int(), Node* pNext = nullptr, Node* pPrev = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
			this->pPrev = pPrev;
		}

		int data;
		Node* pNext;
		Node* pPrev;
	};
//public:
	
	//получение количества элементов в списке
	int GetSize() { return Size; }
	//очистка списка
	void clear();
	//добавление элемента в начало списка
	void push_front(int data);
	//добавление элемента в конец списка
	void push_back(int data);
	//удаление первого элемента в списке
	void pop_front();
	//удаление последнего элемента в списке
	void pop_back();
	//добавление элемента в список по указанному индексу
	void insert(int data, int index);
	//удаление элемента в списке по указанному индексу
	void removeAt(int index);
	//пеегруженный оператор [], который возвращает данные из списка по индексу
	int& operator [] (const int index);
	//вывод списка начиная с "головы"
	void PrintFromHead();
	//вывод списка начиная с "хвоста"
	void PrintFromTail();
	//линейный поиск
	bool LinSearch(int* tempCounter, int value);
	//сортировка
	void InsertingSort();
	void Sort();
	//Обмен данных
	void SwapData(Node* current, Node* nextCurrent);
	//вывод списка
	void Output();

	List();
	~List();



	//template <typename T>
	

	Node* head;
	Node* tail;
	Node* node;
	int Size;
};

List::List()
{
	head = nullptr;
	tail = nullptr;
	Size = 0;
}

List::~List()
{
	clear();
}


void List::clear()
{
	while (Size)
	{
		pop_front();
	}
}


void List::push_front(int data)
{
	if (Size > 1)
	{
		Node* temp = head;
		head = new Node (data, head);
		temp->pPrev = head;
	}
	else if (Size == 1)
	{
		head = new Node (data, head);
		tail->pPrev = this->head;
	}
	else
	{
		head = tail = new Node(data, head, tail);
	}
	Size++;
}


void List::push_back(int data)
{
	if (Size > 1)
	{
		Node* temp = tail;
		tail = new Node(data, nullptr, tail);
		temp->pNext = tail;
	}
	else if (Size == 1)
	{
		tail = new Node(data, nullptr, tail);
		head->pNext = this->tail;
	}
	else
	{
		head = tail = new Node(data, head, tail);
	}
	Size++;
}


void List::pop_front()
{
	if (Size > 1)
	{
		Node* temp = head;
		head = head->pNext;
		delete temp;
	}
	else if (Size == 1)
	{
		Node* temp = head;
		tail = head = head->pNext;
		delete temp;
	}

	Size--;
}


void List::pop_back()
{
	if (Size > 1)
	{
		Node* temp = tail;
		tail = tail->pPrev;
		delete temp;
	}
	else if (Size == 1)
	{
		Node* temp = tail;
		tail = head = tail->pPrev;
		delete temp;
	}

	Size--;
}


void List::insert(int data, int index)
{
	if (index == 0) push_front(data);

	else if (index == Size || index > Size) push_back(data);
	/*здесь можно реализовать проверку, if(index > Size) то кидать исключение, с сообщением пользователю -
	- что он хочет добавить узел по индексу, до которого список еще не дорос. Либо оставить данную реализацию,
	в которой узел просто добавляется в конец*/

	else if (index <= Size / 2)
	{
		Node* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node* newNode = new Node(data, previous->pNext, previous);

		previous->pNext = newNode;
		Node* next = newNode->pNext;
		next->pPrev = newNode;

		Size++;
	}

	else if (index > Size / 2)
	{
		Node* next = this->tail;
		for (int i = Size - 1; index < i; i--)
		{
			next = next->pPrev;
		}

		Node* newNode = new Node(data, next, next->pPrev);

		next->pPrev = newNode;
		Node* previous = newNode->pPrev;
		previous->pNext = newNode;

		Size++;
	}
}


void List::removeAt(int index)
{
	if (index == 0) pop_front();

	else if (index == Size || index > Size) pop_back();
	/*здесь можно реализовать проверку, if(index > Size) то кидать исключение, с сообщением пользователю -
	- что он хочет удалить узел по индексу, которого не существует. Либо оставить данную реализацию,
	в которой просто удаляется последний узел*/

	else if (index <= Size / 2)
	{
		Node* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node* toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		Node* next = toDelete->pNext;
		delete toDelete;
		next->pPrev = previous;

		Size--;
	}

	else if (index > Size / 2)
	{
		Node* next = this->tail;
		for (int i = Size - 1; index < i; i--)
		{
			next = next->pPrev;
		}

		Node* toDelete = next->pPrev;
		next->pPrev = toDelete->pPrev;
		Node* previous = toDelete->pPrev;
		delete toDelete;
		previous->pNext = next;

		Size--;
	}
}

int& List::operator[] (const int index)
{
	if (index <= Size / 2)
	{
		int counter = 0;
		Node* current = this->head;

		while (current != nullptr)
		{
			if (counter == index) return current->data;
			current = current->pNext;
			counter++;
		}
	}
	else
	{
		int counter = Size - 1;
		Node* current = this->tail;

		while (current != nullptr)
		{
			if (counter == index) return current->data;
			current = current->pPrev;
			counter--;
		}
	}
}


void List::PrintFromHead()
{
	cout << "Come the method PrintFromHead:" << endl;
	Node* print = head;
	while (print)
	{
		cout << print->data << endl;
		print = print->pNext;
	}
	cout << endl;
}

void List::PrintFromTail()
{
	cout << "Come the method PrintFromTail:" << endl;
	Node* print = tail;
	while (print)
	{
		cout << print->data << endl;
		print = print->pPrev;
	}
	cout << endl;
}

bool List::LinSearch(int* tempCounter, int value)
{
	Node* current = head;
	while (current != nullptr)
	{
		(*tempCounter)++;
		if (current->data == value)
		{
			return true;
		}
		current = current->pNext;
	}
	return false;
}

void List::SwapData(Node* current, Node* nextCurrent)
{
	cout << "Вход в свап есть" << endl;
	if (nextCurrent->pNext != nullptr)
	{
		nextCurrent->pNext->pPrev = current;
	}
	if (current->pPrev != nullptr)
	{
		current->pPrev->pNext = nextCurrent;
	}
	nextCurrent->pPrev = current->pPrev;
	current->pNext = nextCurrent->pNext;
	nextCurrent->pNext = current;
	current->pPrev = nextCurrent;
	
}

void List::Output()
{
	cout << "Значения элементов списка" << endl;
	if (Size != 0)
	{
		Node* temp = head;
		while (temp->pNext != nullptr)
		{
			cout << temp->data << endl;
			temp = temp->pNext;
		}
		cout << temp->data << endl;
	}
	
}


void List::InsertingSort()
{
	cout << "Вход есть" << endl;
	Node* current = head;
	Node* nextCurrent = current->pNext;
	Node* saveCurrent = new Node;
	saveCurrent = current;
	while (nextCurrent != nullptr)
	{
		if (current->data > nextCurrent->data)
		{
			SwapData(current, nextCurrent);
			if (nextCurrent->pNext == nullptr)
			{
				nextCurrent = current->pNext;
				cout << "Вход в иф есть" << endl;
			}
			else
			{
				cout << "Вход в элс есть" << endl;
				current = nextCurrent->pNext;
			}

		}
		else if (current->data <= nextCurrent->data)
		{
			cout << "Вход else if  есть" << endl;
			current = nextCurrent;
			nextCurrent = nextCurrent->pNext;
			saveCurrent = current;
		}
	}

	tail = current;
	while (current->pNext != nullptr)
	{
		current = current->pNext;
		head = current;
	}

}


/*template<typename T>
void List<T>::Sort()
{



}*/


//проверка вводимого числа
int Check()
{
	int index;
	int number;
	bool correct = false;
	while (!correct) {
		cin >> index;
		if (cin.fail()) {
			cin.clear();
			while (cin.get() != '\n');
			cout << "Пожалуйста, введите допустимое значение." << endl;
			correct = false;
		}
		else {
			cin.ignore();
			number = index;
			correct = true;
		}
	}
	return number;
}

/*void Sort(List* lst)
{
	



}*/


//TODO: Сделать функцию линейного поиска в функции
//Линейный поиск
/*int LinSearch(List* lst, const int value)
{
	int Size = lst->GetSize();
	
	for (int i = 0; i < Size; i++)
	{
		if (&lst[i] == value)
		{
			cout << "Число " << value << " находится в ячейке под индексом " << i << endl;
			return i;

		}
		else
		{
			cout << "Число не найдено" << endl;
			return -1;
		}

	}
}*/


//TODO:	сделать проверки индексов
//TODO: сделать функцию вывода
/*template <typename T>
void Output (List<int>* lst)
{
	
	for (int i = 0; i < lst->GetSize(); i++)
	{
		std::cout << lst[i];
	}
}*/

int main()
{
	setlocale(LC_ALL, "ru");

	List lst;
	
	
	cout << "Введите размер списка" << endl;
	int size;
	size = Check();
	for (int i = 0; i < size; i++)
	{
		int value = rand() % 100;
		lst.push_back(value);
	}
	system("cls");
	cout << "Значение элементов списка: " << endl;
	
	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}
	int ListSize;
	ListSize = lst.GetSize();

	while (true)
	{
		//TODO: Составить нормальное меню
		int number = 0;
		cout << "\n            Введите от 0 до ??: \n" << endl;
		cout << "Для вывода списка введите 1\n" << endl;
		cout << "Для добавления элемента в список введите 2\n" << endl;
		cout << "Для удаление элемента списка введите 3\n" << endl;
		cout << "Для сортировки списка по возрастанию введите 4\n" << endl;
		cout << "Для линейного поиска по элементам в списоке введите 5\n" << endl;
		cout << "Для выхода из программы введите 0\n" << endl;
		
		number = Check();

		switch (number)
		{
		//создание списка
		case 1:
		{
			system("cls");
			//вывод списка
			lst.Output();
			
		}
		break;

		//вставка элемента в список
		case 2:
		{
			cout << "Для добавления элемента в начало списка введите 1" << endl;
			cout << "Для добавления элемента в конец списка введите 2" << endl;
			cout << "Для добавления элемента после определенного элемента введите 3" << endl;
			cout << "Для добавления элемента перед определенным элементом введите 4" << endl;
			int caseNum;
			caseNum = Check();
			switch (caseNum)
			{
			case 1:
			{
				//функция добавления элемента в начало
				int value;
				cout << "Введите добавляемое значение" << endl;
				cin >> value;
				lst.push_front(value);
				system("cls");
				cout << "Значение элементов списка: " << endl;

				for (int i = 0; i < lst.GetSize(); i++)
				{
					cout << lst[i] << endl;
				}
			}
			break;
			case 2:
			{
				//функция добавления элемента в конец
				/* проверка на наличие элементов в списоке if (storage.Length == 0)
				{
					system("cls");
					cout << "список пуст! Выберите добавление элемента в начало списка." << endl;
					system("pause");
					break;
				}*/
				int value;
				cout << "Введите добавляемое значение" << endl;
				cin >> value;
				lst.push_back(value);
				system("cls");
				cout << "Значение элементов списка: " << endl;

				for (int i = 0; i < lst.GetSize(); i++)
				{
					cout << lst[i] << endl;
				}
				break;
			}

			case 3:
			{
				//TODO: сделать проверку на вводимый индекс
				//функция добавления элемента после элемента
				int value;
				int index;
				value = 0;
				cout << "Введите добавляемое значение" << endl;
				cin >> value;
				cout << "Введите индекс после которого необходимо вставить значение" << endl;
				index = Check();
				index++;
				lst.insert(value, index);
				system("cls");
				cout << "Значение элементов списка: " << endl;

				for (int i = 0; i < lst.GetSize(); i++)
				{
					cout << lst[i] << endl;
				}
				/*if (storage.Length == 0)
				{
					system("cls");
					cout << "список пуст! Выберите добавление элемента в начало списка." << endl;
					system("pause");
					break;
				}
				cout << "Введите добавляемое значение" << endl;
				Check(&value);
				cout << "Введите адрес элемента, после которого необходимо вставить значение" << endl;
				Check(&index);
				while (index > storage.Length || index <= -1)
				{
					cout << "Введите правильный адрес" << endl;
					Check(&index);
				}
				PushAfter(&storage, index, value);
				Output(&storage);*/
				break;
			}
			case 4:
			{
				//вставка перед определенным элементом
				//TODO: сделать проверку на вводимый индекс
				int value;
				int index;
				value = 0;
				cout << "Введите добавляемое значение" << endl;
				cin >> value;
				cout << "Введите индекс перед которым необходимо вставить значение" << endl;
				index = Check();
				index--;
				lst.insert(value, index);
				system("cls");
				cout << "Значение элементов списка: " << endl;

				for (int i = 0; i < lst.GetSize(); i++)
				{
					cout << lst[i] << endl;
				}
				break;
			}
			}
			break;
		}

		//удаление элемента из списка
		case 3:
		{

			cout << "Введите индекс удаляемого элемента" << endl;
			int index;
			index = Check();
			if (index == 0)
			{
				lst.pop_front();
			}
			else
			if (index == ListSize)
			{
				lst.pop_back();
			}
			else { lst.removeAt(index); }
			system("cls");
			cout << "Значение элементов списка: " << endl;

			for (int i = 0; i < lst.GetSize(); i++)
			{
				cout << lst[i] << endl;
			}
			break;
			/*while (index > storage.Length || index <= -1)
			{
				cout << "Введите правильный адрес" << endl;
				Check(&index);
			}
			if (storage.Length == 0)
			{
				system("cls");
				cout << "список пуст" << endl;
				system("pause");
				break;
			}
			else
			{
				DelElement(&storage, index);
				Output(&storage);
				break;*/
		}

		//сортировка списка
		case 4:
		{
			lst.InsertingSort();
			system("cls");
			cout << "Значение элементов списка: " << endl;

			for (int i = 0; i < lst.GetSize(); i++)
			{
				cout << lst[i] << endl;
			}
			break;
		}

		//TODO: вставить return'ы
		//линейный поиск
		case 5:
		{
			cout << "Введите значение элемента: ";
			int value = 0;
			cin >> value;
			int tempCounter = 0;
		
			if (lst.LinSearch(&tempCounter, value) == true)
			{
				system("cls");
				cout << "Элемент был найден. Индекс: " << tempCounter << endl;
			}
			else
			{
				system("cls");
				cout << "Элемент не был найден." << endl;
			}

			//int value = 0;
			//cout << "Введите число для поиска" << endl;
			//cin >> value;
			/*
			cout << "Введите число для поиска" << endl;
			value = Check();*/
			//int nElement = 0;
		//	nElement = LinSearch(&lst, value);

			//if (nElement != -1)
			//{
			//	cout << "Значение " << value << " находится в ячейке с индексом: " << nElement << endl;
			//	cout << endl;
			//}

			//else cout << "В массиве нет такого значения" << endl;
			//system("pause");

			/*for (int i = 0; i < lst.GetSize(); i++)
				if (lst[i] == value)
				{
					cout << "Число " << value << " находится в ячейке под индексом " << i << endl;

				}
				else cout << "Число не найдено" << endl;*/
			break;
		}
		{
			/*system("cls");
			cout << "Введите число, которое необходимо найти" << endl;
			int requiredKey = 0;
			Check(&requiredKey);
			int nElement = 0;
			nElement = LinSearch(&storage, requiredKey);

			if (nElement != -1)
			{
				cout << "Значение " << requiredKey << " находится в ячейке с индексом: " << nElement << endl;
				cout << endl;
			}
			else cout << "В списоке нет такого значения" << endl;
			system("pause");
			Output(&storage);*/
			break;
		}

		//выход из программы
		case 0:
		{
			//удаление динамического списка
			return -1;
			break;
		}

		}
	}

	return 0;
}