#include "pch.h"
#include "List.h"
#include <iostream>

using namespace std;

//�������� ��������� �����
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
			cout << "����������, ������� ���������� ��������." << endl;
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