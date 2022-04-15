
using namespace std;
using ll = long long;

int two_sum(vector<int> a, int n, int k)
{
	sort(a.begin(), a.end());
	int i = 0, j = n - 1, count = 0;
	while (i < j)
	{
		if (a[i] + a[j] == k)
		{
			count++;
			i++;
			j--;
		}
		else if (a[i] + a[j] > k)
		{
			j--;
		}
		else
		{
			i++;
		}
	}
	return count;
}

int getPairsCount(int arr[], int n, int k) {
	// code here
	map<int, int> m;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (m.find(k - arr[i]) != m.end())
		{
			count += m[k - arr[i]];
		}
		m[arr[i]]++;
	}
	return count;
}

int twoSum(vector<int>& a, int n, int k)
{
	int count = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] + a[j] == k)
			{
				count++;
			}
		}
	}
	return count;
}

int two_Sum(vector<int> &a, int n, int k)
{
	int count = 0;
	unordered_map<int, int> m;
	for (int i = 0; i < n; i++)
	{
		m[a[i]]++;
	}
	for (int i = 0; i < n; i++)
	{
		count += m[k - a[i]];
		if (k - a[i] == a[i])
			count--;
	}
	return count / 2;
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
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		cout << two_Sum(a, n, k) << endl;
	}


	return 0;
}