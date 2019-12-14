#pragma once


struct List
{
	struct Node
	{
		//����������� ����
		Node(int data = int(), Node* pNext = nullptr, Node* pPrev = nullptr)
		{
			this->Data = data;
			this->PNext = pNext;
			this->PPrev = pPrev;
		}

		int Data;
		Node* PNext;
		Node* PPrev;
	};

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
	Node* node;
	int Size;
};