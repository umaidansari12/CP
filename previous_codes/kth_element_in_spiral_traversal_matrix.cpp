#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int findK(int [MAX][MAX], int , int , int );
int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n, m;
        int k = 0;
        //cin>>k;
        cin >> n >> m >> k;
        int a[MAX][MAX];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }
        cout << findK(a, n, m, k) << endl;


    }
}// } Driver Code Ends


/*You are required to complete this method*/
int findK(int arr[MAX][MAX], int n, int m, int k)
{
//Your code here
    int top = 0, down = n - 1, right = m - 1, left = 0, ik = 0, direction = 0;
    while (left <= right && top <= down)
    {
        if (direction == 0)
        {
            for (int i = left; i <= right; i++)
            {
                if (ik == k - 1)
                    return arr[top][i];
                ik++;
            }
            top++;
        }
        else if (direction == 1)
        {
            for (int i = top; i <= down; i++)
            {
                if (ik == k - 1)
                    return arr[i][right];
                ik++;
            }
            right--;
        }
        else if (direction == 2)
        {
            for (int i = right; i >= left; i--)
            {
                if (ik == k - 1)
                    return arr[down][i];
                ik++;
            }
            down--;
        }
        else if (direction == 3)
        {
            for (int i = down; i >= top; i--)
            {
                if (ik == k - 1)
                    return arr[i][left];
                ik++;
            }
            left++;
        }
        direction = (direction + 1) % 4;
    }
    return 0;
}

