class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if (n < 3)
            return false;
        for (int i = 1; i < n - 1; i++)
        {
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
            {
                int j = i - 1;
                while (j >= 0 and arr[j] < arr[j + 1])
                    j--;
                int k = i + 1;
                while (k < n - 1 and arr[k] > arr[k + 1])
                    k++;
                if ((k - j) == n)
                    return true;
            }
        }
        return false;
    }
};