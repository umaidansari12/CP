#include <bits/stdc++.h>

using namespace std;

void miniMaxSum(vector<int> arr) {
    int max=arr[0],min=arr[0],sum=arr[0];
    for(int i=1; i < arr.size();i++)
    {
        sum+=arr[i];
        if(max<arr[i])
        {
            max=arr[i];
        }
        if(min > arr[i])
        {
            min=arr[i];
        }
    }
    cout<<sum<<endl<<min<<endl<<max<<endl;
    cout << sum-max<<sum-min<< endl;
}

int main()
{
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    miniMaxSum(a);
}