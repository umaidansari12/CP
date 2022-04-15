#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s="";
    int q;
    cin>>q;
    stack <string> st;
    st.push(s);
    while(q--)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            string s2;
            cin>>s2;
            if(s.size()==0)
            {
                s=s2;
            }
            else
            {
                s.append(s2);
            }
            s2.clear();
            st.push(s);
        }
        else if(t==2)
        {
            int k;
            cin>>k;
            while(k>0)
            {
                s.pop_back();
                k--;
            }
            if(s.size()==0)
            {
                st.push("");
            }
            else
            {
                st.push(s);
            }
        }
        else if(t==3)
        {
            int c;
            cin>>c;
            cout<<s[c-1]<<endl;
        }
        else if(t==4)
        {
            st.pop();
            s=st.top();
        }
    }
}