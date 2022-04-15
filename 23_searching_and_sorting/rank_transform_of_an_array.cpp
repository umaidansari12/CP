class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int> m;
        for (int i = 0; i < arr.size(); i++) {
            m[arr[i]]++;
        }
        int rank = 1;
        for (auto i : m) {
            m[i.first] = rank;
            rank++;
        }
        vector<int> res;
        for (auto i : arr) {
            res.push_back(m[i]);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> A(arr);
        sort(A.begin(), A.end());
        unordered_map<int, int> rank;
        for (int& a : A)
            rank.emplace(a, rank.size() + 1);
        for (int i = 0; i < A.size(); ++i)
            A[i] = rank[arr[i]];
        return A;
    }
};