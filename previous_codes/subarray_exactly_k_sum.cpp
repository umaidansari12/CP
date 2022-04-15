
using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int n, s = 0, e = 0, k;
		cin >> n >> k;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		/*for (int i = 0; i < n; i++)
		{
			int sum = a[i];
			for (int j = i + 1; j < n; j++)
			{
				if (sum == k)
				{
					s = i;
					e = j;
					break;
				}
				if (sum > k || j == n)
					break;
				sum += a[j];
				//cout << a[j] << " ";
			}
			//cout << endl;
		}*/
		int i = 0, j = 0, sum = a[0], flag = 0;
		while (j != n - 1)
		{
			if (sum + a[j + 1] < k)
			{
				sum += a[++j];
			}
			else if (sum == k)
			{
				flag = 1;
				s = i + 1;
				e = j + 1;
				break;
			}
			else if (sum + a[j + 1] == k)
			{
				flag = 1;
				j++;
				s = i + 1;
				e = j + 1;
				break;
			}
			else
			{
				sum -= a[i++];
			}
		}
		if (flag)
			cout << s << " " << e << endl;
		else
			cout << -1 << endl;
	}


	return 0;
}