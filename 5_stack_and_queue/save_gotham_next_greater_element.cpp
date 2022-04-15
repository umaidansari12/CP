#include <bits/stdc++.h>
using namespace std;

int save_gotham(int arr[], int n);



int main() {

    int t;
    cin >> t;
    while (t--)
    {
        int n; cin >> n;
        int arr[n];

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cout << save_gotham(arr, n) << endl;
    }

    return 0;
}// } Driver Code Ends

int save_gothamBrute(int arr[], int n)
{
    // Complete the function
    int sum = 0, mod = 1e9 + 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                sum = (sum + arr[j]) % mod;
                break;
            }
        }
    }
    return sum;
}


int save_gotham(int arr[], int n)
{
    // Complete the function

    int res = 0;

    stack<int> st;
    st.push(arr[n - 1]);

    for (int i = n - 2; i >= 0; i--)
    {
        while (!st.empty() and st.top() <= arr[i])
        {
            st.pop();
        }

        int curr = st.empty() ? 0 : st.top();

        res = (res + curr) % 1000000001;

        st.push(arr[i]);
    }

    return res;
}