//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++

vector<int> mergeKArrays(vector<vector<int> > arrays) {
    //Complete this function
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> min_heap;
    int k = arrays.size();
    for (int i = 0; i < k; i++)
    {
        min_heap.push({arrays[i][0], i, 0});
    }
    vector<int> output;
    while (!min_heap.empty())
    {
        vector<int> ele = min_heap.top();
        min_heap.pop();
        int element = ele[0];
        int row_idx = ele[1];
        int idx = ele[2];
        if (idx + 1 < (arrays[row_idx].size()))
        {
            min_heap.push({arrays[row_idx][idx + 1], row_idx, idx + 1});
        }
        output.push_back(element);
    }
    return output;


}

class Solution
{
public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arrays, int K)
    {
        //code here
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> min_heap;
        for (int i = 0; i < K; i++)
        {
            min_heap.push({arrays[i][0], i, 0});
        }
        vector<int> output;
        while (!min_heap.empty())
        {
            vector<int> ele = min_heap.top();
            min_heap.pop();
            int element = ele[0];
            int row_idx = ele[1];
            int idx = ele[2];
            if (idx + 1 < K)
            {
                min_heap.push({arrays[row_idx][idx + 1], row_idx, idx + 1});
            }
            output.push_back(element);
        }
        return output;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        vector<vector<int>> arr(N, vector<int> (N, 0));
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++)
            {
                cin >> arr[i][j];
            }
        }
        Solution obj;
        vector<int> output = obj.mergeKArrays(arr, k);
        printArray(output, k * k);
        cout << endl;
    }
    return 0;
}





// } Driver Code Ends


