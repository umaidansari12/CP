// CPP program to find maxium number of meetings
#include <bits/stdc++.h>
using namespace std;

// Structure for storing starting time,
// finishing time and position of meeting.
struct meeting {
	int start;
	int end;
	int pos;
};

// Comparator function which can compare
// the second element of structure used to
// sort pairs in increasing order of second value.
bool comparator(struct meeting m1, meeting m2)
{
	return (m1.end < m2.end);
}

// Function for finding maximum meeting in one room
void maxMeeting(vector<int> s, vector<int> f, int n)
{
	struct meeting meet[n];
	for (int i = 0; i < n; i++)
	{
		// Starting time of meeting i.
		meet[i].start = s[i];

		// Finishing time of meeting i
		meet[i].end = f[i];

		// Original position/index of meeting
		meet[i].pos = i + 1;
	}

	// Sorting of meeting according to their finish time.
	sort(meet, meet + n, comparator);

	// Vector for storing selected meeting.
	vector<int> m;

	// Initially select first meeting.
	m.push_back(meet[0].pos);

	// time_limit to check whether new
	// meeting can be conducted or not.
	int time_limit = meet[0].end;

	// Check for all meeting whether it
	// can be selected or not.
	for (int i = 1; i < n; i++) {
		if (meet[i].start >= time_limit)
		{
			// Push selected meeting to vector
			m.push_back(meet[i].pos);

			// Update time limit.
			time_limit = meet[i].end;
		}
	}

	// Print final selected meetings.
	for (int i = 0; i < m.size(); i++) {
		cout << m[i] << " ";
	}
	cout << endl;
}

// Driver code
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		vector<int> s(n);
		vector<int> f(n);
		for (int i = 0; i < n; i++)
		{
			cin >> s[i];
		}
		for (int i = 0; i < n; i++)
		{
			cin >> f[i];
		}
		maxMeeting(s, f, n);
	}


	return 0;
}