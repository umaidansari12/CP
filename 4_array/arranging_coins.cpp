class Solution {
public:
    int arrangeCoins(int n) {
        int total = n, cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (total < i)
                break;
            total -= i;
            cnt++;
        }
        return cnt;

    }
};