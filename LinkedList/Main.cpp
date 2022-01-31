#include "List.h"

void main()
{
	List<int> list = List<int>();

	list.pushFront(1);
	list.pushFront(2);
	list.pushFront(3);
	list.pushFront(5);
	list.insert(4, 3);
	list.pushBack(6);

	list.print();
}