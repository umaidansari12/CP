#include<bits/stdc++.h>
using namespace std;

class Solution {
    // Function to find the leaders in the array.
public:
    vector<int> leaders(int n, int arr[]) {
        // Code here
        vector<int> answer;
        for (int i = 0; i < n; i++) {
            bool found = true;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] > arr[i]) {
                    found = false;
                    break;
                }
            }
            if (found)
                answer.push_back(arr[i]);
        }
        return answer;
    }
};

class Solution {
    // Function to find the leaders in the array.
public:
    vector<int> leaders(int n, int arr[]) {
        // Code here
        vector<int> answer;
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            if (st.empty() or arr[i] >= st.top()) {
                st.push(arr[i]);
            }
        }

        while (!st.empty()) {
            answer.push_back(st.top());
            st.pop();
        }

        return answer;
    }
};

vector<int> superiorElements(vector<int>&a) {
    // Write your code here.
    int n = a.size();
    vector<int> answer;
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        if (st.empty() or a[i] > st.top()) {
            st.push(a[i]);
        }
    }

    while (!st.empty()) {
        answer.push_back(st.top());
        st.pop();
    }
    sort(answer.begin(), answer.end());

    return answer;
}


vector<int> printLeaders(int arr[], int n) {

    vector<int> ans;

// Last element of an array is always a leader,
// push into ans array.
    int max = arr[n - 1];
    ans.push_back(arr[n - 1]);

    // Start checking from the end whether a number is greater
    // than max no. from right, hence leader.
    for (int i = n - 2; i >= 0; i--)
        if (arr[i] > max) {
            ans.push_back(arr[i]);
            max = arr[i];
        }


    return ans;
}

int main() {

    // Array Initialization.
    int n = 6;
    int arr[n] = {10, 22, 12, 3, 0, 6};

    vector<int> ans = printLeaders(arr, n);


    for (int i = ans.size() - 1; i >= 0; i--) {

        cout << ans[i] << " ";
    }

    cout << endl;
    return 0;
}