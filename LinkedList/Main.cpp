#include "List.h"

void main()
{
	List<int> list = List<int>();

    //Testing push front function
    std::cout << "Testing pushFront Function: " << std::endl;
	list.pushFront(1);
	list.pushFront(2);
	list.pushFront(3);
    list.print();
    std::cout << "" << std::endl;

    //Tesing push back function
    std::cout << "Testing pushBack Function: " << std::endl;
	list.pushBack(6);
    list.pushBack(11);
    list.print();
    std::cout << "" << std::endl;

    //Testing insert function
    std::cout << "Testing insert Function" << std::endl;
    list.insert(10, 2);
    list.print();
    std::cout << "" << std::endl;
    
    //Testing contains function
    std::cout << "Testing contains Function: " << std::endl;
    if (list.contains(1))
        std::cout << "Cantains 1" << std::endl;
    std::cout << "" << std::endl;

    //Testing remove function
    std::cout << "Testing remove Function: " << std::endl;
    list.remove(6);
    list.remove(1);
    list.print();
    std::cout << "" << std::endl;

    //Testing the sort function
    std::cout << "Testing the sort Function: " << std::endl;
	list.sort();
	list.print();
    std::cout << "" << std::endl;

    //Testing the equals operator
    std::cout << "Testing the Equals Operator Function: " << std::endl;
	List<int> list1 = List<int>();

	list1 = list;
	list1.print();
    std::cout << "" << std::endl;

    //Testing the destroy function and isEmpty function
    std::cout << "Testing the destroy and isEmpty Function: " << std::endl;
    list1.destroy();
    if (list1.isEmpty())
        std::cout << "List is empty" << std::endl;
}