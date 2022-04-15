#include <bits/stdc++.h>

using namespace std;
string caesar(string s,int k)
{
    for(auto &c: s){
        if(isalpha(c)){
            char a = isupper(c)?'A':'a';
            c= a + (c - a + k)%26;//
        }
    }    
    return s;  
}
string caesarCipher(string s, int k) {
    int n =s.size();
    char c;
    k=k%26;
    string st;
    for (int i = 0; i < n; i++)
            {
                if (isupper(s[i]))
                {
                    c = s[i] + k;
                    if (c > 90)
                    {
                        c = 64+(c%90);
                    }

                    st.push_back(c);
                }
                else if (islower(s[i]))
                {
                    c = s[i] + k;
                    if (c > 122)
                    {
                        c = 96+(c%122);
                    }

                     st.push_back(c);
                }
                else
                {
                     st.push_back(s[i]);
                }
            }
cout << st;
return st;
}


int main()
{
    string s;
    int k;
    cin>>s;
    cin>>k;
    s=caesarCipher(s,k);
    cout<<s;
}