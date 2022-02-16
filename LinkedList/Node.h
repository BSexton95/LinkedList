#pragma once

template<typename T>
class Node
{
public:
	/// <summary>
	/// Constructor of a node. Initializes the next and previous node to be null.
	/// </summary>
	Node();

	/// <summary>
	/// Constructor of a node that holds a value
	/// </summary>
	/// <param name="value">The value of the node</param>
	Node(T value);

	/// <summary>
	/// The next node in the list 
	/// </summary>
	Node<T>* next;

	/// <summary>
	/// The previous node in the list
	/// </summary>
	Node<T>* previous;

	/// <summary>
	/// the value the node holds
	/// </summary>
	T data;
};

template<typename T>
inline Node<T>::Node()
{
	next = nullptr;
	previous = nullptr;
}

template<typename T>
inline Node<T>::Node(T value)
{
	data = value;
}
