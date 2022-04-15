class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int aVal = 0, aCarry = 1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            aVal = digits[i] + aCarry;
            digits[i] = aVal % 10;
            aCarry = aVal / 10;
        }
        if (aCarry > 0) {
            digits.insert(digits.begin(), aCarry);
        }
        return digits;

    }
};

class Solution {
public:
    vector<int> increment(vector<int> arr , int N) {
        // code here
        vector<int> ans;
        int carry = 1;
        for (int i = N - 1; i >= 0; i--)
        {
            int sum = arr[i] + carry;
            carry = sum / 10;
            sum %= 10;
            ans.push_back(sum);
        }
        if (carry)
            ans.push_back(carry);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

