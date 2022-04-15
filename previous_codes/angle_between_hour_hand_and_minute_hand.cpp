#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int getAngle(int H , int M) {
        // code here

        /* if(H==12) H=0;
         if(M==60)
         {
             M=0;
             H+=1;
             if(H>12)
             H=H-12;
         }*/
        if (M == 0 || M == 60) M = 0;
        float h = (30 * H) + (0.5 * M);
        float m = M * 6;
        float angle = abs(h - m);
        int ans = min(360 - angle, angle);
        return ans;
    }
    double angleClock(int hour, int minutes) {
        if (minutes == 60) minutes = 0;
        double h = (30 * hour) + (0.5 * minutes);
        double m = (6 * minutes);
        double angle = abs(h - m);
        return min(360 - angle, angle);

    }
};


// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int H, M;

        cin >> H >> M;

        Solution ob;
        cout << ob.getAngle(H, M) << endl;
    }
    return 0;
}  // } Driver Code Ends