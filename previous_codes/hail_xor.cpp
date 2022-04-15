/*#include <iostream>
#include<vector>
#include<math.h>
using namespace std;
/*You are given a sequence A1,A2,…,AN and you have to perform the following operation exactly X times:

Choose two integers i and j such that 1≤i<j≤N.
Choose a non-negative integer p.
Change Ai to Ai⊕2p, and change Aj to Aj⊕2p, where ⊕ denotes bitwise XOR.
Find the lexicographically smallest sequence which can be obtained by performing this operation exactly X times.

A sequence B1,B2,…,BN is said to be lexicographically smaller than a sequence C1,C2,…,CN if there is an index i such that Bi<Ci and for each valid j<i, Bj=Cj.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers N and X.
The second line contains N space-separated integers A1,A2,…,AN.
Output
For each test case, print a single line containing N space-separated integers ― the lexicographically smallest obtainable sequence.

Constraints
1≤T≤10
2≤N≤105
1≤X≤109
1≤Ai≤109 for each valid i
Subtasks
Subtask #1 (30 points): N≤100
Subtask #2 (70 points): original constraints

Example Input
1
3 3
2 2 3
Example Output
0 0 3
Explanation
Example case 1: The original sequence is (2,2,3). Consider the following three operations:

Choose i=1, j=2 and p=1. Then, A1 changes from 2 to 2⊕21=0 and similarly, A2 changes from 2 to 2⊕21=0. Now the sequence is (0,0,3).
Next, choose i=1, j=2 and p=1. Then, A1 changes to 0⊕21=2 and A2 changes to 0⊕21=2. The sequence is (2,2,3).
Next, again choose i=1, j=2 and p=1. Then, A1 changes to 2⊕21=0 and A2 changes to 2⊕21=0. The sequence is (0,0,3) again.
We can check that after exactly 3 operations, this is the lexicographically smallest sequence we can obtain.
int main() {
    long long t, n, x, a[100001], k = 30;
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld %lld", &n, &x);
        if (n == 2)
        {
            scanf("%lld %lld", &a[0], &a[1] );
            if (a[0] == 0)
            {
                if (x % 2 != 0)
                {
                    a[0] = 1;
                    a[1] = a[1] ^ 1;
                }
            }
            else
            {
                while (x-- > 0)
                {
                    int p = int(log(a[0]) / log(2));
                    a[0] = a[0] ^ (int) pow(2, p);
                    a[1] = a[1] ^ (int) pow(2, p);
                    if (a[0] == 0) break;
                }
                if (x > 0 && x % 2 != 0)
                {
                    a[0] = 1;
                    a[1] = a[1] ^ 1;
                }
            }
        }



        else
        {
            vector<vector<long long>>idx(k + 1);
            for (long long i = 0; i < n; i++) {
                scanf("%lld", &(a[i]));
                if (i == n - 1)continue;
                for (long long j = k; j >= 0; j--)if (a[i] & (1LL << j)) {
                        idx[j].push_back(i);
                    }
            }
            vector<long long> cnt(k + 1, 0);
            for (long long i = 0; i < n - 1; i++) {
                for (long long j = k; j >= 0; j--) {
                    long long mask = 1LL << j;
                    if ((a[i]&mask) == 0)continue;
                    a[i] ^= mask;
                    long long d;
                    if (++cnt[j] < idx[j].size()) {
                        d = idx[j][cnt[j]++];
                    } else d = n - 1;
                    a[d] ^= mask;
                    if (--x == 0)break;
                }
                if (x == 0)break;
            }
        }
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";

    }

}*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int greatesPowerOf2(int n)
{
    return pow(2, log2(n));
}

int main()
{
    ios_base :: sync_with_stdio(false);
    //cin.tie(NULL);
    // cout.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int i = 0;
        while (1)
        {
            if (x == 0)
                break;
            if (i < n - 1 && arr[i] == 0)
                i++;
            if (i == n - 1)
                break;
            int gpo2 = greatesPowerOf2(arr[i]);
            arr[i] ^= gpo2;
            int j = i + 1;
            while (1)
            {
                if (j == n - 1)
                    break;
                if (arr[j]^gpo2 < arr[j])
                {
                    arr[j] ^= gpo2;
                    break;
                }
            }
            x--;
            if (x == 1 || (x % 2 != 0 && n == 2))
            {
                arr[n - 1] ^= 1;
                arr[n - 2] ^= 1;

            }

        }
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }


    return 0;
}