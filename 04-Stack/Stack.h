#pragma once
#include "Node.h"
#include <iostream>
using namespace std;

const int Stack_size = 5;
template <typename T>
class Stack
{
public :
	int size;
	int top;
	Node<T>* data[Stack_size];

	Stack();
	~Stack();
	void push(int val);
	void pop();
	bool is_empty();
	bool is_full();
	void print();
};

template <typename T>
Stack<T>::Stack() {
	size = 0;
	top = -1;
	for (int i = 0; i < Stack_size; i++) {
		data[i] = nullptr;
	}
}

template <typename T>
Stack<T>::~Stack() {
	for (int i = 0; i < Stack_size; i++) {
		Node<T>* temp = data[i];
		free(temp);
		data[i] = nullptr;
	}
}

template <typename T>
void Stack<T>::push(int val) {
	if (is_full()) {
		cout << "error : Stack is full" << endl;
		return;
	}
	else {
		Node<T>* node = new Node<T>(val);
		top++;
		data[top] = node;
		size++;
	}
}

template <typename T>
void Stack<T>::pop() {
	if (is_empty()) {
		cout << "error : Stack is empty" << endl;
		return;
	}
	else {
		free(data[top]);
		data[top] = nullptr;
		top--;
		size--;
	}
}

template <typename T>
bool Stack<T>::is_empty() {
	return (size == 0);
}

template <typename T>
bool Stack<T>::is_full() {
	return (size == Stack_size);
}

template <typename T>
void Stack<T>::print() {
	cout << "bottom -> ";
	for (int i = 0; i < size; i++) {
		cout << data[i]->data << " -> ";
	}
	cout << "top" << endl;
}
