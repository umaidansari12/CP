
// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int findSubArraySum(int Arr[], int N, int k)
    {
        // code here
        int count = 0, curr_sum = 0;
        map<int, int> presum;
        for (int i = 0; i < N; i++)
        {
            curr_sum += Arr[i];
            if (curr_sum == k)
                count++;
            if (presum.find(curr_sum - k) != presum.end())
                count += presum[curr_sum - k];
            presum[curr_sum]++;
        }
        return count;
    }
    int findSubArraySum(int Arr[], int N, int k)
    {
        // code here
        int count = 0;
        for (int i = 0; i < N; i++)
        {
            int sum = 0;
            for (int j = i; j < N; j++)
            {
                sum += Arr[j];
                if (sum == k)
                {
                    count++;
                }
            }
        }
        return count;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for (int i = 0; i < N; i++)
            cin >> Arr[i];
        int k;
        cin >> k;
        Solution obj;
        cout << obj.findSubArraySum(Arr, N, k) << endl;
    }
    return 0;
}  // } Driver Code Ends