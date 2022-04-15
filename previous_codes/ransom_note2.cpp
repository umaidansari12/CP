#include <bits/stdc++.h>

using namespace std;

void checkMagazine(vector<string> magazine, vector<string> note) {
    int m=magazine.size(),n=note.size(),flag=0;
    map<string,int> ma,no;
    for(int i=0;i<m;i++)
    {
        ma[magazine[i]]++;
    }
    for(int i=0;i<n;i++)
    {
        no[note[i]]++;
    }
    auto i=note.begin();
    while(i!=note.end())
    {
        if(no[*i]<=ma[*i] && no[*i]!=0)
        {
            flag++; 
            i++;           
            
        }
        else
        {
            break;
        }
        
    }
    if(flag==n)
    {
            cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }


}

int main()
{
    return 0;
}