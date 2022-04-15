#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//

void decodeString(string s, int n) {
	int size = s.size();
	int row = n;
	int col = size / n;
	int idx = 0;
	vector<vector<char>> mat(row, vector<char>(col));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			mat[i][j] = s[idx++];
			// << mat[i][j] << " ";
		}
		//cout << endl;
	}

	for (int temp = 0; temp < col; temp++) {
		int i = 0;
		int j = temp;
		while (i < row and j < col) {

			if (mat[i][j] >= 'a' and mat[i][j] <= 'z') {
				cout << mat[i][j];
			}
			else if (mat[i][j] == '_') {
				cout << " ";
			}
			j++;
			i++;
		}
	}
	cout << endl;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int n;
		cin >> n;
		decodeString(s, n);
	}


	return 0;
}