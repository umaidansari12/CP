bool check(int index, int n, string S) {
	if (index >= (n / 2))
		return true;
	if (S[index] != S[n - index - 1])
		return false;
	return check(index + 1, n, S);
}

int isPalindrome(string S)
{
	// Your code goes here
	int n = S.size();
	return check(0, n, S);
	int n = S.size();
	for (int i = 0; i < (n / 2); i++)
	{
		if (S[i] != S[n - i - 1])
			return 0;
	}
	return 1;
}