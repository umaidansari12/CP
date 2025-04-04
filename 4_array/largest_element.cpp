#include<bits/stdc++.h>
using namespace std;

int largestElement(vector<int> arr) {
    int largest = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
        largest = max(largest, arr[i]);
    return largest;

    // TC - O(n)
    // SC - O(1)

}

class Solution
{
public:
    int largest(vector<int> &arr, int n)
    {
        int answer = arr[0]; // one of the array elements will be largest so assign arr[0]
        for (int i = 1; i < n; i++)
            answer = max(answer, arr[i]);
        return answer;
    }
};

// sort and return last element
// TC - O(nlogn)
// sc - O(1) - ignoring recursive stack space