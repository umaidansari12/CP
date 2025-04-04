class Solution {
public:
  string armstrongNumber(int n) {
    // code here
    int num = n, armstrong_num = 0;
    while (num > 0) {
      armstrong_num += (pow(num % 10, 3));
      num /= 10;
    }
    return armstrong_num == n ? "Yes" : "No";
  }
};