#include <bits/stdc++.h>
using namespace std;

int convertFive(int n);

// Driver program to test above function
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << convertFive(n) << endl;
    }
}// } Driver Code Ends


/*you are required to complete this method*/
int convertFive(int n) {
    // Your code here
    int temp = 0;
    while (n)
    {
        temp = (temp * 10) + (((n % 10) == 0) ? 5 : n % 10);
        n /= 10;
    }
    n = 0;
    while (temp)
    {
        n = (n * 10) + (temp % 10);
        temp /= 10;
    }
    return n;
}