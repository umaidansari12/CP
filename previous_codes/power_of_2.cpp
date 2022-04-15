bool isPowerofTwo(long long n) {

	// Your code here
	if (n == 0)
		return false;
	return (ceil(log2(n))) == (floor(log2(n)));

}

bool isPowerOfTwo(int n)
{
	if (n == 0)
		return 0;
	while (n != 1)
	{
		if (n % 2 != 0)
			return 0;
		n = n / 2;
	}
	return 1;
}