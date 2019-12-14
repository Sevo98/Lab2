#pragma once


struct List
{
	struct Node
	{
		//конструктор узла
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

	//получение количества элементов в списке
	int GetSize() { return Size; }
	//очистка списка
	void Clear();
	//добавление элемента в начало списка
	void PushFront(int data);
	//добавление элемента в конец списка
	void PushBack(int data);
	//удаление первого элемента в списке
	void PopFront();
	//удаление последнего элемента в списке
	void PopBack();
	//добавление элемента в список по указанному индексу
	void Insert(int data, int index);
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
	//Обмен данных
	void SwapData(Node* current, Node* nextCurrent);
	//вывод списка
	void Output();

	List();
	~List();

	Node* Head;
	Node* Tail;
	Node* node;
	int Size;
};