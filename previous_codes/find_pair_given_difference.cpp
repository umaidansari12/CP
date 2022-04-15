#include <bits/stdc++.h>

using namespace std;


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int l, n;
        cin >> l >> n;
        int arr[l];
        for (int i = 0; i < l; i++)
            cin >> arr[i];
        if (findPair(arr, l, n))
            cout << 1 << endl;
        else cout << "-1" << endl;
    }


    return 0;
}// } Driver Code Ends


bool findPair(int arr[], int size, int n) {
    //code
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (abs(arr[i] - arr[j]) == n)
                return true;
        }
    }
    return false;

}

bool findPair(int arr[], int size, int n) {
    //code
    sort(arr, arr + size);
    for (int i = 0; i < size; i++)
        if (binary_search(arr, arr + size, n + arr[i]))
            return true;

    return false;

}

int Solution::solve(vector<int> &A, int B) {
    map<int, int> m;
    if (B == 0)
        return 0;
    for (int i = 0; i < A.size(); i++)
        m[A[i]]++;
    for (int i = 0; i < A.size(); i++)
        if (m.find(B + A[i]) != m.end())
            return 1;

    return 0;

}
