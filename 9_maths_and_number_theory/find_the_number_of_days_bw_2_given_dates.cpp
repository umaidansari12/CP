
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    int countLeapYears(int d1, int m1, int y1)
    {
        int years = y1;

        // Check if the current year needs to be
        //  considered for the count of leap years
        // or not
        if (m1 <= 2)
            years--;

        // An year is a leap year if it
        // is a multiple of 4,
        // multiple of 400 and not a
        // multiple of 100.
        return years / 4
               - years / 100
               + years / 400;
    }
    int noOfDays(int d1, int m1, int y1, int d2, int m2, int y2) {
        // code here
        int n1 = 0, n2 = 0;
        int daysinMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        n1 = y1 * 365 + d1;
        for (int i = 0; i < m1 - 1; i++)
            n1 += daysinMonth[i];
        n1 += countLeapYears(d1, m1, y1);
        n2 = y2 * 365 + d2;
        for (int i = 0; i < m2 - 1; i++)
            n2 += daysinMonth[i];
        n2 += countLeapYears(d2, m2, y2);
        return abs(n2 - n1);



    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int d1, d2, m1, m2, y1, y2;

        cin >> d1 >> m1 >> y1;
        cin >> d2 >> m2 >> y2;

        Solution ob;
        cout << ob.noOfDays(d1, m1, y1, d2, m2, y2) << endl;
    }
    return 0;
}  // } Driver Code Ends