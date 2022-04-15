// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        // Your code here
        int answer = 0;
        for (int i = 0; i < n; i++) {
            int platform = 0;
            for (int j = i; j < n; j++) {
                if ((arr[j] >= arr[i] and arr[j] <= dep[i]) or (arr[i] >= arr[j] and arr[i] <= dep[j])) {
                    platform++;
                }
            }
            answer = max(answer, platform);
        }

        return answer;
    }
    int findPlatform(int arr[], int dep[], int n)
    {
        // Your code here
        vector<pair<int, int>> _time(n);
        for (int i = 0; i < n; i++) {
            _time[i].first = arr[i];
            _time[i].second = dep[i];
        }

        sort(_time.begin(), _time.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.second < b.second;
        });

        pair<int, int> curr_train = _time[0];

        int platform = 1, answer = 1;
        for (int i = 1; i < n; i++) {
            if (_time[i].first <= curr_train.second) {
                platform++;
            }
            else {
                curr_train = _time[i];
                answer = max(answer, platform);
                platform = 1;
            }
        }

        return answer;


    }

    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        // Your code here
        sort(arr, arr + n);
        sort(dep, dep + n);
        int i = 0, j = 0, answer = 0, platform = 0;
        while (i < n and j < n) {
            if (arr[i] <= dep[j]) {
                platform++;
                i++;
            }
            else {
                platform--;
                j++;
            }
            answer = max(answer, platform);
        }
        return answer;
    }

    int findPlatform(int arr[], int dep[], int n)
    {
        // Insert all the times (arr. and dep.)
        // in the multiset.
        multiset<pair<int, char> > order;
        for (int i = 0; i < n; i++) {

            // If its arrival then second value
            // of pair is 'a' else 'd'
            order.insert(make_pair(arr[i], 'a'));
            order.insert(make_pair(dep[i], 'd'));
        }

        int result = 0;
        int plat_needed = 0;

        // Start iterating the multiset.
        for (auto it : order) {

            // If its 'a' then add 1 to plat_needed
            // else minus 1 from plat_needed.
            if (it.second == 'a')
                plat_needed++;
            else
                plat_needed--;

            if (plat_needed > result)
                result = plat_needed;
        }
        return result;
    }
    int minPlatform(int arrival[], int departure[], int n)
    {

        // as time range from 0 to 2359 in 24 hour clock,
        // we declare an array for values from 0 to 2360
        int platform[2361] = {0};
        int requiredPlatform = 1;
        for (int i = 0; i < n; i++) {

            // increment the platforms for arrival
            ++platform[arrival[i]];

            // once train departs we decrease the platform count
            --platform[departure[i] + 1];
        }

        // We are running loop till 2361 because maximum time value
        // in a day can be 23:60
        for (int i = 1; i < 2361; i++) {

            // taking cumulative sum of platform give us required
            // number of platform fro every minute
            platform[i] = platform[i] + platform[i - 1];
            requiredPlatform = max(requiredPlatform, platform[i]);
        }
        return requiredPlatform;
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        int dep[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int j = 0; j < n; j++) {
            cin >> dep[j];
        }
        Solution ob;
        cout << ob.findPlatform(arr, dep, n) << endl;
    }
    return 0;
}  // } Driver Code Ends