#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {

public:
	int maxCandy(int height[], int n)
	{
		int l = 0 ;
		int h = n - 1;
		int max_area = 0;
		while (l < h) {
			max_area = max(max_area, min(height[l], height[h]) * (h - l - 1));
			if (height[l] < height[h])
				l++;
			else
				h--;
		}
		return max_area;
	}
};

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	return 0;
}