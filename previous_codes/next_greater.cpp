#include <bits/stdc++.h>

using namespace std;

void print(int a[], int n)
{
    stack<int> s;
    s.push(a[0]);
    for (int i = 1; i < n ; i++)
    {
        if (s.empty())
        {
            s.push(a[i]);
            continue;
        }
        while (s.empty() == false && s.top() < a[i])
        {
            cout << s.top() << "\t" << a[i] << endl;
            s.pop();
        }
        s.push(a[i]);
    }
    while (s.empty() == false)
    {
        cout << s.top() << "\t-1" << endl;
        s.pop();
    }
}

void printNGE(int a[], int n)
{
    stack<int> s;
    s.push(a[0]);
    for (int i = 1; i < n ; i++)
    {
        if (s.empty())
        {
            s.push(a[i]);
            continue;
        }
        while (s.empty() == false && s.top() < a[i] )
        {
            cout << s.top() << "\t" << a[i] << endl;
            s.pop();
        }
        s.push(a[i]);
    }
    while (s.empty())
    {
        cout << s.top() << "\t-1" << endl;
        s.pop();
    }
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, flag = 0;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << "ELEMENT\tNEXT\n";
        print(a, n);
        /*for(int i = 0; i < n ; i++)
        {
            flag=-1;
            cout << a[i] <<"\t";
            for(int j=i+1;j<n;j++)
            {
                if(a[j] > a[i])
                {
                    flag=a[j];
                    break;
                }
            }
            cout << flag <<endl;
        }*/
    }
}