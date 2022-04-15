
#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n)
{
    if (n == 1)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    /*vector<bool> prime(10001, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= 10000; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= 10000; j += i)
            {
                prime[j] = false;
            }
        }
    }*/
    int T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        int n = s.size();
        bool f1 = false, f2 = true;
        unordered_map<char, int> m;
        set<char> se;
        for (int i = 0; i < n; i++)
        {
            se.insert(s[i]);
            m[s[i]]++;
        }
        int d = se.size();
        if (isPrime(d))
        {
            f1 = true;
        }
        /*for (int i = 0; i < n; i++)
        {
            //cout << s[i] << " " << m[s[i]] << " " << prime[m[s[i]]];
            if (prime[m[s[i]]] == false)
            {
                f = 1;
                break;
            }
        }*/
        //cout << endl;
        //cout << m.size();
        for (auto i : m)
        {
            if (!isPrime(i.second))
            {
                f2 = false;
            }
        }
        if (f1 && f2)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
