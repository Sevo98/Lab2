#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
//#include "List.h"

using namespace std;

template <typename T>
class List
{
public:

	//получение количества элементов в списке
	int GetSize() { return Size; }
	//очистка списка
	void clear();
	//добавление элемента в начало списка
	void push_front(T data);
	//добавление элемента в конец списка
	void push_back(T data);
	//удаление первого элемента в списке
	void pop_front();
	//удаление последнего элемента в списке
	void pop_back();
	//добавление элемента в список по указанному индексу
	void insert(T data, int index);
	//удаление последнего элемента в списке
	void removeAt(int index);
	//
	T& operator [] (const int index);
	//вывод списка начиная с "головы"
	void PrintFromHead();
	//вывод списка начиная с "хвоста"
	void PrintFromTail();

	List <T>();
	~List <T>();

private:

	template <typename T>
	class Node
	{
	public:
		Node(T data = T(), Node* pNext = nullptr, Node* pPrev = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
			this->pPrev = pPrev;
		}

		T data;
		Node* pNext;
		Node* pPrev;
	};

	Node <T>* head;
	Node <T>* tail;
	int Size;
};

template <typename T> List <T>::List()
{
	head = nullptr;
	tail = nullptr;
	Size = 0;
}

template <typename T> List <T>::~List()
{
	clear();
}

template<typename T>
void List<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}

template <typename T>
void List <T>::push_front(T data)
{
	if (Size > 1)
	{
		Node <T>* temp = head;
		head = new Node <T>(data, head);
		temp->pPrev = head;
	}
	else if (Size == 1)
	{
		head = new Node <T>(data, head);
		tail->pPrev = this->head;
	}
	else
	{
		head = tail = new Node <T>(data, head, tail);
	}
	Size++;
}

template <typename T>
void List <T>::push_back(T data)
{
	if (Size > 1)
	{
		Node <T>* temp = tail;
		tail = new Node <T>(data, nullptr, tail);
		temp->pNext = tail;
	}
	else if (Size == 1)
	{
		tail = new Node <T>(data, nullptr, tail);
		head->pNext = this->tail;
	}
	else
	{
		head = tail = new Node <T>(data, head, tail);
	}
	Size++;
}

template <typename T>
void List <T>::pop_front()
{
	if (Size > 1)
	{
		Node <T>* temp = head;
		head = head->pNext;
		delete temp;
	}
	else if (Size == 1)
	{
		Node <T>* temp = head;
		tail = head = head->pNext;
		delete temp;
	}

	Size--;
}

template <typename T>
void List <T>::pop_back()
{
	if (Size > 1)
	{
		Node <T>* temp = tail;
		tail = tail->pPrev;
		delete temp;
	}
	else if (Size == 1)
	{
		Node <T>* temp = tail;
		tail = head = tail->pPrev;
		delete temp;
	}

	Size--;
}

template <typename T>
void List <T>::insert(T data, int index)
{
	if (index == 0) push_front(data);

	else if (index == Size || index > Size) push_back(data);
	/*здесь можно реализовать проверку, if(index > Size) то кидать исключение, с сообщением пользователю -
	- что он хочет добавить узел по индексу, до которого список еще не дорос. Либо оставить данную реализацию,
	в которой узел просто добавляется в конец*/

	else if (index <= Size / 2)
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<T>* newNode = new Node<T>(data, previous->pNext, previous);

		previous->pNext = newNode;
		Node<T>* next = newNode->pNext;
		next->pPrev = newNode;

		Size++;
	}

	else if (index > Size / 2)
	{
		Node<T>* next = this->tail;
		for (int i = Size - 1; index < i; i--)
		{
			next = next->pPrev;
		}

		Node<T>* newNode = new Node<T>(data, next, next->pPrev);

		next->pPrev = newNode;
		Node<T>* previous = newNode->pPrev;
		previous->pNext = newNode;

		Size++;
	}
}

template <typename T>
void List <T>::removeAt(int index)
{
	if (index == 0) pop_front();

	else if (index == Size || index > Size) pop_back();
	/*здесь можно реализовать проверку, if(index > Size) то кидать исключение, с сообщением пользователю -
	- что он хочет удалить узел по индексу, которого не существует. Либо оставить данную реализацию,
	в которой просто удаляется последний узел*/

	else if (index <= Size / 2)
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<T>* toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		Node<T>* next = toDelete->pNext;
		delete toDelete;
		next->pPrev = previous;

		Size--;
	}

	else if (index > Size / 2)
	{
		Node<T>* next = this->tail;
		for (int i = Size - 1; index < i; i--)
		{
			next = next->pPrev;
		}

		Node<T>* toDelete = next->pPrev;
		next->pPrev = toDelete->pPrev;
		Node<T>* previous = toDelete->pPrev;
		delete toDelete;
		previous->pNext = next;

		Size--;
	}
}

template <typename T>
T& List <T>::operator[] (const int index)
{
	if (index <= Size / 2)
	{
		int counter = 0;
		Node <T>* current = this->head;

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
		Node <T>* current = this->tail;

		while (current != nullptr)
		{
			if (counter == index) return current->data;
			current = current->pPrev;
			counter--;
		}
	}
}

template <typename T>
void List <T>::PrintFromHead()
{
	cout << "Come the method PrintFromHead:" << endl;
	Node <T>* print = head;
	while (print)
	{
		cout << print->data << endl;
		print = print->pNext;
	}
	cout << endl;
}

template <typename T>
void List <T>::PrintFromTail()
{
	cout << "Come the method PrintFromTail:" << endl;
	Node <T>* print = tail;
	while (print)
	{
		cout << print->data << endl;
		print = print->pPrev;
	}
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "ru");

	List <int> lst;

	cout << "Значение элементов списка: " << endl;

	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}


	return 0;
}