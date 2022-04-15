#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void rotateby90(vector<vector<int> >& matrix, int n)
{
    // code here
    vector<vector<int>> b(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            b[j][i] = matrix[i][n - j - 1];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            matrix[i][j] = b[i][j];
    }

}

class Solution
{
public:
    void rotateby90(vector<vector<int> >& matrix, int n)
    {
        // code here
        for (int i = 0; i < n; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i < j)
                    swap(matrix[i][j], matrix[j][i]);
            }
        }

    }
};
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }
        rotateby90(a, n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl ;
        }
    }

}