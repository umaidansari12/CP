#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends

/*You are required to complete this method*/

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> M(n, vector<int>(m, 0));
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                M[i][j] = matrix[i][j] == '1' ? 1 : 0;
            }
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                if (M[i][j] == 1)
                {
                    M[i][j] += M[i - 1][j];
                }
        }
        for (int i = 0; i < n; i++)
        {
            int j = 0;
            stack<int> s;
            while (j < m)
            {
                if (s.empty() || M[i][s.top()] <= M[i][j])
                    s.push(j++);
                else
                {
                    int t = s.top();
                    s.pop();
                    int a = M[i][t] * (s.empty() ? j : j - s.top() - 1);
                    res = max(res, a);
                }
            }
            while (!s.empty())
            {
                int t = s.top();
                s.pop();
                int a = M[i][t] * (s.empty() ? j : j - s.top() - 1);
                res = max(res, a);
            }
        }
        return res;

    }
};

class Solution {
public:
    /*int maxArea(vector<vector<int>> arr, int n, int m) {
        // Your code here
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] == 1)
                {
                    int row = 1, col = 1;
                    for (int k = i + 1; k < n; k++)
                    {
                        if (arr[k][j] == 1)
                            row++;
                        else
                            break;
                    }
                    for (int k = j + 1; k < m; k++)
                    {
                        if (arr[i][k] == 1)
                            col++;
                        else
                            break;
                    }
                    ans = max(ans, row * col);
                }
            }
        }
        return ans;
    }*/
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int res = 0;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                if (M[i][j] == 1)
                {
                    M[i][j] += M[i - 1][j];
                }
        }
        for (int i = 0; i < n; i++)
        {
            int j = 0;
            stack<int> s;
            while (j < m)
            {
                if (s.empty() || M[i][s.top()] <= M[i][j])
                    s.push(j++);
                else
                {
                    int t = s.top();
                    s.pop();
                    int a = M[i][t] * (s.empty() ? j : j - s.top() - 1);
                    res = max(res, a);
                }
            }
            while (!s.empty())
            {
                int t = s.top();
                s.pop();
                int a = M[i][t] * (s.empty() ? j : j - s.top() - 1);
                res = max(res, a);
            }
        }
        return res;
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    /*int M[MAX][MAX];*/

    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
// } Driver Code Ends