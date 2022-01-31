#pragma once
#include "Node.h"

template<typename T>
class Iterator
{
public:
	Iterator();
	Iterator(Node<T>* node);
	Iterator<T> operator++();
	Iterator<T> operator--();
	const bool operator ==(const Iterator<T>& iter);
	const bool operator != (const Iterator<T>& iter);
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
