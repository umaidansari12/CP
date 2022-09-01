//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long reversedBits(long long X) {
        // code here
        vector<int> bits(32,0);
        int index = 31;
        while(X>0){
            int bit = X%2;
            X/=2;
            bits[index] = bit;
            index--;
        }
        long long pow = 1,num=0;
        for(int i=0;i<32;i++){
            num += (pow*bits[i]);
            pow*=2;
        }
        return num;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends