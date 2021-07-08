#pragma once
template <typename T>
class Node {
public :
	T data;
	Node* next;

	Node();
	Node(T val);
	~Node();
};

template <typename T>
Node<T>::Node() {
	next = nullptr;
}

template <typename T>
Node<T>::~Node() {
	delete next;
}

template <typename T>
Node<T>::Node(T val) {
	data = val;
	next = nullptr;
}
