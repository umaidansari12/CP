class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> freqCounter(2001, 0);
        for (int i = 0; i < arr.size(); i++) {
            freqCounter[arr[i]]++;
        }
        int missingCounter = 0;
        for (int i = 1; i <= 2000; i++) {
            if (freqCounter[i] == 0) {
                missingCounter++;
            }
            if (missingCounter == k) {
                return i;
            }
        }
        return 0;
    }
};
