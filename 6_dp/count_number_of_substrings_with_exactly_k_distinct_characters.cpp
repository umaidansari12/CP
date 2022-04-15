//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
public:

    long long int atMostK(string s, int k, int n) {

        long long int count = 0;

        int start = 0, end = 0;

        int freq[26] = {0};

        for (end = 0; end < n; end++) {
            if (freq[s[end] - 'a'] == 0) {
                k--;
            }

            freq[s[end] - 'a']++;

            while (k < 0) {
                --freq[s[start] - 'a'];
                if (freq[s[start] - 'a'] == 0) {
                    k++;
                }
                start++;
            }

            count += (end - start + 1);

        }

        return count;
    }

    long long int substrCount (string s, int k) {
        //code here.
        int n = s.size();
        return atMostK(s, k, n) - atMostK(s, k - 1, n);
    }

    long long int substrCount (string s, int k) {
        //code here.
        //logic can be simple brute force
        //generate substrings and in each substring check if exactly k character is present or not
        //we need to have a map so that we can check the distinct character count
        int _size = s.size();
        long long int count = 0;
        for (int i = 0; i < _size; i++) {
            unordered_map<char, int> freq;
            for (int j = i; j < _size; j++) {
                freq[s[j]]++;
                if (freq.size() == k) {
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
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        int k; cin >> k;
        Solution ob;
        cout << ob.substrCount (s, k) << endl;
    }
}  // } Driver Code Ends