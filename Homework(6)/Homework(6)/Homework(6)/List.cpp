#include "List.h"
List::List()
{
	count = 0;  
	head = tail = NULL;
}
List::~List()
{
	Del();
}
void List::Add(int value)
{
	if (head) 
	{
		tail->next = new Element;
		tail = tail->next;
	}
	else
	{
		head = tail = new Element;
	}
	tail->value = value;
	tail->next = NULL;
	count++;
}

void List::Insert(int value, int pos)
{
	if (pos < 1 || pos > count + 1) 
	{ 
		std::cout << "Outside" << std::endl;
	}
	else 
	{
		if (pos == 1) 
		{
			Element* tmp = head;
			head = new Element;
			head->value = value;
			head->next = tmp;
			count++;
		}
		else	if (pos > 1 && pos <= count)
		{
			Element* preMove = head;
			for (int i = 1; i < pos - 1; ++i) 
			{ 
				preMove = preMove->next; 
			}
			Element* Insert = new Element; 
			Insert->value = value; 
			Insert->next = preMove->next; 
			preMove->next = Insert;
			count++;
		}
		else if (pos == count + 1) 
		{
			Add(value);
		}
	}
}

void List::Del() 
{
	Element* tmp = head;
	head = head->next;
	delete tmp;
	count--;
}

void List::Del(int pos)
{
	if (pos < 1 || pos > count) 
	{
		std::cout << "Outside" << std::endl;
	}
	else {
		if (pos == 1)
		{
			Del();
		}
		else if (pos > 1 && pos < count)
		{
			Element* preDel = head;
			for (int i = 1; i < pos - 1; ++i)
			{
				preDel = preDel->next;
			}
			Element* deliting = preDel->next; 
			count--;
		}
		else if (pos == count)
		{
			Element* preLast = head;
			for (int i = 1; i < pos - 1; ++i) 
			{
				preLast = preLast->next;
			}
			tail = preLast;
			tail->next = NULL;
			count--;
		}

	}
}

void List::Show() 
{
	Element* tmp = head;
	while (tmp)
	{
		std::cout << tmp->value << " ";
		tmp = tmp->next;
	}
	std::cout << std::endl;
}

int List::GetCount() 
{
	return count;
}

int List::Find(int elem) 
{ 
	int pos = 1;
	Element* find = head;
	for (int pos = 1; pos <= count; ++pos) 
	{
		if (find->value == elem)
		{
			return pos;
		}
		else
			find = find->next;
	}
	return NULL;
}