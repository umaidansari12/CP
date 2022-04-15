#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        vector<string> a(2);
        for (int i = 0; i < 2; i++)
            cin >> a[i];
        vector<int> cnt(256, INT_MAX);
        for (auto i : a)
        {
            vector<int> cnt1(256, 0);
            for (auto s : i)
                cnt1[s]++;
            for (int i = 0; i < 256; i++)
                cnt[i] = min(cnt[i], cnt1[i]);
        }
        string s;
        for (int i = 0; i < 256; i++)
        {
            for (int j = 0; j < cnt[i]; j++)
                s.push_back(i);
        }
        if (s.size() == 0)
            cout << "nil\n";
        else
            cout << s << endl;
    }
}

///can be solved using set also
/*In the given question, no matter what the frequency of a particular upper or lower case alphabet in the strings S and R, we need to find the letters common in both of them, treating upper and lower cases differently. Hence, the simplest way to do so is it iterate over either of the two strings and check the occurence of each letter in a string, in the other string. To avoid duplication, we can use the STL container set, that stores unique elements in sorted order. Hence on inserting the common elements in a set, it will automatically get stored in ascending order of their ASCII values. The contents of the set can then be displayed as output.*/
/*#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string se,r;
        cin>>se>>r;
        set<char> s;
        for(auto i:se)
            for(auto j:r)
                if(i==j)
                s.insert(i);

        for(auto i:s)
        cout<<i;
        if(s.size()==0)
        cout<<"nil";
        cout<<endl;


    }
}*/