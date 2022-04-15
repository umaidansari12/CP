#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
	int n, m, q;
	cin >> n >> m >> q;
	vector<int> seats(n + 1, 0);
	bool possible = true;
	int countPassengers = 0;
	for (int i = 0; i < q; i++)
	{
		char sign;
		cin >> sign;
		int number;
		cin >> number;
		if (sign == '+')
		{
			if (seats[number] == 0)
			{
				countPassengers++;
				seats[number] = 1;
				if (countPassengers > m)
					possible = false;
			}
			else if (seats[number] == 2)
			{
				possible = false;
			}
		}
		else if (sign == '-')
		{
			if (seats[number] == 0)
			{
				possible = false;
			}
			else if (seats[number] == 1)
			{
				countPassengers--;
				seats[number] = 2;
			}
		}
	}
	if (!possible) {
		cout << "Inconsistent\n";
	}
	else cout << "Consistent\n";
}

//same solution above without return statement return was creating TLE

string solve1()
{
	int n, m, q;
	cin >> n >> m >> q;
	vector<int> seats(n + 1, 0);
	int countPassengers = 0;
	for (int i = 0; i < q; i++)
	{
		string sign = "";
		int number;
		cin >> sign >> number;
		//cout << sign << " " << number << "\n";
		if (sign == "+")
		{
			countPassengers++;
			if (seats[number] == 0)
			{
				seats[number] = 1;
			}
			else if (seats[number] == 2)
			{
				return "Inconsistent";
			}
		}
		else if (sign == "-")
		{
			countPassengers--;
			if (seats[number] == 0)
			{
				return "Inconsistent";
			}
			else if (seats[number] == 1)
			{
				seats[number] = 2;
			}
		}
		if (countPassengers > m)//or countPassengers < 0)
			return "Inconsistent";
	}
	return "Consistent";
}


void solve()
{
	int n, m, q;
	cin >> n >> m >> q;
	bool possible = true;
	set<int> bus;
	while (q--) {
		char sign;
		cin >> sign;
		int number;
		cin >> number;
		if (sign == '+')
		{
			if (bus.find(number) != bus.end()) {
				possible = false;
			}
			else {
				bus.insert(number);
				if (bus.size() > m)
					possible = false;
			}
		}
		else if (sign == '-') {
			if (bus.find(number) == bus.end()) {
				possible = false;
			}
			else {
				bus.erase(number);
			}
		}
	}
	if (!possible) {
		cout << "Inconsistent\n";
	}
	else cout << "Consistent\n";
}

string solve2()
{
	int n, m, q;
	cin >> n >> m >> q;
	bool possible = true;
	set<int> bus;
	while (q--) {
		char sign;
		cin >> sign;
		int number;
		cin >> number;
		if (sign == '+')
		{
			if (bus.find(number) == bus.end()) {
				bus.insert(number);
				if (bus.size() > m) {
					//possible = false;
					return "Inconsistent";
				}
			}
			else {
				//possible = false;
				return "Inconsistent";
			}
		}
		else if (sign == '-') {
			if (bus.find(number) != bus.end()) {
				bus.erase(number);
			}
			else {
				//possible = false;
				return "Inconsistent";
			}
		}
	}
// 	if (!possible) {
// 		return "Inconsistent";
// 	}
	return "Consistent";
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;

	while (t--) {
		//cout << solve() << '\n';
		solve();
	}


	return 0;
}