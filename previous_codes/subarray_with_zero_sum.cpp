
using namespace std;
using ll = long long;

int maxlen(vector<int> a, int n)
{
	// Your code here
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = i; j < n; j++)
		{
			sum += a[j];
			if (sum == 0)
			{
				count = max(count, j - i + 1);
			}
		}
	}
	return count;
}

class Solution {
public:
	//Complete this function
	//Function to check whether there is a subarray present with 0-sum or not.
	bool subArrayExists(int arr[], int n)
	{
		//Your code here
		unordered_map<int, int> m;
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += arr[i];
			if (arr[i] == 0)
				return true;
			if (sum == 0)
				return true;
			if (m.find(sum) != m.end())
				return true;
			m[sum]++;
		}
		return false;
	}
};
bool maxLen(vector<int> a, int n)
{
	int sum = 0;
	unordered_map<int, int> presum;
	for (int i = 0; i < n; i++)
	{
		sum += a[i];
		if (a[i] == 0 && maxlen == 0) //edge case when the given element is 0 and maxlen is 0 then update it to 1 i.e length of subarray is 1
			return true;
		if (sum == 0)//edge case when the sum becomes 0
			return true;
		if (presum.find(sum) != presum.end())
		{
			return true;
		}
		else
		{
			presum[sum] = i;
		}
	}
	return false;
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
		int N;
		cin >> N;
		vector<int> a(N);
		for (int i = 0; i < N; i++)
		{
			cin >> a[i];
		}
		if (maxLen(a, N))
			cout << "Yes\n";
		else
			cout << "No\n";
	}


	return 0;
}