#pragma once
#include "Node.h"
#include <iostream>
using namespace std;

template <typename T>
class LinkedList
{
public : 
	Node<T>* head;
	int size;

	LinkedList();
	~LinkedList();
	void insert(T data);
	void delete_index(int idx);
	int find(T data);
	void print();
};

template <typename T>
 LinkedList<T>::LinkedList() {
	 head = nullptr;
	 size = 0;
}

 template <typename T>
 LinkedList<T>::~LinkedList() {
	 Node<T>* temp1 = head;
	 while (temp1 != nullptr) {
		 Node<T>* temp2 = temp1;
		 temp1 = temp1->next;
		 free(temp2);
		 temp2 = nullptr;
	 }
	 free(temp1);
	 temp1 = nullptr;
 }

 template <typename T>
void LinkedList<T>::insert(T data) {
	Node<T>* node = new Node<T>(data);
	Node<T>* ptr = head;
	if (ptr == nullptr) head = node;
	else {
		while (ptr->next != nullptr) {
			ptr = ptr->next;
		}
		ptr->next = node;
	}
	size++;
}

template <typename T>
void LinkedList<T>::delete_index(int idx) {
	Node<T>* ptr = head;
	if (idx == 0) {
		head = ptr->next;
		delete ptr;
		size--;
	}
	else if (idx >= 0 && idx < size) {
		for (int i = 1; i < idx; i++) {
			ptr = ptr->next;
		}
		Node<T>* temp = ptr->next;
		ptr->next = temp->next;
		temp->next = nullptr;
		delete temp;
		size--;
	}
	else {
		cout << "error : index is more than size" << endl;
	}
}

template <typename T>
int LinkedList<T>::find(T data) {
	Node<T>* ptr = head;
	int cnt = 0;
	while (ptr != nullptr) {
		if (ptr->data == data) return cnt;
		ptr = ptr->next;
		cnt++;
	}
	return -1;
}

template <typename T>
void LinkedList<T>::print() {
	Node<T>* ptr = head;
	while (ptr != nullptr) {
		cout << ptr->data << " -> ";
		ptr = ptr->next;
	}
	cout << "null" << endl;
}
