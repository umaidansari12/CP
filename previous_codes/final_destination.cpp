#include <bits/stdc++.h>
using namespace std;


/*If robot chooses the shortest path from (0,0) to (a,b), it takes |a| + |b| steps.
So we know that all numbers less than |a| + |b| are impossible to be the number of steps that robot take.
Now consider when the number of steps is not less than |a| + |b|.
When Robot arrives at (a, b), he can take two more steps such as (a, b) -> (a, b + 1) -> (a, b) to remain at the same position.
So we know that for all x such that x ≥ |a| + |b| and (x - (|a| + |b|))%2 = 0, there exists a way for robot to get to (a, b) in exactly x steps.
The last part we should prove is that it's impossible for Robot to arrive at (a,b) in exactly x steps when (x - (|a| + |b|))%2 = 1.
We can color all positions (x, y) where (x + y)%2 = 0 as white and color other points as black.
After each step, the color of the position you're at always changes.
So we know that it's impossible for robot to get to (a, b) in odd/even steps if the color of (a, b) is white/black.
Conclusion: If x ≥ |a| + |b| and (x - (|a| + |b|))%2 = 0 print 1, Otherwise print 0.*/
// } Driver Code Ends
class Solution {
public:
    int canReach(long long a, long long b, long long x) {
        long steps = x - abs(a) - abs(b);
        if (steps < 0)
            return 0;
        return (steps % 2) ? 0 : 1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long a, b, x;

        cin >> a >> b >> x;

        Solution ob;
        cout << ob.canReach(a, b, x) << endl;
    }
    return 0;
}  // } Driver Code Ends