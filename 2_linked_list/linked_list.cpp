
#include <bits/stdc++.h>

using namespace std;

class Node {
public:
	int key;
	Node* next;
	Node(int key)
	{
		this->key = key;
		this->next = NULL;
	}
};

// class Parent {
// public:
// 	int x;
// }

// class Child :: Parent() {

// 	cout<<x

// }

try() {
	int b = 5 / 0;
}
catch () {
	cout << "Divide by zero" << endl;
}

deep copy and shallow copy;





class LinkedList {
public:
	Node* head;
	Node* prev;
	LinkedList()
	{
		head = NULL;
		prev = NULL;
	}
	void insert(int x)
	{
		if (head == NULL)
		{
			head = new Node(x);
			prev = head;
		}
		else
		{
			prev->next = new Node(x);
			prev = prev->next;
		}

	}

	void print()
	{
		Node* curr = head;
		while (curr)
		{
			cout << curr->key << " ";
			curr = curr->next;
		}
	}

};



int main()
{
	LinkedList l;
	l.insert(5);
	l.insert(8);
	l.insert(10);
	l.insert(12);
	l.print();

	return 0;

}