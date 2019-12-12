#include "pch.h"
#include "List.h"
#include <iostream>

using namespace std;


List::List()
{
	head = nullptr;
	tail = nullptr;
	Size = 0;
}

List::~List()
{
	Clear();
}


void List::Clear()
{
	while (Size)
	{
		PopFront();
	}
}

void List::PushFront(int data)
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

void List::PushBack(int data)
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

void List::PopFront()
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

void List::PopBack()
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

void List::Insert(int data, int index)
{
	if (index == 0) PushFront(data);
	else if (index > Size)
	{
		cout << "¬ведите правильный индекс" << endl;
		system("pause");
	}

	else if (index == Size || index > Size) PushBack(data);

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
	if (index == 0) PopFront();
	else if (index > Size)
	{
		cout << "¬ведите правильный индекс" << endl;
		system("pause");
	}

	else if (index == Size) PopBack();

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
	cout << "«начени€ элементов списка" << endl;
	if (Size != 0)
	{
		Node* temp = head;
		int index = 0;
		while (temp->pNext != nullptr)
		{
			cout << temp->data << " - индекс " << index << endl;
			temp = temp->pNext;
			index++;
		}
		cout << temp->data << " - индекс " << index << endl;
	}
	
}


void List::InsertingSort()
{
	Node* current = head;
	Node* nextCurrent = current->pNext;
	Node* saveCurrent = new Node;
	saveCurrent = current;
	while (nextCurrent != nullptr)
	{
		if (current->data > nextCurrent->data)
		{
			SwapData(current, nextCurrent);
			if (nextCurrent->pPrev == nullptr)
			{
				nextCurrent = current->pNext;
			}
			else
			{
				current = nextCurrent->pPrev;
			}

		}
		else if (current->data <= nextCurrent->data)
		{
			current = nextCurrent;
			nextCurrent = nextCurrent->pNext;
			saveCurrent = current;
		}
	}

	tail = current;
	while (current->pPrev != nullptr)
	{
		current = current->pPrev;
		head = current;
	}

}