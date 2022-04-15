#include <bits/stdc++.h>

using namespace std;
using ll = long long;


class Solution
{
public:
	static bool comp(Item a, Item b)
	{
		double r1 = (double)a.value / a.weight;
		double r2 = (double)b.value / b.weight;
		return r1 > r2;
	}
	double fractionalKnapsack(int W, Item arr[], int n)
	{
		// Your code here
		sort(arr, arr + n, comp);
		int curWeight = 0;
		double finalValue = 0.0;
		for (int i = 0; i < n; i++)
		{
			if (curWeight + arr[i].weight <= W)
			{
				finalValue += arr[i].value;
				curWeight += arr[i].weight;
			}
			else
			{
				int remain = W - curWeight;
				finalValue += ((double)arr[i].value / arr[i].weight) * remain;
				break;

			}
		}
		return finalValue;
	}

};


bool cmp(vector<vector<int>> a, vector<vector<int>> b)
{
	double r1 = a[]
}
double fractional_Knapsack(vector<vector<int>> vw, int n, int w)
{
	sort(vw.begin(), vw.end(), cmp);
	return 0.0;
}
double fractionalKnapsack(vector<vector<int>> vw, vector<double> v_w, int n, int w)
{
	double res = 0.0;
	int i = 0;
	unordered_map<int, int> idx;
	for (int i = 0; i < n; i++)
		idx[v_w[i]] = i;
	sort(v_w.begin(), v_w.end(), cmp);
	while (w > 0 && vw[n - 1][1] > 0)
	{
		if (w >= vw[idx[v_w[i]]][1])
		{
			w -= vw[idx[v_w[i]]][1];
			res += (vw[idx[v_w[i]]][0]);
			vw[idx[v_w[i]]][1] = 0;
		}
		else
		{
			vw[idx[v_w[i]]][1] -= w;
			res += (v_w[i] * w);
			w = 0;
		}
		i++;
	}
	return res;
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
		int n, w;
		cin >> n >> w;
		vector<vector<int>> vw(n, vector<int> (2, 0));
		vector<double> v_w;
		for (int i = 0; i < n; i++)
		{
			cin >> vw[i][0] >> vw[i][1];
			double r = double(vw[i][0]) / double(vw[i][1]);
			v_w.push_back(r);
		}
		/*for (int i = 0; i < n; i++)
		{
			cout << vw[i][0] << " " << vw[i][1] << " | " << v_w[i] << endl;
			cout << "Done\n";
		}*/
		double res = fractionalKnapsack(vw, v_w, n, w);
		double res1 = fractional_Knapsack(vw, n, w);
		printf("%.2f\n", res);
		printf("%.2f\n", res1);



	}



	return 0;
}