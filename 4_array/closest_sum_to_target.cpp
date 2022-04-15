#include<bits/stdc++.h>
using namespace std;

pair<int, int> closestSum(vector<int> a, int x) {
    // your code goes here
    int n = a.size(), diff = INT_MAX, ans1 = -1, ans2 = -1, s = 0, e = n - 1;
    while (s <= e)
    {
        int sum = a[s] + a[e];
        if (abs(x - sum) < diff)
        {
            diff = abs(x - sum);
            ans1 = a[s];
            ans2 = a[e];
        }
        else if (sum < x)
            s++;
        else
            e--;
    }

    return {ans1, ans2};

}