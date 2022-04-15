#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string biggerIsGreater(string w) {
	int n = w.size(), ind1 = n - 2;
	while (ind1 >= 0 && w[ind1] >= w[ind1 + 1])
		ind1--;
	if (ind1 < 0)
		return "no answer";
	else
	{
		int ind2 = n - 1;
		while (ind2 > ind1 && w[ind2] <= w[ind1])
			ind2--;
		swap(w[ind1], w[ind2]);
		reverse(w.begin() + ind1 + 1, w.end());
	}

	return w;

}


int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		cout << biggerIsGreater(s) << endl;
	}


	return 0;
}