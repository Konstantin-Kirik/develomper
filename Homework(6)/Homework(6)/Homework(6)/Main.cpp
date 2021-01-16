#include "List.h"
void main()
{
	List list;
	list.Add(20);
	list.Add(40);
	list.Add(20);
	list.Add(100);
	list.Insert(60, 1);
	list.Show();
	list.Del(1);
	list.Show();
	std::cout << list.Find(60) << std::endl;
}