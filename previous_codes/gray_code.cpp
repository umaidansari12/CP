//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans(1 << n);
        for (int i = 0; i < (1 << n); i++)
            ans[i] = i ^ (i >> 1);
        return ans;

    }
};

class Solution {
public:
    void utils(bitset<32>& bits, vector<int>& result, int k) {
        if (k == 0) {
            result.push_back(bits.to_ulong());
        }
        else {
            utils(bits, result, k - 1);
            bits.flip(k - 1);
            utils(bits, result, k - 1);
        }
    }
public:
    vector<int> grayCode(int n) {
        bitset<32> bits;
        vector<int> result;
        utils(bits, result, n);
        return result;
    }
};

class Solution
{
public:
    string getBinaryString(int i, int n)
    {
        string s = "";
        int count = 0;
        while (i > 0)
        {
            s += to_string(i % 2);
            i /= 2;
            count++;
        }
        while (count < n)
        {
            s += '0';
            count++;
        }
        reverse(s.begin(), s.end());
        return s;
    }

    vector<string> graycode(int n)
    {
        //code here
        vector<string> arr;
        if (n <= 0)
            return arr;
        // 'arr' will store all generated codes


        // start with one-bit pattern
        arr.push_back("0");
        arr.push_back("1");

        // Every iteration of this loop generates 2*i codes from previously
        // generated i codes.
        int i, j;
        for (i = 2; i < (1 << n); i = i << 1)
        {
            // Enter the prviously generated codes again in arr[] in reverse
            // order. Nor arr[] has double number of codes.
            for (j = i - 1 ; j >= 0 ; j--)
                arr.push_back(arr[j]);

            // append 0 to the first half
            for (j = 0 ; j < i ; j++)
                arr[j] = "0" + arr[j];

            // append 1 to the second half
            for (j = i ; j < 2 * i ; j++)
                arr[j] = "1" + arr[j];
        }
        return arr;

    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        Solution ob;
        vector<string> ans = ob.graycode(n);
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";

        cout << "\n";
    }
}



// } Driver Code Ends