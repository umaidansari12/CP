#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Point {
public:
	int x, y;
	Point()
	{

	}
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};

class Compare {
public:
	bool operator()(const Point p1, const Point p2)
	{
		if (p1.x == p2.x)
			return p1.y < p2.y;
		return p1.x < p2.x;
	}
};

int countRectangles(vector<Point> points, int n)
{
	set<Point, Compare> s;
	for (Point p : points)
		s.insert(p);
	int ans = 0;
	for (auto it = s.begin(); it != prev(s.end()); it++)
	{
		for (auto jt = next(it); jt != s.end(); jt++)
		{
			Point p1 = *it;
			Point p2 = *jt;
			if (p1.x == p2.x or p1.y == p2.y)
				continue;
			Point p3(p1.x, p2.y);
			Point p4(p2.x, p1.y);
			if (s.find(p3) != s.end() && s.find(p4) != s.end())
			{
				ans++;
			}
		}
	}
	return ans / 2;
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
		int n, x, y;
		cin >> n;
		vector<Point> points(n);
		for (int i = 0; i < n; i++)
		{
			cin >> x >> y;
			Point p(x, y);
			points.push_back(p);
		}
		cout << countRectangles(points, n) << endl;
	}


	return 0;
}