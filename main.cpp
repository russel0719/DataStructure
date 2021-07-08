// for debug and memory leak check
#if defined(_DEBUG)
#define _CRTDBG_MAP_ALLOC
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif
#include <stdlib.h>
#include <crtdbg.h>

// Data Structure import
#include "LinkedList.h"
#include "Queue.h"
#include "Stack.h"
#include "Tree.h"

// elemetal setting
#include <iostream>
using namespace std;

void ll_test() {
	cout << "------------------------------" << endl << "Start LinkedList Test" << endl << "------------------------------" << endl;
	LinkedList<int> ll;

	ll.insert(1); // 1->null
	ll.insert(3); // 1->3->null
	ll.insert(4); // 1->3->4->null
	ll.insert(2); // 1->3->4->2->null
	ll.delete_index(2); //1->3->2->null
	cout << ll.find(2) << endl; // return 2
	ll.print(); // 1->3->2
	cout << ll.size << endl;
}

void queue_test() {
	cout << "------------------------------" << endl << "Start Queue Test" << endl << "------------------------------" << endl;
	Queue<int> q;

	q.push(1);	// front <- 1 <- rear
	q.push(3);	// front <- 1 <- 3 <- rear
	q.push(8);	// front <- 1 <- 3 <- 8 <- rear
	q.pop();	// front <- 3 <- 8 <- rear
	q.print();	
	q.push(4);	// front <- 3 <- 8 <- 4 <- rear
	q.push(7);	// front <- 3 <- 8 <- 4 <- 7 <- rear
	q.push(2);	// front <- 3 <- 8 <- 4 <- 7 <- 2 <- rear
	q.push(6);	// error
	q.pop();	// front <- 8 <- 4 <- 7 <- 2 <- rear
	q.print();
	q.pop();	// front <- 4 <- 7 <- 2 <- rear
	q.pop();	// front <- 7 <- 2 <- rear
	q.pop();	// front <- 2 <- rear
	q.pop();	// front <- rear
	q.pop();	// error
	q.print();
}

void stack_test() {
	cout << "------------------------------" << endl << "Start Stack Test" << endl << "------------------------------" << endl;
	Stack<int> s;

	s.push(1);
	s.push(3);	// bottom -> 1 -> 3 -> top
	s.push(8);	// bottom -> 1 -> 3 -> 8 -> top
	s.pop();	// bottom -> 1 -> 3 -> top
	s.print();
	s.push(4);	// bottom -> 1 -> 3 -> 4 -> top
	s.push(7);	// bottom -> 1 -> 3 -> 4 -> 7 -> top
	s.push(2);	// bottom -> 1 -> 3 -> 4 -> 7 -> 2 -> top
	s.push(6);	// error
	s.pop();	// bottom -> 1 -> 3 -> 4 -> 7 -> top
	s.print();
	s.pop();	// bottom -> 1 -> 3 -> 4 -> top
	s.pop();	// bottom -> 1 -> 3 -> top
	s.pop();	// bottom -> 1 -> top
	s.pop();	// bottom -> top
	s.pop();	// error
	s.print();
}

void tree_test() {
	cout << "------------------------------" << endl << "Start Tree Test" << endl << "------------------------------" << endl;
	Tree<int> t;

	t.insert(6);
	t.insert(7);
	t.insert(1);
	t.insert(4);
	t.insert(2);
	t.insert(9);
	t.insert(3);
	t.insert(5);
	t.insert(8);
	t.travel_in();
	t.travel_post();

}

int main() {
	ll_test();
	queue_test();
	stack_test();

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	return 0;
}
