#include "pch.h"
#include "List.h"
#include <iostream>

using namespace std;

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