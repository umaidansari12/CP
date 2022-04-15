#include <bits/stdc++.h>
using namespace std;

int marksTampering(vector<int>& marks, int k)
{

}

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> marks(n);
	for (int i = 0; i < n; i++) cin >> marks[i];
	int ans = marksTampering(marks, k);
	cout << ans << endl;
}