class Solution {
public:
    int splitNum(int num) {
        vector<int> digits;

        while (num > 0) {
            digits.push_back(num % 10);
            num /= 10;
        }
        sort(digits.begin(), digits.end());
        long long int num1 = 0, num2 = 0, _size = digits.size();
        for (int i = 0; i < _size; i++) {
            if (i % 2 == 0) {
                num1 = num1 * 10 + digits[i];
            }
            else {
                num2 = num2 * 10 + digits[i];
            }
        }

        return num1 + num2;

    }
};