#include <iostream>
template <typename T>
struct Element
{
	T value;
	Element* next;
	Element* prev;
};

template <typename T>
class Queue
{
	Element  <T>* head;
	Element  <T>* tail;
public:
	Queue();
	~Queue();
	void Add(T);
	T Exctract();
	void Del();
	void Show();
};

template <typename T>
Queue<T>::Queue()
{
	head = tail = NULL;
}

template <typename T>
Queue<T>::~Queue()
{
	Del();
}

template <typename T>
void Queue <T>::Add(T value)
{
	if (head)
	{
		tail->next = new Element <T>;
		tail->next->value = value;
		tail->next->next = NULL;
		tail->next->prev = tail;
		tail = tail->next;
	}
	else
	{
		head = new Element  <T>;
		head->value = value;
		head->prev = head->next = NULL;
		tail = head;
	}
}

template <typename T>
T Queue <T>::Exctract()
{
	if (tail)
	{
		if (tail->prev)
		{
			T exctract = tail->value;
			tail = tail->prev;
			delete tail->next;
			tail->next = NULL;
			return exctract;
		}
		else
		{
			T exctract = tail->value;
			delete tail;
			tail = head = NULL;
			return exctract;
		}
	}
	else
	{
		std::cout << "Queue is no" << std::endl;
		return 0;
	}
}


template <typename T>
void Queue <T>::Del()
{
	while (head)
	{
		if (head->next)
		{
			head = head->next;
			delete head->prev;
			head->prev = NULL;
		}
		else
		{
			delete head;
			head = tail = NULL;
		}
	}
}

template <typename T>
void Queue <T>::Show()
{
	if (head)
	{
		Element  <T>* temp = head;
		while (temp)
		{
			std::cout << temp->value << " ";
			temp = temp->next;
		}
		std::cout << std::endl;
	}
	else
	{
		std::cout << "No Elements" << std::endl;
	}
}

void main()
{
	Queue<int> A;
	for (int i = 1; i < 6; i++)
	{
		A.Add(i);
		A.Show();
	}
	A.Exctract();
	A.Show();

}



