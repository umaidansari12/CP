#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeTrailingZeros(string num) {
        int index = num.size() - 1;
        for (int i = index; i >= 0; i--) {
            if (num[i] != '0') {
                index = i;
                break;
            }
        }
        string answer = "";
        for (int idx = 0; idx <= index; idx++) {
            answer += num[idx];
        }
        return answer;
    }
};


int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.removeTrailingZeros(s) << endl;
    }
}