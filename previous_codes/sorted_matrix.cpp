// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        // code here
        int r[N * N], k = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                r[k++] = Mat[i][j];
        }
        sort(r, r + (N * N));
        k = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                Mat[i][j] = r[k++];
            }
        }
        return Mat;
        /*int r[N*N],k=0;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            r[k++]=Mat[i][j];
        }
        sort(r,r+(N*N));
        k=0;
        for(int i=0;i<N*N;i++)
        {
            int row=i/N;
            int c=i%N;
            Mat[row][c]=r[i];
        }
        return Mat;*/
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> v(N, vector<int>(N));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) cin >> v[i][j];
        Solution ob;
        v = ob.sortedMatrix(N, v);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) cout << v[i][j] << " ";
            cout << "\n";
        }
    }
}  // } Driver Code Ends