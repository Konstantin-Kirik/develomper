#pragma once
#include <iostream>

struct Element 
{
	int value;
	Element* next;
};

class List 
{
	Element* head;
	Element* tail;
	int count;
public:
	List();
	~List();
	void Add(int); 
	void Insert(int, int);
	void Del(); 
	void Del(int);
	void Show();
	int GetCount();
	int Find(int);
};

