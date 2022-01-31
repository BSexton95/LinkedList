#pragma once
#include "Iterator.h"
#include "Node.h"
#include <iostream>

template<typename T>
class List
{
public:
	List();
	List(const List<T>& other);
	~List() {};

	/// <summary>
	/// Deletes all nodes in the list
	/// </summary>
	void destroy();

	/// <returns>Retruns an iterator pointing to the first node in the list</returns>
	Iterator<T> begin() const;

	/// <summary>
	/// 
	/// </summary>
	/// <returns>Returns the nex item after the last node in the list</returns>
	Iterator<T> end() const;

	/*/// <summary>
	/// Checks to see if the given item is in the list
	/// </summary>
	/// <param name="object">The item to find in the list</param>
	/// <returns>The item in the list</returns>
	bool contains(const T object) const;*/

	/// <summary>
	/// Adds a new node to the beginning of the list
	/// </summary>
	/// <param name="object">The new node to add at the beginning</param>
	void pushFront(const T& object);

	/// <summary>
	/// Adds a new node to the end of the list
	/// </summary>
	/// <param name="value">The new node to add at the end</param>
	void pushBack(const T& value);

	/// <summary>
	/// Adds a new node at the given index
	/// </summary>
	/// <param name="value">The new node to insert</param>
	/// <param name="index">Where the node will be inserted</param>
	/// <returns></returns>
	bool insert(const T& value, int index);

	/// <summary>
	/// Remove all nodes with the given value
	/// </summary>
	/// <param name="value">The value the node, that needs to be removed, has</param>
	/// <returns></returns>
	bool remove(const T& value);

	/// <summary>
	/// Prints the values for all the nodes
	/// </summary>
	void print() const;

	/// <summary>
	/// Set the default values for the first node pointer, 
	/// the last node pointer, and the node count
	/// </summary>
	void initialize();

	/// <returns>Whether or not the list has any nodes in it</returns>
	bool isEmpty() const;

	/// <summary>
	/// Sets the given iterator to point to a node at the given index
	/// </summary>
	/// <param name="iter">The iterator</param>
	/// <param name="index">The index the iterator will point at</param>
	/// <returns></returns>
	bool getData(Iterator<T>& iter, int index);

	/// <returns>The amount of nodes in the list</returns>
	int getLength() const { return m_nodeCount; }

	/*const List<T>& operator= (constList<T>& otherList);*/

	//void sort();

private:
	Node<T>* m_first;
	Node<T>* m_last;
	int m_nodeCount;
};

template<typename T>
List<T>::List()
{
	m_first = nullptr;
	m_last = nullptr;
	m_nodeCount = 0;
}

template<typename T>
List<T>::List(const List<T>& other)
{
	m_first = other.m_first;
	m_last = other.m_last;
	m_nodeCount = other.m_nodeCount;
	
}

template<typename T>
void List<T>::destroy()
{

}

template<typename T>
Iterator<T> List<T>::begin() const
{
	return m_first;
}

template<typename T>
Iterator<T> List<T>::end() const
{
	return m_last;
}

//template<typename T>
//bool List<T>::contains(const T object) const
//{
//	for (Iterator<T> iter = begin(); iter != end(); iter++)
//	{
//		if (iter == object)
//		{
//			/*std::cout << "Node found" << std::endl;*/
//			return true;
//		}
//	}
//	return false;
//}

template<typename T>
void List<T>::pushFront(const T& value)
{
	//Create new node
	Node<T>* nodeInserted = new Node<T>(value);

	//If fist node in the list is not null...
	if (m_first != nullptr)
	{
		//...Set the new nodes next to be the previous fist in the list
		nodeInserted->next = m_first;
	}

	//Set the first node in the list to be the new node
	m_first = nodeInserted;

	//If the new nodes next is not null...
	if (nodeInserted->next != nullptr)
	{
		//...set the new nodes nexts previous to be the new node
		nodeInserted->next->previous = nodeInserted;
	}
	//Otherwise
	else
	{
		//set the last node in the list to be the new node
		m_last = nodeInserted;
	}

	//Increment the node count
	m_nodeCount++;
}

template<typename T>
void List<T>::pushBack(const T& value)
{
	//Create new node
	Node<T>* nodeInserted = new Node<T>(value);

	//If the last node in the list is not null...
	if (m_last != nullptr)
		//...set the new nodes previous to be the last
		nodeInserted->previous = m_last;

	//Set the last node in the node to be the new node
	m_last = nodeInserted;

	//If the new nodes previous is not null
	if (nodeInserted->previous != nullptr)
		//...set the new nodes previouses next to be the new node
		nodeInserted->previous->next = nodeInserted;
	//Otherwise
	else
		//Set the first node in the list to be the new node
		m_first = nodeInserted;

	//Increment the node count
	m_nodeCount++;
}

template<typename T>
bool List<T>::insert(const T& value, int index)
{
	////Iterate through linked list
	//for (Iterator<T> iter = begin(); iter == index; iter++)
	//{
	//	//Create new node
	//	Node<T> newNode = new Node<T>;
	//	newNode.data = value;
	//	newNode.next = iter.m_current->previous;

	//	//if the current node is not null...
	//	if (iter.m_current != nullptr)
	//	{
	//		//...set the new nodes previous to be the current nodes previous
	//		newNode.previous = iter.m_current->previous;

	//		//if the current nodes previous is null...
	//		if (iter.m_current->previous != nullptr)
	//		{
	//			//...set the current nodes previouses next to be the new node
	//			iter.m_current->previous->next = newNode;
	//		}

	//		//set the current nodes previous to be the new node
	//		iter.m_current->previous = newNode;
	//	}

	//	if (m_first == iter.m_current)
	//		m_first = newNode;

	//	if (m_last->next == nullptr)
	//		m_last = newNode;

	//}

	bool nodeInserted = false;

	//Create new node
	Node<T>* newNode = new Node<T>(value);
	Node<T>* currentNode = m_first;

	for (int i = 0; i < index; i++)
	{
		currentNode = currentNode->next;
	}

	newNode->next = currentNode;
	newNode->previous = currentNode->previous;
	currentNode->previous = newNode;

	return nodeInserted;
}

template<typename T>
bool List<T>::remove(const T& value)
{
	bool nodeRemoved = false;

	Node<T>* currentNode = m_first;


	if (currentNode != nullptr && currentNode->data == value)
	{
		currentNode = currentNode->next;
		nodeRemoved = true;
	}

	/*for (Iterator<T> iter = begin(); iter != value->next; iter++)
	{
		iter.m_current->next = value.next;
		value.next.previous = iter.m_current;
	}*/

	return false;
}

template<typename T>
void List<T>::print() const
{
	Node<T>* current;

	current = m_first;

	while (current != nullptr)
	{
		std::cout << current->data << std::endl;
		current = current->next;
	}
}

template<typename T>
void List<T>::initialize()
{
	m_first = nullptr;
	m_last = nullptr;
	m_nodeCount = 0;
}

template<typename T>
bool List<T>::isEmpty() const
{
	return false;
}

template<typename T>
bool List<T>::getData(Iterator<T>& iter, int index)
{
	return false;
}

//template<typename T>
//const List<T>& List<T>::operator=(const List<T>& otherList)
//{
//	// TODO: insert return statement here
//}

//template<typename T>
//void List<T>::sort()
//{
//	for (int i = 1; i < m_nodeCount; i++)
//	{
//		for (int j = 0; j < m_nodeCount; j++)
//		{
//			T tempslot = begin();
//
//			if ()
//		}
//	}
//}
