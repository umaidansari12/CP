/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

/*
Problem Statement
You are given a Singly Linked List of integers and an integer array 'B' of size 'N'. Each element in the array 'B' represents a block size. Modify the linked list by reversing the nodes in each block whose sizes are given by the array 'B'.
Note:
1. If you encounter a situation when 'B[i]' is greater than the number of remaining nodes in the list, then simply reverse the remaining nodes as a block and ignore all the block sizes from 'B[i]'.

2. All block sizes are contiguous i.e. suppose that block 'B[i]' ends at a node cur, then the block 'B[i+1]' starts from the node just after the node cur.
Example
Linked list: 1->2->3->4->5
Array B: 3 3 5

Output: 3->2->1->5->4

We reverse the first block of size 3 and then move to block 2. Now, since the number of nodes remaining in the list (2) is less than the block size (3), we reverse the remaining nodes (4 and 5) as a block and ignore all the block sizes that follow.
Input Format:
The first line of the input contains the elements of the singly linked list separated by a single space and terminated by -1. Hence, -1 would not be a list element.

The second line contains a single integer 'N', denoting the size of the block array 'B'.

The third line contains 'N' single space-separated elements of the block array 'B'.
Output Format:
You should return the modified linked list where elements should be single-space separated, terminated by -1.
Note:
You don't need to print the output, it has already been taken care of. Just implement the given function.
Constraints:
0 <= L <= 5 * 10^5
-10^9 <= data <= 10^9 and data != -1
1 <= N <= 5 * 10^5
0 <= B[i] <= 5 * 10^5

Where 'L' is the number of nodes in the linked list and 'data' is the value of a node in the linked list.

Time Limit: 1 sec
Sample Input 1:
1 2 3 4 5 6 7 8 9 10 11 -1
3
2 3 4
Sample Output 1:
2 1 5 4 3 9 8 7 6 10 11 -1
Explanation Of The Sample Output 1:
For the given input, the block sizes are 2, 3 and 4 respectively. First, we reverse 2 elements (1->2 becomes 2->1), then the next 3 elements (3->4->5 becomes 5->4->3) and lastly the next 4 elements (6->7->8->9 becomes 9->8->7->6). Thus, the final modified list becomes 2->1->5->4->3->9->8->7->6->10->11.
Sample Input 2:
0 6 1 5 -1
2
2 3
Sample Output 2:
6 0 5 1 -1
Explanation Of The Sample Output 2:
For the given input, the block sizes are 2 and 3 . First, we reverse 2 elements (0->6 becomes 6->0), then we need to change next 3 elements but we are left with only 2 elements (1->5) and thus it becomes (5->1). Thus, the final modified list becomes 6->0->5->1.

Input :
2 5 7 8 4 -1
3
2 3 4

1 2 3 4 5 6 7 8 9 10 11 -1
3
2 3 4

0 6 1 5 -1
2
2 3

1 2 3 4 5 -1
3
3 3 5

-1
1
3

5 7 8 2 4 -1
3
1 0 2

1 3 5 7 9 -1
2
6 2

1 2 3 4 5 -1
1
0

1 2 3 4 5 -1
10
1 0 0 1 0 0 1 1 1 0

Output :
5 2 4 8 7 -1

2 1 5 4 3 9 8 7 6 10 11 -1

6 0 5 1 -1

3 2 1 5 4 -1

-1

5 8 7 2 4 -1

9 7 5 3 1 -1

1 2 3 4 5 -1

1 2 3 4 5 -1


*/


Node* reverse(Node* head, int n, int b[], int index) {
	if (head == NULL or head->next == NULL or index == n)
		return head;
	int k = b[index];
	if (k == 0)
	{
		head = reverse(head, n, b, index + 1);
		return head;
	}

	Node* curr = head;
	Node* next = NULL;
	Node* prev = NULL;

	while (curr and k-- > 0) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	if (next) {
		head->next = reverse(next, n, b, index + 1);
	}
	return prev;
}

Node *getListAfterReverseOperation(Node *head, int n, int b[]) {
	// Write your code here.

	return reverse(head, n, b, 0);
}