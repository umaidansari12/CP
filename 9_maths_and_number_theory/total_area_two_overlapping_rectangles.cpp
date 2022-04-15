#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*
We basically add areas of two rectangles. This includes the intersecting part twice, so we subtract the area of intersecting part.

Total Area = (Area of 1st rectangle +
              Area of 2nd rectangle) -
              Area of Intersecting part
Area of Rectangle = x_distance * y_distance

Where,
x_distance for 1st rectangle = abs(l1.x – r1.x)
y_distance for 1st rectangle = abs(l1.y – r1.y)

Similarly, we can compute area of 2nd rectangle.

For area of intersecting part,
x_distance for intersecting rectangle = min(r1.x, r2.x) – max(l1.x, l2.x)
y_distance for 1st rectangle = min(r1.y, r2.y) – max(l1.y, l2.y)

If the x_distance or y_distance is negative, then the two rectangles do not intersect. In that case, overlapping area is 0.*/

class Point {
public:
	int x, y;
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

int AreaReactangle(Point l1, Point l2, Point r1, Point r2) {
	int areaFirst = abs(l1.x - r1.x) * abs(l1.y - r1.y);
	int areaSecond = abs(l2.x - r2.x) * abs(l2.y - r2.y);

	int x_dist = min(r1.x, r2.x) - max(l1.x, l2.x);
	int y_dist = min(r1.y, r2.y) - max(l1.y, l2.y);
	int areaCommon = 0;
	if (x_dist > 0 and y_dist > 0) {
		areaCommon = x_dist * y_dist;
	}
	return (areaFirst + areaSecond - areaCommon);
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int x, y;
		cin >> x >> y;
		Point l1(x, y);
		cin >> x >> y;
		Point r1(x, y);
		cin >> x >> y;
		Point l2(x, y);
		cin >> x >> y;
		Point r2(x, y);

		cout << AreaReactangle(l1, l2, r1, r2) << endl;

	}

	return 0;
}