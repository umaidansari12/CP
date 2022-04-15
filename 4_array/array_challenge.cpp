#include <bits/stdc++.h>

using namespace std;
using ll = long long;


string ArrayChallenge(string strArr[], int arrLength) {
	string s1 = "", s2 = "";
	for (int i = 0; i < strArr[0].size(); i++) {
		if (strArr[0][i] >= 'a' and strArr[0][i] <= 'z') s1 += strArr[0][i];
		else if (strArr[0][i] == '-' and strArr[0][i + 1] == 'B') {
			s1.pop_back();
		}
	}

	for (int i = 0; i < strArr[1].size(); i++) {
		if (strArr[1][i] >= 'a' and strArr[1][i] <= 'z') s2 += strArr[1][i];
		else if (strArr[1][i] == '-' and strArr[1][i + 1] == 'B') {
			s2.pop_back();
		}
	}
	if (s1.compare(s2) == 0)
		return "true";
	return "false";
}






int ArrayChallenge1(int arr[], int arrLength) {
	int pos = -1;
	for (int i = 0; i < arrLength; i++) {
		if (arr[i] == 1)
			pos = i;
	}
	int ans = INT_MAX;
	for (int i = pos - 1; i >= 0; i--) {
		if (arr[i] == 2) {
			ans = min(ans, (pos - i) + 1);
			break;
		}
	}
	for (int i = pos + 1; i < arrLength; i++) {
		if (arr[i] == 2) {
			ans = min(ans, (i - pos) + 1);
			break;
		}
	}
	return ans == INT_MAX ? 0 : ans - 1;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string a[2];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		cout << ArrayChallenge(a, n) << endl;
	}


	return 0;
}