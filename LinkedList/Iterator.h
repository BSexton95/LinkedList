#pragma once
#include "Node.h"

template<typename T>
class Iterator
{
public:
	/// <summary>
	/// Constructor for the iterator
	/// </summary>
	Iterator();

	/// <summary>
	/// Constructor for the iterator that holds a node for an argument
	/// </summary>
	/// <param name="node">The current node</param>
	Iterator(Node<T>* node);

	/// <summary>
	/// Sets the current node to its next node
	/// </summary>
	/// <returns>The next node</returns>
	Iterator<T> operator++();

	/// <summary>
	/// Sets the current node to its previous node
	/// </summary>
	/// <returns>The previous node</returns>
	Iterator<T> operator--();

	/// <param name="iter">The iterator to compare</param>
	/// <returns>If two lists are equal</returns>
	const bool operator ==(const Iterator<T>& iter);

	/// <param name="iter">The iterator to compare</param>
	/// <returns>two list are not equal</returns>
	const bool operator != (const Iterator<T>& iter);

	/// <summary>
	/// Returns returns the data the node is pointing at
	/// </summary>
	/// <returns></returns>
	T operator*();

private:
	Node<T>* m_current;
};

template<typename T>
Iterator<T>::Iterator()
{
	m_current = nullptr;
}

template<typename T>
Iterator<T>::Iterator(Node<T>* node)
{
	m_current = node;
}

template<typename T>
Iterator<T> Iterator<T>::operator++()
{
	if (m_current->next == nullptr)
		return Iterator<T>(m_current);
	else
		return Iterator<T>(m_current->next);
}

template<typename T>
Iterator<T> Iterator<T>::operator--()
{
	if (m_current->previous = nullptr)
		return Iterator<T>(m_current);
	else
		return Iterator<T>(m_current->previous);
}

template<typename T>
const bool Iterator<T>::operator==(const Iterator<T>& iter)
{
	//If the iteraters current node is null...
	if (iter.m_current == nullptr)
		//...exit the function and return false
		return false;

	//Returns if the current nodes data, next node, and previous node are equal
	return m_current->data == iter.m_current->data &&
		m_current->next == iter.m_current->next &&
		m_current->previous == iter.m_current;
}

template<typename T>
inline const bool Iterator<T>::operator!=(const Iterator<T>& iter)
{
	//If the iteraters current is null...
	if (iter.m_current == nullptr)
		//...exit function and return false
		return false;

	//Returns if the current nodes data, next node, and previous node are not equal
	return m_current->data != iter.m_current->data &&
		m_current->next != iter.m_current->next &&
		m_current->previous != iter.m_current->next;
}

template<typename T>
inline T Iterator<T>::operator*()
{
	return m_current->data;
}
