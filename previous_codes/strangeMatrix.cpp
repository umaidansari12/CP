//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

class A
{
private:
  int R, C;
  vector<int> B;

public:
  void init(int _R, int _C, vector<int> _B)
  {
    R = _R;
    B = _B;
    C = _C;
  }
  int get(int i, int j)
  {
    assert(0 <= i && i < R && 0 <= j && j < C);
    if (B[i] >= j + 1)
      return 0;
    return 1;
  }
} a;

// } Driver Code Ends
//User function Template for C++

class Solution {
private:
  // do not edit this function
  // use it to get the value of A[i][j]
  int get(int i, int j) {
    return a.get(i, j);
  }
public:
  int solve(int R, int C) {
    //code here
    int ans = 0, i = 0, j = C;
    while (i < R)
    {
      while (j > 0 and get(i, j - 1) == 1)
      {
        ans = max(ans, i);
        j--;
      }
      i++;
    }
    return ans;
  }
};

// { Driver Code Starts.
signed main()
{

  int t;
  cin >> t;
  while (t--)
  {
    int R, C;
    cin >> R >> C;

    vector<int> B(R);
    for (int i = 0; i < R; i++)
    {
      cin >> B[i];
      /*
          B[i] denotes the number of zeros in the ith row
          A[i][j]=0 if j+1<=B[i]
          A[i][j]=1 else
      */
      assert(0 <= B[i] && B[i] <= C);
    }
    a.init(R, C, B);
    Solution obj;
    long long answer = obj.solve(R, C);
    cout << answer << endl;
  }
}
// } Driver Code Ends