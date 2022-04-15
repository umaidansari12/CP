#include <bits/stdc++.h>

using namespace std;

void segregateElements(int [], int );

int main() {
	// your code goes here
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		segregateElements(a, n);

		for (int i = 0; i < n; i++)
			cout << a[i] << " ";
		cout << endl;
	}
}
/*using modified insertion sort if the current element is positive we dont do anything
but if it is negative we shift all positive elements to its right so that we can place negative elements in the
beginning of the array*/
void segregateElements(int arr[], int n)
{
	// Your code goes here
	int key, j;
	for (int i = 1; i < n; i++)
	{
		key = arr[i];
		if (key > 0)
			continue;
		j = i - 1;
		while (j >= 0 &&  arr[j] > 0)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}
void segregateElements(int arr[], int n)
{
	int i = 0, j = 0;
	while (i < n)
	{
		if (arr[i] < 0)
			swap(arr[i++], arr[j++]);
		else
			i++;
	}

}