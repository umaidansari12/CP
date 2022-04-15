#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends


class Solution {
public:
    void RepeatedMissing(vector<int> &a, int n)
    {
        ll s_n = (ll)n * (ll)(n + 1) / 2, s_sqn = ((ll)n * (ll)(n + 1) * ((ll)(2 * n) + 1)) / 6;
        for (int i = 0; i < n; i++)
        {
            s_n -= (ll)a[i];
            s_sqn -= ((ll)a[i] * (ll)a[i]);
        }
        ll missing_number = (s_n + s_sqn / s_n) / 2;
        ll repeating = missing_number - s_n;
        cout << repeating << " " << missing_number << endl;
    }
    void repeatingMissing(vector <int> &a, int n)
    {
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++)
        {
            if (a[i] == a[i + 1])
            {
                cout << a[i] << " ";
                break;
            }

        }
        for (int i = 0; i < n; i++)
        {
            if (a[i + 1] == a[i])
            {
                cout << a[i] - 1 << endl;
                break;
            }
            if (a[i + 1] - a[i] > 1)
            {
                cout << a[i] + 1 << endl;
                break;
            }
        }
    }

    void repeating_missing(vector <int> &a, int n)
    {
        for (int i = 0; i < n; i++)
        {
            a[a[i] % n] += n;
        }
        for (int i = 0; i < n; i++)
        {
            if (a[i] >= 2 * n)
            {
                cout << (i) << " ";
                break;
            }

        }
        for (int i = 0; i < n; i++)
        {
            if (a[i] / n == 0)
            {
                cout << (i) << endl;
                break;
            }

        }
    }
    void repeatingmissing(vector<int> &a, int n)
    {
        bool present[n + 1] = {false};
        ll repeating = 0, missing = 0;
        for (int i = 0; i < n; i++)
        {
            if (present[a[i]] == true)
                repeating = a[i];
            present[a[i]] = true;
        }
        for (int i = 1; i < n + 1; i++)
        {
            if (present[i] == false)
                missing = i;
        }
        cout << repeating << " " << missing << endl;
    }
    int *findTwoElement(int *arr, int n) {
        // code here
        int a[n + 1];
        for (int i = 1; i <= n; i++)
            a[i] = 0;
        for (int i = 0; i < n; i++)
            a[arr[i]]++;
        int *res;
        res = (int*)malloc(2 * sizeof(int));
        for (int i = 0; i <= n; i++)
        {
            if (a[i] >= 2)
                res[0] = i;
            if (a[i] == 0)
                res[1] = i;
        }
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends