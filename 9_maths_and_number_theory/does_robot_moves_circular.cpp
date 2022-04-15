#include <bits/stdc++.h>
using namespace std;
string isCircular(string path);

int main() {
    int t;
    cin >> t;
    while (t--) {
        string path;
        cin >> path;
        cout << isCircular(path) << endl;
    }
    return 0;
}// } Driver Code Ends


string isCircular(string path) {
    //complete the function here
    int x = 0, y = 0, i = 0;
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    for (auto ins : path) {
        if (ins == 'R') {
            i = (i + 1) % 4;
        }
        else if (ins == 'L') {
            i = (i + 3) % 4;
        }
        else {
            x += dx[i];
            y += dy[i];
        }
    }
    return (x == 0 and y == 0) ? "Circular" : "Not Circular";
}