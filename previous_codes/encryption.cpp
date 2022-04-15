#include<bits/stdc++.h>

using namespace std;


string encryption(string s) {
    int n=s.size();
    int row=floor(sqrt(n));
    int column=ceil(sqrt(n));
    if(row*column < n)
    {
        row=column;
    }
    cout<<n<<" "<<row<<" "<<column<<endl;
    string a[column];
    int k=0;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            a[i].push_back(s[k]);
            k++;
        }
    }
    string b[column];
    k=0;
    for(int i=0;i<column;i++)
    {
        for(int j=0;j<row;j++)
        {
            
            b[i].push_back(a[j][i]);
            k++;
        }
    }
    string c;
    for(string f:b)
    {
        for(char d:f)
        {
            if(d==' ')
            {
                continue;
            }
            else
            {
                c.push_back(d);
            }
        }
        c.push_back(' ');
    }
    string d;
    for(int i=0;i<c.size()-1;i++)
    {
        if(c[i]==0)
        {
            continue;
        }
        else
        {
            d.push_back(c[i]);
        }
    }
    return d;
}

int main()
{
    string s;
    cin>>s;
    string res=encryption(s);
    cout<<res<<endl;
    for(char a:res)
    {
        int b=a;
        cout<<b<<"->";
    }
}



