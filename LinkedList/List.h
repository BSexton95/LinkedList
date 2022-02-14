#pragma once
#include "Iterator.h"
#include "Node.h"
#include <iostream>

template<typename T>
class List
{
public:
	/// <summary>
	/// Initializes all private veriables to be null
	/// </summary>
	List();

	/// <summary>
	/// Sets a list to have a first and last node and a node count
	/// </summary>
	/// <param name="other">The list to initialize</param>
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

	/// <summary>
	/// Checks to see if the given item is in the list
	/// </summary>
	/// <param name="object">The item to find in the list</param>
	/// <returns>The item in the list</returns>
	bool contains(const T object) const;

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

	/// <summary>
	/// 
	/// </summary>
	/// <param name="otherList"></param>
	/// <returns></returns>
	const List<T>& operator= (const List<T>& otherList);

	void sort();

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
	Node<T>* currentNode = m_first;
	Node<T>* tempNode = m_first;

	for (int i = 0; i < getLength(); i++)
	{
		if (currentNode != nullptr)
		{
			tempNode = currentNode;
			currentNode = currentNode->next;
			delete tempNode;
		}
		initialize();
	}
}

template<typename T>
Iterator<T> List<T>::begin() const
{
	return Iterator<T>(m_first);
}

template<typename T>
Iterator<T> List<T>::end() const
{
	return Iterator<T>(m_last);
}

template<typename T>
bool List<T>::contains(const T object) const
{
	Node<T>* nodeToFind = m_first;

	for (int i = 0; i < getLength(); i++)
	{
		if (nodeToFind->data == object)
		{
			std::cout << "Node found" << std::endl;
			return true;
		}
		else
		{
			nodeToFind = nodeToFind->next;
		}
	}
	return false;
}

template<typename T>
void List<T>::pushFront(const T& value)
{
	//Create new node
	Node<T>* nodeInserted = new Node<T>(value);

	//If fist node in the list is not null...
	if (m_first != nullptr)
		//...Set the new nodes next to be the previous fist in the list
		nodeInserted->next = m_first;
	

	//Set the first node in the list to be the new node
	m_first = nodeInserted;

	//If the new nodes next is not null...
	if (nodeInserted->next != nullptr)
		//...set the new nodes nexts previous to be the new node
		nodeInserted->next->previous = nodeInserted;
	//Otherwise
	else
		//set the last node in the list to be the new node
		m_last = nodeInserted;

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
	bool nodeInserted = false;

	//Create new node
	Node<T>* newNode = new Node<T>(value);
	//Set a current node to be the first in the list
	Node<T>* currentNode = m_first;

	if (index == 0)
	{
		pushFront(value);
		return true;

	}

	if (index == getLength())
	{
		pushBack(value);
		return true;
	}

	//Interate through the list until it reaches the index to be inserted
	for (int i = 0; i < index; i++)
	{
		//Sets the current not to be the next node in the list
		currentNode = currentNode->next;
	}

	//If the current node is not null...
	if (currentNode != nullptr)
	{
		//...set the new nodes previous to be the current nodes previous
		newNode->previous = currentNode->previous;

		//If the current nodes previous is null...
		if (currentNode->previous != nullptr)
		{
			//...set the current nodes previouses next to be the new node to be inserted
			currentNode->previous->next = newNode;
		}

		//set the current nodes previous to be the new node
		currentNode->previous = newNode;
	}

	//Set the new nodes next to the current node
	newNode->next = currentNode;
	//Set the new nodes previous to teh current nodes previous
	newNode->previous = currentNode->previous;
	//Set the current nodes previous to the new node
	currentNode->previous = newNode;

	//return if the node was inserted
	return nodeInserted;
}

template<typename T>
bool List<T>::remove(const T& value)
{
	
	bool nodeRemoved = false;

	//Create a new node that is set to the first node in the list
	Node<T>* currentNode = m_first;

	//Iterate through the list
	for (int i = 0; i < getLength(); i++)
	{
		//If the data in the current node is equal to the value that should be removed...
		if (currentNode->data == value)
		{
			if (currentNode->previous == nullptr)
				m_first = currentNode->next;
			else if (currentNode->next == nullptr)
				m_last = currentNode->previous;
			else
			{
				//...set the current nodes nexts previous to be teh current nodes previous
				currentNode->next->previous = currentNode->previous;
				//set the current nodes previouses next to be the current nodes next
				currentNode->previous->next = currentNode->next;
			}
			
			//Decrement the node count
			m_nodeCount--;
			//delete the current node
			delete currentNode;
			//set node removed to be true
			nodeRemoved = true;
			break;
		}
		//Otherwise continue through the list
		else
		{
			currentNode = currentNode->next;
		}
	}

	//Return if the node removed was true or false
	return nodeRemoved;
}

template<typename T>
void List<T>::print() const
{
	//Create a current node, set it to be the fist node in the list
	Node<T>* currentNode = m_first;
	
	//While current node is not null...
	for (int i = 0; i < getLength(); i++)
	{
		//...print the nodes data to console
		std::cout << currentNode->data << std::endl;
		currentNode = currentNode->next;
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
	if (m_first == nullptr && m_last == nullptr && m_nodeCount == 0)
		return true;
	else
		return false;
}

template<typename T>
bool List<T>::getData(Iterator<T>& iter, int index)
{
	if (index <= 0 || index > getLength())
		return false;

	iter = begin();

	for (int i = 0; i < index; i++)
	{
		++iter;
	}

	return true;
}

template<typename T>
const List<T>& List<T>::operator=(const List<T>& otherList)
{
	destroy();
	Node<T>* newNode = otherList.m_first;

	for (int i = 0; i < otherList.getLength(); i++)
	{
		insert(newNode->data, i);
		newNode = newNode->next;
	}

	return *this;
}

template<typename T>
void List<T>::sort()
{
	Node<T>* newNode = new Node<T>();
	Node<T>* currentNode = m_first;

	for (int i = 0; i < m_nodeCount - 1; i++)
	{
		currentNode = m_first;

		for (int j = 0; j < m_nodeCount - 1; j++)
		{ 
			if (currentNode->next->data < currentNode->data)
			{
				newNode->data = currentNode->next->data;
				currentNode->next->data = currentNode->data;
				currentNode->data = newNode->data;
			}
			currentNode = currentNode->next;
		}
	}
}
