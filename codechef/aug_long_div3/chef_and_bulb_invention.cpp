#include <bits/stdc++.h>

using namespace std;
using ll = long long;


/*

DIFFICULTY
Simple

PREREQUISITES
Basic Math

PROBLEM
Given NN, KK and pp, there are NN gases numbered from 00 to N-1N−1. Chef tries all gases one by one, first trying all gases xx with x \bmod K = 0xmodK=0 in increasing order, then all gases with x \bmod K = 1xmodK=1 and so on, trying one gas on each day.

Given an integer pp, determine the day on with gas numbered pp shall be tried.

QUICK EXPLANATION
Grouping gases xx having the same value of x \bmod KxmodK, we get KK groups, where groups are processed one by one.
We can find the group in which pp is present simply by computing p \bmod KpmodK.
First N \bmod KNmodK groups shall have \frac{N}{K}+1
K
N
​
 +1 elements, and rest K - N \bmod KK−NmodK groups shall have \frac{N}{K}
K
N
​
  elements
We need to count all elements in the first p \bmod KpmodK groups and then count the number of gases in the group same as pp which are tried before pp.
EXPLANATION
Let’s consider an example first. Say we have N = 27, K = 5N=27,K=5. The gases would be processed in following order
0 5 10 15 20 25 1 6 11 16 21 26 2 7 12 17 22 3 8 13 18 23 4 9 14 19 24
We can divide above into groups bases on x \bmod KxmodK. We have

0: 0 5 10 15 20 25
1: 1 6 11 16 21 26
2: 2 7 12 17 22
3: 3 8 13 18 23
4: 4 9 14 19 24
We can see that before processing any element in row rr, all elements in rows before rr are processed.

Let’s assume given pp is in row rr. So we need to find the number of elements in rows before row indexed rr.

Observation: First N \bmod KNmodK rows contain \frac{N}{K}+1
K
N
​
 +1 elements, and rest K - N \bmod KK−NmodK rows contain \frac{N}{K}
K
N
​
  elements.

It is intuitive to see it this way. Let’s find CC as the largest multiple of KK such that C \leq NC≤N. In above example, C = 25 = K *\lfloor \frac{N}{K}\rfloorC=25=K∗⌊
K
N
​
 ⌋. We can see that dividing the first CC gases into KK groups contribute \lfloor \frac{N}{K}\rfloor⌊
K
N
​
 ⌋ gases in each group evenly. Now, only N \bmod KNmodK gases are left, each of which is divided into the first N \bmod KNmodK groups.

Hence, first N \bmod KNmodK groups have \lfloor \frac{N}{K}\rfloor +1⌊
K
N
​
 ⌋+1 elements, and rest K - N \bmod KK−NmodK rows have \lfloor \frac{N}{K}\rfloor⌊
K
N
​
 ⌋ elements.

For computing the number of elements in the first rr rows, we can see that

if r \leq N \bmod Kr≤NmodK, then all rows have \lfloor \frac{N}{K}\rfloor+1⌊
K
N
​
 ⌋+1 elements, leading to \displaystyle r * \left(\left\lfloor \frac{N}{K}\right\rfloor+1\right)r∗(⌊
K
N
​
 ⌋+1) elements.
Otherwise first N \bmod KNmodK rows have \lfloor \frac{N}{K}\rfloor+1⌊
K
N
​
 ⌋+1 elements, and r - N \bmod Kr−NmodK rows have \lfloor \frac{N}{K}\rfloor⌊
K
N
​
 ⌋ elements, leading to \displaystyle (N \bmod K)* \left (\left \lfloor \frac{N}{K} \right\rfloor+1 \right) + (r - N \bmod K) * \frac{N}{K}(NmodK)∗(⌊
K
N
​
 ⌋+1)+(r−NmodK)∗
K
N
​

 Simplicifation
Hence, if we know row containing pp, we can count the number of elements in rows before that row. Also, based on our grouping, we have pp appearing in row indexed p \bmod KpmodK.

Now, within the current group rr, First, rr is processed, then K + rK+r is processed, and so on. We want to find the index of pp in the current row, which can be computed in the same way as computing the index of a term in AP. Specifically, pp is processed at index nn, such that n = (p-r)/K+1n=(p−r)/K+1.

Summarizing, the day on which gas pp is processed can be written as \displaystyle (p \bmod K) * \frac{N}{K} + min(p \bmod K, N \bmod K) + \frac{p-p \bmod K}{K} + 1(pmodK)∗
K
N
​
 +min(pmodK,NmodK)+
K
p−pmodK
​
 +1 which can be computed in O(1)O(1) time.

TIME COMPLEXITY
The time complexity is O(1)O(1) per test case.
*/
long long int solve2() {
	long long int n, p, k, cnt = 1;
	cin >> n >> p >> k;
	//ll a[n];
	map<ll, ll> m;
	for (long long int i = 0; i < n; i++)
		m[i] = i;
	bool flag = false;
	for (long long int i = 0; i < k; i++)
	{
		//for (long long int j = 0; j < n; j++)
		for (auto j : m)
		{
			//if ((a[j] % k) == i and a[j] == p)
			if ((j.second % k) == i and j.second == p)
			{
				//return cnt;
				flag = true;
				break;
			}
			//else if ((a[j] % k) == i)
			else if ((j.second % k) == i)
				cnt++;
		}
		if (flag)
			break;
	}
	return cnt;
}

long long int solve3() {
	long long int n, p, k, cnt = 0, key = -1;
	cin >> n >> p >> k;
	map<ll, vector<ll>> m;
	for (long long int i = 0; i < n; i++)
	{
		m[i % k].push_back(i);
		if (i == p)
		{
			key = i % k;
		}
	}

	for (auto i : m)
	{
		if (i.first == key)
		{
			for (auto j : i.second)
			{
				if (j == p)
				{
					return cnt + 1;
				}
				cnt++;
			}
		}
		cnt += i.second.size();
	}


	// bool flag = false;
	// for (long long int i = 0; i < k; i++)
	// {
	// 	//for (long long int j = 0; j < n; j++)
	// 	for (auto j : m)
	// 	{
	// 		//if ((a[j] % k) == i and a[j] == p)
	// 		if ((j.second % k) == i and j.second == p)
	// 		{
	// 			//return cnt;
	// 			flag = true;
	// 			break;
	// 		}
	// 		//else if ((a[j] % k) == i)
	// 		else if ((j.second % k) == i)
	// 			cnt++;
	// 	}
	// 	if (flag)
	// 		break;
	// }
	return cnt;
}

long long int solve1() {
	long long int n, p, k, cnt = 0, key = -1;
	cin >> n >> p >> k;
	//map<ll, vector<ll>> m;
	key = p % k;
	for (long long int i = 0; i < n; i++)
	{
		if ((i % k) < key)
			cnt++;
		if ((i % k) == key and i <= p)
		{
			cnt++;
		}
	}

	return cnt;

}



ll solve5() {
	ll n, p, k, cnt = 1;
	cin >> n >> p >> k;

	ll a[n];
	for (ll i = 0; i < n; i++)
		a[i] = i;
	for (ll i = 0; i < k; i++)
	{
		for (ll j = 0; j < n; j++)
		{
			if ((a[j] % k) == i and a[j] == p)
			{
				return cnt;
			}
			else if ((a[j] % k) == i)
				cnt++;
		}
	}
	return cnt;
}

ll solve()
{
	ll n, p, k, cnt = 0;
	cin >> n >> p >> k;
	ll rem = p % k; // finding row in which p belongs
	ll last = (n / k) * k;//finding the last multiple of k i.e less than or equal to n
	ll times = (last / k);//same number of elements that will be present in every group if the group is complete i.e n%k==0

	cnt = times * rem;//counting the number of elements which are present in rows that are before p
	cnt += (p / k);//including the number which are present in same row as p but before p

	cnt += (min(rem, n % k)); //including those numbers which are  greater than p but have modulo less than the p

	return cnt + 1;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		cout << solve3() << '\n';
	}

	return 0;
}