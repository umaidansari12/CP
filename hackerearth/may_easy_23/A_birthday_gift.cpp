#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int x, y, z;
        cin >> x >> y >> z;
        int amount_needed = y - x;
        long long int amount_saved = z * (z + 1) / 2;
        if (amount_needed <= amount_saved)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}