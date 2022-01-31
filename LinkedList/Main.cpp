#include "List.h"

void main()
{
	List<int> list = List<int>();

	list.pushFront(1);
	list.pushFront(2);
	list.pushFront(3);
	list.pushFront(5);
	list.pushBack(6);/*
	list.pushFront(10);
	list.print();
	list.insert(15, 3);
	list.print();*/
	list.remove(1);
	list.remove(2);
	list.print();
}