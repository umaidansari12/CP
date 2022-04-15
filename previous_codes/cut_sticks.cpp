#include<bits/stdc++.h>

using namespace std;

vector<int> cutTheSticks(vector<int> arr) {
    int n=arr.size();
    vector<int> ans(n);
    ans[0]=n;
    int i=1;
    while(arr.size()>0)
    {
        int m=*min_element(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++)
        {
            arr[i]=arr[i]-m;
        }
        arr.erase(remove(arr.begin(), arr.end(), 0), arr.end());
        ans[i]=arr.size();
        i++;
    }
    ans.erase(remove(ans.begin(), ans.end(), 0), ans.end());
return ans;

}


int main()
{
    int n,x;
    vector<int> a(n);
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> x;
        a.push_back(x);
    }
    vector<int> res=cutTheSticks(a);
    for(int i:res)
    {
        cout<<i<<"\t";
    }


}