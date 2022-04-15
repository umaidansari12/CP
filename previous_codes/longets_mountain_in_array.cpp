class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if (n < 3)
            return 0;
        int ans = 0, i = 0;
        for (int i = 1; i < n - 1; i++)
        {
            if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1])
            {
                int j = i - 1;
                while (j >= 0 && arr[j] < arr[j + 1])
                    j--;
                int k = i + 1;
                while (k < n - 1 && arr[k] > arr[k + 1])
                    k++;
                ans = max(ans, k - j);
            }
        }
        return ans;
    }
};

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if (n < 0)
            return 0;
        int ans = 0;
        for (int i = 1; i < n - 1;)
        {
            if (arr[i] > arr[i - 1] and arr[i] > arr[i + 1])
            {
                int j = i, cnt = 1;
                while (j >= 1 and arr[j] > arr[j - 1])
                {
                    j--;
                    cnt++;
                }
                while (i < n - 1 && arr[i] > arr[i + 1])
                {
                    i++;
                    cnt++;
                }
                ans = max(ans, cnt);
            }
            else
                i++;
        }
        return ans;
    }
};