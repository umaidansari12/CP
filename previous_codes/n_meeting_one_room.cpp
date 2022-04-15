#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct meeting {
	int start;
	int finish;
};

bool comparator(struct meeting a, struct meeting b)
{
	return a.finish < b.finish;
}
int maxMeetings(int start[], int end[], int n) {
	// Your code her
	vector<meeting> a(n);
	for (int i = 0; i < n; i++)
	{
		a[i].start = start[i];
		a[i].finish = end[i];
	}
	sort(a.begin(), a.end(), comparator);
	int e = a[0].finish, count = 1;
	for (int i = 1; i < n; i++)
	{
		if (a[i].start > e)
		{
			count++;
			e = a[i].finish;
		}
	}
	return count;
}

struct meeting {
	int start;
	int end;
	int pos;
};
bool comparator(struct meeting m1, meeting m2)
{
	if (m1.end < m2.end) return true;
	else if (m1.end > m2.end) return false;
	else if (m1.pos < m2.pos) return true;
	return false;
}
void maxMeetings(int s[], int e[], int n) {
	struct meeting meet[n];
	for (int i = 0; i < n; i++) {
		meet[i].start = s[i], meet[i].end = e[i], meet[i].pos = i + 1;
	}

	sort(meet, meet + n, comparator);

	vector<int> answer;

	int limit = meet[0].end;
	answer.push_back(meet[0].pos);

	for (int i = 1; i < n; i++) {
		if (meet[i].start > limit) {
			limit = meet[i].end;
			answer.push_back(meet[i].pos);
		}
	}
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}

}

bool cmp(pair<int, int> a, pair<int, int> b)
{
	return (a.second < b.second);
}

void n_meeting_one_room(vector<pair<int, int>> a, int n)
{
	unordered_map<int, int> idx;
	for (int i = 0; i < n; i++)
	{
		if (idx[a[i].second] == 0)
			idx[a[i].second] = i + 1;
	}
	sort(a.begin(), a.end(), cmp);
	cout << idx[a[0].second] << " ";
	int e = a[0].second;
	for (int i = 1; i < n; i++)
	{
		if (a[i].first >= e)
		{
			cout << idx[a[i].second] << " ";
			e = a[i].second;
		}
	}
	cout << endl;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		vector<pair<int, int>> a;
		vector<int> s(n), e(n);
		for (int i = 0; i < n; i++)
		{
			cin >> s[i];

		}
		for (int i = 0; i < n; i++)
		{
			cin >> e[i];
		}
		for (int i = 0; i < n; i++)
			a.push_back(make_pair(s[i], e[i]));
		n_meeting_one_room(a, n);
	}


	return 0;
}