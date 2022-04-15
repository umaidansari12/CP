#include <bits/stdc++.h>

using namespace std;

/*int binarySearch(vector <int> a, int item, int low, int high) 
{ 
    if (high <= low) 
        return (item > a[low])?  (low + 1): low; 
  
    int mid = (low + high)/2; 
  
    if(item == a[mid]) 
        return mid+1; 
  
    if(item > a[mid]) 
        return binarySearch(a, item, mid+1, high); 
    return binarySearch(a, item, low, mid-1); 
} 

vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {
    int n=scores.size(),m=alice.size();
    vector <int> count(100000);
    vector <int> rank;
    vector <int> res;
    for(int i=0;i<n;i++)
    {
        count[scores[i]]++;
    }
    cout<<"Caching : ";
    for(int i=0;i<100000;i++)
    {
        if(count[i]>0)
        {
            cout<<count[i]<<" "<<i<<":";
            rank.push_back(i);
        }
    }
    cout<<endl<<"Rank : ";
    for(int i=0;i<rank.size();i++)
    {
        cout<<rank[i]<<" ";
    }
    cout<<"Rank Size : "<<rank.size();
    for(int i=0;i<m;i++)
    {
        int x=alice[i];
        for(int j=0;j<=rank.size();j++)
        {
            
        }
    }

return res;
}*/
vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {
    vector <int> res;
    int m=alice.size();
    auto ip = std::unique(scores.begin(), scores.end()); 
    scores.resize(std::distance(scores.begin(), ip)); 
    sort(scores.begin(),scores.end());
    int n=scores.size();
    cout<<"Scores Size : "<<n<<endl;
    for(int i=0;i<m;i++)
    {
        int x=alice[i];
        auto loc=upper_bound(scores.begin(),scores.end(),x);
        cout<<scores.size()-(loc-scores.begin())+1<<" "; 
    }
    cout<<endl;
    return scores;
}
int main()
{
    int n,m;
    cin>>n;
    vector <int> scores(n);
    for(int i=0;i<n;i++)
    {
        cin>>scores[i];
    }
    cin>>m;
    vector <int> alice(m);
    for(int i=0;i<m;i++)
    {
        cin>>alice[i];
    }
    vector <int> res=climbingLeaderboard(scores,alice);
    cout<<"Result : ";
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
    }
    cout<<endl;
}