#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//Using deque , Try to maintain the order of pages according to least recently used pages.

class Solution
{

public:
	int pagefaults(int pages[], int n, int capacity)
	{
		deque<int> q;
		int ans = 0, x = 0;
		unordered_map<int, int> mp, mp2;
		for (int i = 0; i < n; i++)
		{

			if (mp.find(pages[i]) == mp.end()) {
				ans++;
				mp2[pages[i]]++;
				q.push_back(pages[i]);
				mp[pages[i]];
			}
			else
			{
				mp2[pages[i]]++;
				q.push_back(pages[i]);
				continue;
			}
			if (capacity == x)
			{
				while (q.size())
				{
					int z = q.front();
					q.pop_front();
					mp2[z]--;
					if (mp2[z] == 0) {
						mp.erase(z);
						break;
					}
				}
			}
			else x++;
		}
		return ans;


	}
};

class Solution
{

public:
	int pagefaults(int pages[], int n, int capacity)
	{
		// code here
		unordered_set<int> s;

		// To store least recently used indexes
		// of pages.
		unordered_map<int, int> indexes;

		// Start from initial page
		int page_faults = 0;
		for (int i = 0; i < n; i++)
		{
			// Check if the set can hold more pages
			if (s.size() < capacity)
			{
				// Insert it into set if not present
				// already which represents page fault
				if (s.find(pages[i]) == s.end())
				{
					s.insert(pages[i]);

					// increment page fault
					page_faults++;
				}

				// Store the recently used index of
				// each page
				indexes[pages[i]] = i;
			}

			// If the set is full then need to perform lru
			// i.e. remove the least recently used page
			// and insert the current page
			else
			{
				// Check if current page is not already
				// present in the set
				if (s.find(pages[i]) == s.end())
				{
					// Find the least recently used pages
					// that is present in the set
					int lru = INT_MAX, val;
					for (auto it = s.begin(); it != s.end(); it++)
					{
						if (indexes[*it] < lru)
						{
							lru = indexes[*it];
							val = *it;
						}
					}

					// Remove the indexes page
					s.erase(val);

					// insert the current page
					s.insert(pages[i]);

					// Increment page faults
					page_faults++;
				}

				// Update the current page index
				indexes[pages[i]] = i;
			}
		}

		return page_faults;


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
		int n, capacity;
		cin >> n >> capacity;
		vector<int> pages(n);
		for (int i = 0; i < n; i++)
			cin >> pages[i];
		queue<int> q;
		int i = 0, faults = capacity;
		for (i = 0; i < capacity; i++)
			q.push(pages[i]);
		for (; i < n; i++)
		{
			auto j = q.front();
			if (j == pages[i])
				continue;
			else
			{
				q.push(pages[i]);
				q.pop();
				faults++;
			}
		}
		cout << faults << endl;

	}


	return 0;
}