#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class comp {
public:
	bool operator() (pair<int, int> a, pair<int, int> b) {
		int x1 = a.first * a.first;
		int x2 = b.first * b.first;
		int y1 = a.second * a.second;
		int y2 = b.second * b.second;
		if ((x1 + y1) == (x2 + y2))
			return x1 < x2;
		return (x1 + y1) > (x2 + y2);
	}
};


void closestPoints(vector<pair<int, int>> &points, int k) {
	priority_queue < pair<int, int> , vector<pair<int, int> > , comp> pq;
	for (int i = 0; i < points.size(); i++) {
		pq.push({points[i].first, points[i].second});
	}
	while (k--) {
		cout << pq.top().first << " " << pq.top().second << endl;
		pq.pop();
	}
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
		vector<pair<int, int> > points;
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			points.push_back({x, y});
		}
		int k;
		cin >> k;
		closestPoints(points, k);
	}



	return 0;
}