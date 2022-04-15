#include<bits/stdc++.h>
using namespace std;

//str is the input the string
string compressString(const string &str) {
    //complete the function to return output string
    int n = str.size();
    string res;
    for (int i = 0; i < n; i++)
    {
        int count = 1;
        while (i < n - 1 && str[i] == str[i + 1])
        {
            count++;
            i++;
        }
        res += (str[i] + to_string(count));
    }
    return res.size() < n ? res : str;
}


int main()
{
    ios_base :: sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        cout << compressString(s) << endl;
    }


    return 0;
}