#pragma once
#include "Node.h"
#include <iostream>
using namespace std;

const int Queue_size = 5;
template <typename T>
class Queue
{
public:
	int size;
	Node<T>* data[Queue_size];
	int front;
	int rear;

	Queue();
	~Queue();
	void push(int val);
	void pop();
	bool is_empty();
	bool is_full();
	void print();
};

template <typename T>
Queue<T>::Queue() {
	size = 0;
	front = 0;
	rear = 0;
	for (int i = 0; i < Queue_size; i++) {
		data[i] = nullptr;
	}
}

template <typename T>
Queue<T>::~Queue() {
	for (int i = 0; i < Queue_size; i++) {
		Node<T>* temp = data[i];
		free(temp);
	}
}

template <typename T>
void Queue<T>::push(int val) {
	if (is_full()) {
		cout << "error : Queue is full" << endl;
		return;
	}
	else {
		Node<T>* node = new Node<T>(val);
		if (rear == Queue_size - 1) {
			data[rear] = node;
			rear = 0;
			size++;
		}
		else {
			data[rear] = node;
			rear++;
			size++;
		}
	}
}

template <typename T>
void Queue<T>::pop() {
	if (is_empty()) {
		cout << "error : Queue is empty" << endl;
		return;
	}
	else {
		if (front == Queue_size - 1) {
			free(data[front]);
			data[front] = nullptr;
			front = 0;
			size--;
		}
		else {
			free(data[front]);
			data[front] = nullptr;
			front++;
			size--;
		}
	}
}

template <typename T>
bool Queue<T>::is_empty() {
	return (size == 0);
}

template <typename T>
bool Queue<T>::is_full() {
	return (size == Queue_size);
}

template <typename T>
void Queue<T>::print() {
	if (front < rear) {
		cout << "front <- ";
		for (int i = front; i < rear; i++) {
			cout << data[i]->data << " <- ";
		}
		cout << "rear" << endl;
	}
	else {
		cout << "front <- ";
		for (int i = front; i < Queue_size; i++) {
			cout << data[i]->data << " <- ";
		}
		for (int i = 0; i < rear; i++) {
			cout << data[i]->data << " <- ";
		}
		cout << "rear" << endl;
	}
}
