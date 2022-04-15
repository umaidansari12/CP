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

int countTriangles(vector<Point>points, int n)
{
	unordered_map<int, int> freq_x;
	unordered_map<int, int> freq_y;
	for (auto p : points)
	{
		freq_x[p.x]++;
		freq_y[p.y]++;
	}
	int ans = 0;
	for (auto p : points)
	{
		ans += (freq_x[p.x] - 1) * (freq_y[p.y] - 1);
	}
	return ans;
}

int countTrianglesBrute(vector<Point> points, int n)
{
	int ans = 0;
	for (int i = 0; i < n - 1; i++)
	{
		int count_x = 1, count_y = 1;
		for (int j = i + 1; j < n; j++)
		{
			if (points[j].x == points[i].x)
				count_x++;
			if (points[j].y == points[i].y)
				count_y++;
		}
		cout << count_x << " " << count_y << endl;
		ans += (count_x * count_y);
	}
	return ans;

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
		vector<Point> points;
		for (int i = 0; i < n; i++)
		{
			cin >> x >> y;
			Point p(x, y);
			points.push_back(p);
		}
		cout << countTrianglesBrute(points, n) << endl;
	}


	return 0;
}