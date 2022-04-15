#include <bits/stdc++.h>

using namespace std;

vector<int> quickSort(vector<int> arr) {
    list <int> s;
    vector<int> a;
    for(int i:arr)
    {
        if(i==arr[0])
        {
            s.push_back(i);
        }
        else if(i<arr[0])
        {
            s.push_front(i);
        }
        else
        {
            s.push_back(i);
        }
    }
    for(int i:s)
    {
        a.push_back(i);
    }

return a;
}

int main()
{
    vector<int> a;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }
    vector<int> res=quickSort(a);
}