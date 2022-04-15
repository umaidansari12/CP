#include <bits/stdc++.h>

using namespace std;

int marsExploration(string s) {
    int count=0;
    for(int i=0;i<s.size();i=i+3)
    {
        string sb=s.substr(i,3);
        cout<<sb<<endl;
        if(sb.compare("SOS")!=0)
        {
            count++;
        }
    }

return count;
}

int main()
{
    string s;
    cin >> s;
    int res=marsExploration(s);
    cout<<res<<endl;
    return 0;
}

