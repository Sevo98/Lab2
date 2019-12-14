#include "pch.h"
#include "List.h"
#include <iostream>

using namespace std;


List::List()
{
	Head = nullptr;
	Tail = nullptr;
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
		Node* temp = Head;
		Head = new Node(data, Head);
		temp->PPrev = Head;
	}
	else if (Size == 1)
	{
		Head = new Node(data, Head);
		Tail->PPrev = this->Head;
	}
	else
	{
		Head = Tail = new Node(data, Head, Tail);
	}
	Size++;
}

void List::PushBack(int Data)
{
	if (Size > 1)
	{
		Node* temp = Tail;
		Tail = new Node(Data, nullptr, Tail);
		temp->PNext = Tail;
	}
	else if (Size == 1)
	{
		Tail = new Node(Data, nullptr, Tail);
		Head->PNext = this->Tail;
	}
	else
	{
		Head = Tail = new Node(Data, Head, Tail);
	}
	Size++;
}

void List::PopFront()
{
	if (Size > 1)
	{
		Node* temp = Head;
		Head = Head->PNext;
		delete temp;
	}
	else if (Size == 1)
	{
		Node* temp = Head;
		Tail = Head = Head->PNext;
		delete temp;
	}

	Size--;
}

void List::PopBack()
{
	if (Size > 1)
	{
		Node* temp = Tail;
		Tail = Tail->PPrev;
		delete temp;
	}
	else if (Size == 1)
	{
		Node* temp = Tail;
		Tail = Head = Tail->PPrev;
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
		Node* previous = this->Head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->PNext;
		}

		Node* newNode = new Node(data, previous->PNext, previous);

		previous->PNext = newNode;
		Node* next = newNode->PNext;
		next->PPrev = newNode;

		Size++;
	}

	else if (index > Size / 2)
	{
		Node* next = this->Tail;
		for (int i = Size - 1; index < i; i--)
		{
			next = next->PPrev;
		}

		Node* newNode = new Node(data, next, next->PPrev);

		next->PPrev = newNode;
		Node* previous = newNode->PPrev;
		previous->PNext = newNode;

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
		Node* previous = this->Head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->PNext;
		}

		Node* toDelete = previous->PNext;
		previous->PNext = toDelete->PNext;
		Node* next = toDelete->PNext;
		delete toDelete;
		next->PPrev = previous;

		Size--;
	}

	else if (index > Size / 2)
	{
		Node* next = this->Tail;
		for (int i = Size - 1; index < i; i--)
		{
			next = next->PPrev;
		}

		Node* toDelete = next->PPrev;
		next->PPrev = toDelete->PPrev;
		Node* previous = toDelete->PPrev;
		delete toDelete;
		previous->PNext = next;

		Size--;
	}
}

int& List::operator[] (const int index)
{
	if (index <= Size / 2)
	{
		int counter = 0;
		Node* current = this->Head;

		while (current != nullptr)
		{
			if (counter == index) return current->Data;
			current = current->PNext;
			counter++;
		}
	}
	else
	{
		int counter = Size - 1;
		Node* current = this->Tail;

		while (current != nullptr)
		{
			if (counter == index) return current->Data;
			current = current->PPrev;
			counter--;
		}
	}
}

void List::PrintFromHead()
{
	Node* print = Head;
	while (print)
	{
		cout << print->Data << endl;
		print = print->PNext;
	}
	cout << endl;
}

void List::PrintFromTail()
{
	Node* print = Tail;
	while (print)
	{
		cout << print->Data << endl;
		print = print->PPrev;
	}
	cout << endl;
}

bool List::LinSearch(int* tempCounter, int value)
{
	Node* current = Head;
	while (current != nullptr)
	{
		(*tempCounter)++;
		if (current->Data == value)
		{
			return true;
		}
		current = current->PNext;
	}
	return false;
}

void List::SwapData(Node* current, Node* nextCurrent)
{
	if (nextCurrent->PNext != nullptr)
	{
		nextCurrent->PNext->PPrev = current;
	}
	if (current->PPrev != nullptr)
	{
		current->PPrev->PNext = nextCurrent;
	}
	nextCurrent->PPrev = current->PPrev;
	current->PNext = nextCurrent->PNext;
	nextCurrent->PNext = current;
	current->PPrev = nextCurrent;

}

void List::Output()
{
	cout << "«начени€ элементов списка" << endl;
	if (Size != 0)
	{
		Node* temp = Head;
		int index = 0;
		while (temp->PNext != nullptr)
		{
			cout << temp->Data << " - индекс " << index << endl;
			temp = temp->PNext;
			index++;
		}
		cout << temp->Data << " - индекс " << index << endl;
	}

}


void List::InsertingSort()
{
	Node* current = Head;
	Node* nextCurrent = current->PNext;
	Node* saveCurrent = new Node;
	saveCurrent = current;
	while (nextCurrent != nullptr)
	{
		if (current->Data > nextCurrent->Data)
		{
			SwapData(current, nextCurrent);
			if (nextCurrent->PPrev == nullptr)
			{
				nextCurrent = current->PNext;
			}
			else
			{
				current = nextCurrent->PPrev;
			}

		}
		else if (current->Data <= nextCurrent->Data)
		{
			current = nextCurrent;
			nextCurrent = nextCurrent->PNext;
			saveCurrent = current;
		}
	}

	Tail = current;
	while (current->PPrev != nullptr)
	{
		current = current->PPrev;
		Head = current;
	}

}