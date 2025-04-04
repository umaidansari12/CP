#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void leftRotateBrute(int arr[], int k, int n)
{
    // Your code goes here
    int cpy_arr[n];
    for (int i = 0; i < n; i++) {
        cpy_arr[i] = arr[(i + k) % n];
    }
    for (int i = 0; i < n; i++) {
        arr[i] = cpy_arr[i];
    }
}

void leftRotateBetter(vector<int> &a, int N, int K) {
    K = K % N;
    // storing - O(k), space - O(k)
    vector<int> temp(K, 0);
    for (int i = 0; i < K; i++) {
        temp[i] = a[i];
    }
    // shifting - O(n-k)
    for (int i = K; i < N; i++) {
        a[i - K] = a[i];
    }
    // putting back - O(k)
    for (int i = N - K, index = 0; i < N; i++) {
        // a[i] = temp[index];
        a[i] = temp[i - (N - K)];
    }
    // Time Complexity - O(K) + O(N-K) + O(K)
}

void leftRotateOptimal(vector<int> &a, int N, int K) {
    K = K % N;
    // This is based out of sheer observation
    // First reverse the first K part
    // Then reverse next N-K
    // Then reverse entire array
    // doing this we are removing dependancy on the extra space
    // Time Complexity - O(K) + O(N-K) + O(K) = O(2N)
    // Space Complexity - O(1)
    reverse(a.begin(), a.begin() + K);
    reverse(a.begin() + K, a.end());
    reverse(a.begin(), a.end());
}

int main() {
    //Write your code here
    int N, K;
    cin >> N;
    vector<int> a(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    cin >> K;
    leftRotateOptimal(a, N, K);
    for (int i = 0; i < N; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}