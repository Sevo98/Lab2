#pragma once
#include "Node.h"

struct List
{


	//��������� ���������� ��������� � ������
	int GetSize() { return Size; }
	//������� ������
	void Clear();
	//���������� �������� � ������ ������
	void PushFront(int data);
	//���������� �������� � ����� ������
	void PushBack(int data);
	//�������� ������� �������� � ������
	void PopFront();
	//�������� ���������� �������� � ������
	void PopBack();
	//���������� �������� � ������ �� ���������� �������
	void Insert(int data, int index);
	//�������� �������� � ������ �� ���������� �������
	void removeAt(int index);
	//������������ �������� [], ������� ���������� ������ �� ������ �� �������
	int& operator [] (const int index);
	//����� ������ ������� � "������"
	void PrintFromHead();
	//����� ������ ������� � "������"
	void PrintFromTail();
	//�������� �����
	bool LinSearch(int* tempCounter, int value);
	//����������
	void InsertingSort();
	//����� ������
	void SwapData(Node* current, Node* nextCurrent);
	//����� ������
	void Output();

	List();
	~List();

	Node* Head;
	Node* Tail;
	int Size;
};