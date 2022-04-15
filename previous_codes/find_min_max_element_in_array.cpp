pair<long long, long long> getMinMax(long long a[], int n) {
	long long mx = LLONG_MIN, mn = LLONG_MAX;
	for (int i = 0; i < n; i++)
	{
		mx = max(mx, a[i]);
		mn = min(mn, a[i]);
	}
	return make_pair(mn, mx);

}