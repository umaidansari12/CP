#include <bits/stdc++.h>

using namespace std;
/*
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//Compiler version g++ 6.3.0

int main()
{
    int n,k,max=0,a[10000];
    vector<int>m;
    cin >> n >> k;
    for(int i=0;i < n;i++)
    {
      cin>> a[i];
    }
    for(int i=0;i<n-k;i++)
    {
      max=a[i];
      for(int j=i+1;j<k+i;j++)
      {
        if(a[j]>max)
        {
          max=a[j];
        }
      }
      m.push_back(max);
    }
    for(auto i=m.begin();i!=m.end();i++)
    {
      cout << *i <<" ";
    }
}
int main()
{
    int t,n,k,max=0;
    vector<int>m;
    cin >> t;
    for(int i =0 ; i < t ;i++)
    {
        cin >> n;
        cin >> k;
        int a[n];
        for(int j=0;j<n;j++)
        {
            cin >> a[j];
        }
        for(int i=0;i<=n-k;i++)
        {
          max=a[i];
      for(int j=i+1;j<k+i;j++)
      {
        if(a[j]>max)
        {
          max=a[j];
        }
      }
      m.push_back(max);
    }
    for(auto i=m.begin();i!=m.end();i++)
    {
      cout << *i <<" ";
    }
    }
    
}

int main()
{
    int n,k,i;
    cin >> n;
    cin >> k;
    int a[n];
    deque<int> q(k);
    for(i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for(i=0;i<k;i++)
    {
        while(!q.empty() && a[i]>=a[q.back()]) // processing first k elements and inserting in queue the index of maximum elements in the window
        {
            q.pop_back();
        }
        q.push_back(i);
    }
    for(;i<n;i++)
    {
        cout << a[q.front()]<<" ";//prints maximum of each window
        while(!q.empty() && q.front()<=i-k) //remove
        {
            q.pop_front();
        }
        while(!q.empty() && a[i]>=a[q.back()])
        {
            q.pop_back();
        }
        q.push_back(i);
    }
cout<< a[q.front()]<<endl;
}*/
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> m;
        deque<int> q(k);
        int i;
        for(i=0;i<k;i++)
        {
            while(!q.empty() && nums.at(i)>=nums.at(q.back()))
            {
                q.pop_back();
            }
            q.push_back(i);
        }
        int n=nums.size();
        for(;i<n;i++)
        {
            m.push_back(nums.at(q.front()));
            while(!q.empty() && q.front()<=i-k)
            {
                q.pop_front();
            }
            while(!q.empty() && nums.at(i)>=nums.at(q.back()))
            {
                q.pop_back();
            }
            q.push_back(i);
        }
        m.push_back(nums.at(q.front()));
        return m;
    }
    int main()
    {
        vector<int> a;
        vector<int> m;
        //8, 5, 10, 7, 9, 4, 15, 12, 90, 13
        a.push_back(8);
        a.push_back(5);
        a.push_back(10);
        a.push_back(7);
        a.push_back(9);
        a.push_back(4);
        a.push_back(15);
        a.push_back(12);
        a.push_back(90);
        a.push_back(13);
        m=maxSlidingWindow(a,4);
        for(int i:m)
        {
            cout << i << " ";
        }
        //10 10 10 15 15 90 90



	}
    