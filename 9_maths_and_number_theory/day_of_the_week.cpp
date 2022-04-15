#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    string getDayOfWeek(int d, int m, int y) {
        // code here
        static int t[] = { 0, 3, 2, 5, 0, 3,
                           5, 1, 4, 6, 2, 4
                         };
        y -= m < 3;
        int ans = ( y + y / 4 - y / 100 +
                    y / 400 + t[m - 1] + d) % 7;
        if (ans == 0)
            return "Sunday";
        else if (ans == 1)
            return "Monday";
        else if (ans == 2)
            return "Tuesday";
        else if (ans == 3)
            return "Wednesday";
        else if (ans == 4)
            return "Thursday";
        else if (ans == 5)
            return "Friday";
        else if (ans == 6)
            return "Saturday";
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int d, m, y;

        cin >> d >> m >> y;

        Solution ob;
        cout << ob.getDayOfWeek(d, m, y) << endl;
    }
    return 0;
}  // } Driver Code Ends