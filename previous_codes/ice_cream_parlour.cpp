#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*SAMPLE TEST CASES :

	Input :
	2
	4 5
	1 4 5 3 2
	4 4
	2 2 4 3

	Output :
	1 4
	1 2

*/

//Hashing Approach
//Time Complexity : O(n)
//Space Complexity : O(n)
vector<int> icecreamParlor(int m, vector<int> arr) {
	map<int, int> c;
	vector<int> r;
	int n = arr.size();
	for (int i = 0; i < n; i++)
	{
		if (c.find(m - arr[i]) != c.end())
		{
			r.push_back(c[m - arr[i]] + 1);
			r.push_back(i + 1);
			break;
		}
		c[arr[i]] = i;
	}
	return r;
}

//Naive Approach
//Time Complexity : O(n^2)
//Space Complexity : O(1)
vector<int> icecreamParlorNaive(int m, vector<int> arr) {

	vector<int> r;
	int n = arr.size();
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if ((arr[i] + arr[j]) == m)
			{
				r.push_back(i + 1);
				r.push_back(j + 1);
				return r;
			}
		}
	}
	return r;
}



int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int n, m;
		cin >> m >> n;
		vector<int> arr(n);
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		vector<int> res = icecreamParlor(m, arr);
		cout << res[0] << " " << res[1] << endl;

	}


	return 0;
}