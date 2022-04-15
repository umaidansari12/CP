#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int CountBalls(int l, int b, int h, int r)
{
	long long int cuboid = l * b * h;
	long long int ball = 4 * r * r * r;
	return cuboid / ball;

}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int l, b, h, r;
	cin >> l >> b >> h >> r;
	cout << CountBalls(l, b, h, r) << endl;


	return 0;
}