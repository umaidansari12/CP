#include <bits/stdc++.h>

using namespace std;

long long int atMostK(string s, int k) {
    long long int res = 0;
    int i = 0, count[26] = {0};
    for (int j = 0; j < s.size(); j++) {
        if (!count[s[j] - 'a']++)
            k--;
        while (k < 0) {
            if (!--count[s[i] - 'a'])
                k++;
            i++;
        }
        res += (j - i + 1);
    }
    return res;
}

int main() {
    int t = 1;
    while (t--) {
        string s;
        int k;
        cin >> s >> k;
        cout << atMostK(s, k) << endl;
    }
    return 0;
}