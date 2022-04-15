#include <bits/stdc++.h>

using namespace std;

int cookies(int k, vector<int> A) {
	set <int> a;
	for (auto i : A)
	{
		a.insert(i);
	}
	int count = 0;
	while (a.size() > 1 && (*(a.begin()) < k))
	{
		int i = *(a.begin());
		cout << i << endl;
		a.erase(i);
		int i2 = *(a.begin());
		cout << i2 << endl;
		int r = (1 * (i)) + (2 * (i2));
		cout << r << endl;
		a.erase(i2);
		a.insert(r);
		count++;
	}
	return count;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	/*cin.tie(NULL);
	cout.tie(NULL);*/
	int n, k;
	cin >> n >> k;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	cout << cookies(k, a) << endl;


	return 0;
}