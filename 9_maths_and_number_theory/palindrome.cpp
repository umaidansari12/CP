
class Solution
{
public:
	string is_palindrome(int n)
	{
		// Code here.
		int revNum = 0, num = n;
		while (num > 0) {
			revNum = revNum * 10 + num % 10;
			num /= 10;
		}
		return n == revNum ? "Yes" : "No";
	}
};