#include<bits/stdc++.h>

using namespace std;

//take transpose of the matrix
//reverse every row

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }

    }
};

class Solution {
public:
    //Take the first row put it in last column , take the second row put it in second last column
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> b(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                b[j][n - i - 1] = matrix[i][j];
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[i][j] = b[i][j];
            }
        }

    }
};
void rotate(int a[][1000], int n)
{
    for (int i = 0; i < n; i++)
    {
        int s = 0, e = n - 1;
        while (s < e)
        {
            swap(a[i][s], a[i][e]);
            s++;
            e--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i < j)
            {
                swap(a[i][j], a[j][i]);
            }

        }
    }
    cout << "Without STL : \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

}

void rotate_stl(int a[][1000], int n)
{
    for (int i = 0; i < n; i++)
    {
        reverse(a[i], a[i] + n);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i < j)
            {
                swap(a[i][j], a[j][i]);
            }
        }
    }
    cout << "STL : \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}



int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int a[100][1000] = {};
        int b[n][n] = {};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }
        cout << "Normal :\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0, k = n - 1; j<n, k >= 0; j++, k--)
            {
                b[i][j] = a[k][i];
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << b[i][j] << " ";
            }
            cout << endl;
        }
    }

}