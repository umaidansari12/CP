#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void generate(int i, int n, vector<string> &r, string s)
    {
        if (i == n)
        {
            r.push_back(s);
            return;
        }
        generate(i + 1, n, r, s + '1');
        generate(i + 1, n, r, s + '0');
    }
    int numberOfConsecutiveOnes(int N) {
        // code here
        vector<string> r;
        int count = 0;
        generate(0, N, r, "");
        for (auto i : r)
        {
            //cout << i << " ";
            for (int j = 0; j < i.size() - 1; j++)
            {
                if (i[j] == i[j + 1] and i[j] == '1')
                {
                    count++;
                    break;
                }
            }
        }
        //cout << endl;
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
        Solution ob;
        cout << ob.numberOfConsecutiveOnes(N) << endl;
    }
    return 0;
}
// } Driver Code Ends