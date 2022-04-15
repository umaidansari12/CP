#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void calcCostOfCementing(int lengthRatio, int breadthRatio, int  perimeter, int widthWalkway, int ratePerSqM) {
	if (perimeter < 0)
	{
		cout << "Invalid Input\n";
		return;
	}
	long long int ratio = 2 * (lengthRatio + breadthRatio);
	long long int x = perimeter / ratio;

	long long int length = x * lengthRatio;
	long long int breadth = x * breadthRatio;

	long long int totalAreaCost = length * breadth * ratePerSqM;
	long long int lengthWalk = length - (2 * widthWalkway);
	long long int breadthWalk = breadth - (2 * widthWalkway);

	long long int walkWayCost = lengthWalk * breadthWalk * ratePerSqM;

	cout << (totalAreaCost - walkWayCost) << endl;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int l, b, p, w, r;
		cin >> l >> b >> p >> w >> r;
		calcCostOfCementing(l, b, p, w, r);
	}



	return 0;
}