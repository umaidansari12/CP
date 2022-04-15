#include <bits/stdc++.h>

using namespace std;
using ll = long long;

Node* sortedArrayToBST(vector<int> arr, int start, int end)
{
	//Return Null if s > e, because no array elements are there
	if (start > end)
		return NULL;

	/* Get the middle element and make it root */
	int mid = (start + end) / 2;
	Node *root = new Node(arr[mid]);

	//create left & right subtrees recursively
	root->left = sortedArrayToBST(arr, start, mid - 1);
	root->right = sortedArrayToBST(arr, mid + 1, end);

	return root;
}

//Call from Main




int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
	sortedArrayToBST(arr, 0 , n - 1)


	return 0;
}