class Solution {
public:
    int gcd(int a, int b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    int findGCD(vector<int>& nums) {
        int mi = INT_MAX, ma = INT_MIN;
        for (auto num : nums)
        {
            mi = min(mi, num);
            ma = max(ma, num);
        }
        return gcd(mi, ma);

    }
};