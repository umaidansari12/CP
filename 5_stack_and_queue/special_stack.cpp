#include<iostream>
#include<stack>
using namespace std;
void push(stack<int>& s, int a);
bool isFull(stack<int>& s, int n);
bool isEmpty(stack<int>& s);
int pop(stack<int>& s);
int getMin(stack<int>& s);
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, a;
		cin >> n;
		while (!isEmpty(s)) {
			pop(s);
		}
		while (!isFull(s, n)) {
			cin >> a;
			push(s, a);
		}
		cout << getMin(s) << endl;
	}
}// } Driver Code Ends

stack<int> s1;
void push(stack<int>& s, int a) {
	// Your code goes here
	if (s.empty())
	{
		s.push(a);
		s1.push(a);
	}
	else {
		s.push(a);
		s1.push(min(a, s1.top()));
	}
}

bool isFull(stack<int>& s, int n) {
	// Your code goes here
	return s.size() == n;
}

bool isEmpty(stack<int>& s) {
	// Your code goes here
	return s.empty();
}

int pop(stack<int>& s) {
	// Your code goes here
	int ans = -1;
	if (!s.empty())
	{
		ans = s.top();
		s.pop();
		s1.pop();
	}
	return ans;
}

int getMin(stack<int>& s) {
	// Your code goes here
	return s1.top();
}