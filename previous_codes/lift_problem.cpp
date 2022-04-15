#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int solve(int N, int A, int B, int x, int y)
{
	if (A < 1 || A >= N)
		return 0;
	if (A == B)
		return 1;
	return 1 + max(solve(N, A + x, B, x, y), solve(N, A - y, B, x, y));
}
int minSteps(int N, int A, int B, int x, int y)
{
	//code here
	return solve(N, A, B, x, y);
}


//Use BFS
class Solution
{
public:
	int minSteps(int N, int A, int B, int x, int y)
	{

		queue<int> q;
		vector<int> steps(N + 1, -1);

		q.push(A);
		steps[A] = 0;

		while (!q.empty())
		{
			int curFloor = q.front();
			q.pop();
			if (curFloor + x <= N && steps[curFloor + x] == -1)
			{
				steps[curFloor + x] = 1 + steps[curFloor];
				q.push(curFloor + x);
			}
			if (curFloor - y >= 1 && steps[curFloor - y] == -1)
			{
				steps[curFloor - y] = 1 + steps[curFloor];
				q.push(curFloor - y);
			}
		}

		return steps[B];
	}
};
int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int n, a, b, x, y;
		cin >> n >> a >> b >> x >> y;
		cout << minSteps(n, a, b, x, y) << endl;
	}



	return 0;
}