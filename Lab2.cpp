#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include "List.h"
#include "Check.h"
#include <chrono>
#include "Node.h"

using namespace std;

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
		lst.PushBack(value);
	}

	system("cls");
	lst.Output();
	int ListSize;
	ListSize = lst.GetSize();

	while (true)
	{
		int number = 0;
		cout << "\n            Введите от 0 до 5: \n" << endl;
		cout << "Для вывода списка введите 1\n" << endl;
		cout << "Для добавления элемента в список введите 2\n" << endl;
		cout << "Для удаление элемента списка введите 3\n" << endl;
		cout << "Для сортировки списка по возрастанию введите 4\n" << endl;
		cout << "Для линейного поиска по элементам в списоке введите 5\n" << endl;
		cout << "Для выхода из программы введите 0\n" << endl;

		number = Check();

		switch (number)
		{
			//вывод списка
		case 1:
		{
			system("cls");
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
				//добавление элемента в начало
			case 1:
			{
				auto start = chrono::high_resolution_clock::now();

				int value;
				cout << "Введите добавляемое значение" << endl;
				value = Check();
				lst.PushFront(value);
				system("cls");
				lst.Output();

				auto end = chrono::high_resolution_clock::now();
				chrono::duration<float> duration = end - start;
				cout << "Время работы программы " << duration.count() << "с" << endl;
			}
			break;
			//добавление элемента в конец
			case 2:
			{
				auto start = chrono::high_resolution_clock::now();

				int value;
				cout << "Введите добавляемое значение" << endl;
				value = Check();
				lst.PushBack(value);
				system("cls");
				lst.Output();

				auto end = chrono::high_resolution_clock::now();
				chrono::duration<float> duration = end - start;
				cout << "Время работы программы " << duration.count() << "с" << endl;
				break;
			}
			//функция добавления элемента после элемента
			case 3:
			{
				auto start = chrono::high_resolution_clock::now();

				int value;
				int index;
				value = 0;
				cout << "Введите добавляемое значение" << endl;
				value = Check();
				cout << "Введите индекс после которого необходимо вставить значение" << endl;
				index = Check();
				index++;
				lst.Insert(value, index);
				system("cls");
				lst.Output();

				auto end = chrono::high_resolution_clock::now();
				chrono::duration<float> duration = end - start;
				cout << "Время работы программы " << duration.count() << "с" << endl;
				break;
			}
			//вставка перед определенным элементом
			case 4:
			{
				auto start = chrono::high_resolution_clock::now();

				int value;
				int index;
				value = 0;
				cout << "Введите добавляемое значение" << endl;
				cin >> value;
				cout << "Введите индекс перед которым необходимо вставить значение" << endl;
				index = Check();
				lst.Insert(value, index);
				system("cls");
				lst.Output();

				auto end = chrono::high_resolution_clock::now();
				chrono::duration<float> duration = end - start;
				cout << "Время работы программы " << duration.count() << "с" << endl;
				break;
			}
			}
			break;
		}

		//удаление элемента из списка
		case 3:
		{
			auto start = chrono::high_resolution_clock::now();

			cout << "Введите индекс удаляемого элемента" << endl;
			int index;
			index = Check();
			if (index == 0)
			{
				lst.PopFront();
			}
			else if (index == lst.GetSize())
			{
				lst.PopBack();
			}
			else
			{
				index++;
				lst.removeAt(index);
			}
			system("cls");
			lst.Output();
			auto end = chrono::high_resolution_clock::now();
			chrono::duration<float> duration = end - start;
			cout << "Время работы программы " << duration.count() << "с" << endl;
			break;
		}
		//сортировка списка
		case 4:
		{
			lst.InsertingSort();
			system("cls");
			lst.Output();
			break;
		}
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