// #include <bits/stdc++.h>

// using namespace std;

// void helper(int y, int x, unordered_map<int, int> &unique) {
// 	if (y == 0 or unique[x] != 0) {
// 		unique[x] += 1;
// 		return;
// 	}
// 	unique[x] += 1;
// 	helper(y - 1, x + 2, unique);
// 	helper(y - 1, x - 1, unique);
// }

// int main() {
// 	int T;
// 	cin >> T;
// 	while (T--) {
// 		int y;
// 		cin >> y;
// 		unordered_map<int, int> unique;
// 		helper(y, 0, unique);
// 		cout << unique.size() << endl;
// 	}
// }

// TC - O(ylogy);
// #include <bits/stdc++.h>

// using namespace std;

// void helper(int y, int x, set<int> &unique) {
// 	if (y == 0) {
// 		cout << "34->" << x << endl;
// 		unique.insert(x);
// 		return;
// 	}
// 	cout << "37->" << x << endl;
// 	unique.insert(x);
// 	helper(y - 1, x + 2, unique);
// 	helper(y - 1, x - 1, unique);
// }

// int main() {
// 	int T;
// 	cin >> T;
// 	while (T--) {
// 		int y;
// 		cin >> y;
// 		cout <<  << endl;
// 		// set<int> unique;
// 		// helper(y, 0, unique);
// 		// cout << unique.size() << "\n----------------" << endl;
// 	}
// }

#include <bits/stdc++.h>

using namespace std;

void helper(int y, int x, unordered_map<int, int> &unique) {
	if (y == 0 or unique[x] != 0) {
		unique[x] += 1;
		return;
	}
	unique[x] += 1;
	helper(y - 1, x + 2, unique);
	helper(y - 1, x - 1, unique);
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int y;
		cin >> y;
// 		unordered_map<int, int> unique;
// 		helper(y, 0, unique);
// 		cout << unique.size() << endl;
// cout<<pow(3,y)<<endl
		if (y == 0)
			cout << 1 << endl;
		else
			cout << 3 * y << endl;
	}
}