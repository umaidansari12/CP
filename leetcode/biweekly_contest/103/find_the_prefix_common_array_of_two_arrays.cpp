#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int _size = A.size();
        unordered_map<int, int> freq;
        vector<int> C(_size, 0);
        int count = 0;
        for (int i = 0; i < _size; i++) {
            freq[A[i]]++;
            freq[B[i]]++;
            if (A[i] != B[i]) {
                int local_count = 0;
                for (auto ele : freq) {
                    if (ele.second == 2)
                        local_count += 1;
                }
                count = local_count;
            }
            else {
                count++;
            }
            C[i] = count;
        }
        return C;
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;
        vector<int> A(a, 0), B(b, 0);
        for (int i = 0; i < a; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < b; i++) {
            cin >> B[i];
        }
        Solution ob = Solution();
        vector<int> ans = ob.findThePrefixCommonArray(A, B);
        for (auto ele : ans)
            cout << ele << " ";
        cout << endl;
    }
    return 0;
}