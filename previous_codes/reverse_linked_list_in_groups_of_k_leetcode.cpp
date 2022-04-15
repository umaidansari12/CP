#include <bits/stdc++.h>

using namespace std;
//using ll = long long;

class Node {
public:
	int data;
	Node* next;
	Node(int data)
	{
		this->data = data;
		this->next = next;
	}
};


class LinkedList {
public:
	Node* head;
	Node* prev;
	LinkedList()
	{
		this->head = NULL;
		this->prev = NULL;
	}
	void insert(int x)
	{
		Node* newNode = new Node(x);
		if (head == NULL)
		{
			head = newNode;
		}
		else
		{
			prev->next = newNode;
		}
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
	void change(Node* node)
	{
		this->head = node;
	}
};

Node* reverseLinkedListInGroupsOfK(Node* head, int k)
{
	int count = 0;
	Node* current = head;
	Node* prev = NULL;
	Node* next;
	while (current != NULL)
	{
		if (count == k)
			break;
		current = current->next;
		count++;
	}
	if (count < k)
		return head;
	current = head;
	count = 0;
	while (current != NULL && count < k)
	{
		if (current == NULL && count < k)
			next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		count++;
	}
	if (next != NULL)
		head->next = reverseLinkedListInGroupsOfK(next, k);
	return prev;
}
int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int n, x, k;
		cin >> n;
		LinkedList l;
		//Node* head = NULL;
		//Node* prev = NULL;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			l.insert(x);
		}
		cin >> k;
		cout << "Before : ";
		l.print();
		Node* h = reverseLinkedListInGroupsOfK(l.head, k);
		l.change(h);
		cout << "After : ";
		l.print();
		cout << "Done\n";
	}

	return 0;
}

/*class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count=0;
        ListNode* current=head;
        ListNode* prev=NULL;
        ListNode* next=NULL;
        while(current!=NULL)
        {
            if(count==k)
                break;
            count++;
            current=current->next;
        }
        if(count < k)
            return head;
        count=0;
        current=head;
        while(current!=NULL && count<k)
        {
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
            count++;
        }
        if(next!=NULL)
            head->next=reverseKGroup(next,k);
        return prev;


    }
};*/




