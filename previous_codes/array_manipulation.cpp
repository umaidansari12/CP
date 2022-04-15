
long arrayManipulation(int n, vector<vector<int>> queries) {
	vector <long long int> res(n + 1, 0);
	for (int i = 0; i < queries.size(); i++)
	{
		int a = queries[i][0] - 1, b = queries[i][1], k = queries[i][2];
		for (int j = a; j < b; j++)
		{
			res[j] += k;
		}
	}
	return *max_element(res.begin(), res.end());

}

long arrayManipulation(int n, vector<vector<int>> queries) {
	vector <long long int> res(n + 1, 0);
	for (int i = 0; i < queries.size(); i++)
	{
		long long int a = queries[i][0], b = queries[i][1], k = queries[i][2];
		res[a] += k;
		if ((b + 1) <= n)
			res[b + 1] -= k;
	}
	long x = 0, m = 0;
	for (int i = 1; i <= n; i++)
	{
		x = x + res[i];
		m = max(x, m);
	}
	return m;

}