#pragma once
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