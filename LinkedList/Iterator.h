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
	/// <returns>If teh current node is equal to the interator</returns>
	const bool operator ==(const Iterator<T>& iter);

	/// <param name="iter">The iterator to compare</param>
	/// <returns>If the current node is not equal to the intertor</returns>
	const bool operator != (const Iterator<T>& iter);

	/// <summary>
	/// 
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
		return m_current;
	else
		return m_current->next;
}

template<typename T>
Iterator<T> Iterator<T>::operator--()
{
	if (m_current->previous = nullptr)
		return m_current;
	else
		return m_current->previous;
}

template<typename T>
const bool Iterator<T>::operator==(const Iterator<T>& iter)
{
	return m_current->data == iter.m_current->data &&
		m_current->next == iter.m_current->next &&
		m_current->previous == iter.m_current;
}

template<typename T>
inline const bool Iterator<T>::operator!=(const Iterator<T>& iter)
{
	return m_current->data != iter.m_current->data &&
		m_current->next != iter.m_current->next &&
		m_current->previous != iter.m_current->next;
}

template<typename T>
inline T Iterator<T>::operator*()
{
	return T();
}
