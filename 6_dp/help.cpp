#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int max_energy = -1001;
        int _size = energy.size();
        for (int i = 0; i < _size; i++) {
            int _energy = -1001;
            cout << i << "->";
            for (int j = i; j < _size; j = j + k) {
                if (_energy == -1001)
                    _energy = 0;
                _energy += (energy[j]);
                cout << _energy << ",";
            }
            cout << endl;
            max_energy = max(max_energy, _energy);
        }
        return max_energy;
    }
};


int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob = Solution();
        cout << ob.maximumEnergy(a, k) << endl;
    }
}