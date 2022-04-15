#include <bits/stdc++.h>

using namespace std;
//using ll = long long;

class Node {
public:
	int data;
	Node* next;
	Node(int x)
	{
		this->data = x;
		this->next = NULL;
	}
};

Node* rotate(Node* head, int k)
{
	// Your code here
	int count = 0;
	Node* curr = head;
	while (curr)
	{
		count++;
		curr = curr->next;
	}
	k = k % count;
	k = count - k;
	while (k--)
	{
		Node* prev = head;
		curr = head->next;
		while (curr->next != NULL)
		{
			curr = curr->next;
			prev = prev->next;
		}
		curr->next = head;
		prev->next = NULL;
		head = curr;
	}
	return head;
}

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == NULL || head->next == NULL || k == 0)
			return head;
		int count = 1;
		ListNode* curr = head;
		while (curr->next)
		{
			count++;
			curr = curr->next;
		}
		k = k % count;
		curr->next = head;
		k = count - k;
		while (k--)
			curr = curr->next;
		head = curr->next;
		curr->next = NULL;
		return head;

	}
};
Node* rotate(Node* head, int k)
{
	// Your code here
	if (head == NULL || head->next == NULL || k == 0)
		return head;
	int count = 1;
	Node* curr = head;
	while (curr && count < k)
	{
		curr = curr->next;
		count++;
	}
	if (!curr)
		return head;
	Node* kthNode = curr;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = head;
	head = kthNode->next;
	kthNode->next = NULL;
	return head;

}
Node* rotate(Node* head, int k)
{
	// Your code here
	if (head == NULL || head->next == NULL || k == 0)
		return head;
	int count = 1;
	Node* curr = head;
	while (curr->next)
	{
		curr = curr->next;
		count++;
	}
	curr->next = head;
	while (k--)
		curr = curr->next;
	head = curr->next;
	curr->next = NULL;
	return head;

}

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == NULL)
			return NULL;
		int count = 0;
		ListNode* curr = head;
		ListNode* prev;
		while (curr)
		{
			count++;
			curr = curr->next;
		}
		k = k % count;
		while (k--)
		{
			prev = head;
			curr = head->next;
			while (curr->next != NULL)
			{
				curr = curr->next;
				prev = prev->next;
			}
			curr->next = head;
			prev->next = NULL;
			head = curr;
		}
		return head;
	}
};

class LinkedList {
public:
	Node* head = NULL;
	Node* prev = NULL;
	void insert(int x)
	{
		Node* newNode = new Node(x);
		if (head == NULL)
			head = newNode;
		else
			prev->next = newNode;
		prev = newNode;
	}
	void print()
	{
		Node* current = head;
		while (current != NULL)
		{
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}

	void change(Node* h)
	{
		this->head = h;
	}

	void rotateALinkedList(int k)
	{
		int count = 0;
		Node* left = NULL;
		Node* prev = NULL;
		Node* current = head;
		Node* right = NULL;
		while (count < k)
		{
			Node* newNode = new Node(current->data);
			if (left == NULL)
				left = newNode;
			else
				prev->next = newNode;
			prev = newNode;
			current = current->next;
			count++;
		}
		if (current == NULL)//corner case when k is equal to length of linked list
			return;
		prev->next = NULL;
		prev = NULL;
		while (current)
		{
			Node* newNode = new Node(current->data);
			if (right == NULL)
				right = newNode;
			else
				prev->next = newNode;
			prev = newNode;
			current = current->next;
		}
		prev->next = left;
		this->head = right;
	}

	void rotate_a_linked_list(int k)
	{
		if (k == 0)
			return;
		Node* current = head;
		int count = 0;
		while (current != NULL && count < k + 1)
		{
			current = current->next;
			count++;
		}
		if (current == NULL)
			return;
		Node* nextofCurrent = current->next;
		current->next = NULL;
		//current=NULL;
		while (nextofCurrent->next != NULL)
			nextofCurrent = nextofCurrent->next;
		nextofCurrent->next = head;
		head = nextofCurrent;
	}

};

/*Node* rotate(Node* head, int k)
{
	// Your code here
	if (head == NULL || head->next == NULL || k == 0)
		return head;
	Node* current = head;
	Node* left = NULL;
	Node* right = NULL;
	Node* prev = NULL;
	int count = 0;
	while (count < k)
	{
		Node* newNode = new Node(current->data);
		if (left == NULL)
			left = newNode;
		else
			prev->next = newNode;
		prev = newNode;
		current = current->next;
		count++;
	}
	if (current == NULL)
		return head;
	prev->next = NULL;
	prev = NULL;
	while (current)
	{
		Node* newNode = new Node(current->data);
		if (right == NULL)
			right = newNode;
		else
			prev->next = newNode;
		prev = newNode;
		current = current->next;
	}
	prev->next = left;
	return right;
}


Node* rotate(Node* head, int k)
{
    // Your code here
    int count=1;
    Node* current=head;
    while(current!=NULL && count<k)
    {
        current=current->next;
        count++;
    }
    if(current==NULL)
    return head;
    Node* kthNode=current;
    while(current->next!=NULL)
    {
        current=current->next;
    }
    current->next=head;
    head=kthNode->next;
    kthNode->next=NULL;
    return head;
}
ListNode* rotateRight(ListNode* head, int k) {
        ListNode* current=head;
        if(head==NULL || k==0)
            return head;
        int count=0;
        while(current!=NULL)
        {
            current=current->next;
            count++;
        }
        k=k%count;
        current=head;
        count=0;
        while(count<k)
        {
            current=current->next;
            count++;
        }
        ListNode* kthNode=current;
        while(current->next!=NULL)
            current=current->next;
        current->next=head;
        head=kthNode->next;
        kthNode->next=NULL;
        return head;

    }
Enumerate through the list to find the last node, count the size along the way.
Make a loop, by connection last to first
Get modulo of |k/size| - avoiding extra rotation
Enumerate again size-k nodes
Break the loop and return new head

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* current=head;
        if(head==NULL || k==0)
            return head;
        int count=1;
        while(current->next!=NULL)
        {
            current=current->next;
            count++;
        }
        current->next=head;
        k=k%count;
        while(--count>=k)
        {
            current=current->next;
        }
        head=current->next;
        current->next=NULL;
        return head;

    }
};
Since n may be a large number compared to the length of list. So we need to know the length of linked list. After that, move the list after the (l-n % l )th node to the front to finish the rotation.

Ex: {1,2,3} k = 2 Move the list after the 1st node to the front

Ex: {1,2,3} k = 5, In this case Move the list after (3-5 % 3=1)st node to the front.

So the code has three parts.

1) Get the length

2) Move to the (l-n%l)th node

3) Do the rotation
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* current=head;
        if(head==NULL || k==0)
            return head;
        int count=1;
        while(current->next!=NULL)
        {
            current=current->next;
            count++;
        }
        current->next=head;
        k=k%count;
        while(--count>=k)
        {
            current=current->next;
        }
        head=current->next;
        current->next=NULL;
        return head;

    }
};

*/



int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int n, x;
		cin >> n;
		LinkedList l;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			l.insert(x);
		}
		cin >> x;
		cout << "Before : ";
		l.print();
		cout << "After : ";
		l.rotate_a_linked_list(x);
		l.print();

	}

	return 0;
}
