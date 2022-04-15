class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> o, e;
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] % 2)
                o.push_back(A[i]);
            else
                e.push_back(A[i]);
        }
        int index = 0;
        for (int i = 0; i < e.size(); i++)
            A[index++] = e[i];
        for (int i = 0; i < o.size(); i++)
            A[index++] = o[i];
        return A;

    }
};

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int i = 0, j = A.size() - 1;
        while (i <= j)
        {
            if (A[i] % 2 == 0)
                i++;
            else
                swap(A[i], A[j--]);
        }
        return A;

    }
};