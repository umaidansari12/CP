
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    bool isSteppingNumber(int n) {
        int prev = -1;
        while (n) {
            int rem = n % 10;
            if (prev != -1) {
                if (abs(rem - prev) != 1)
                    return false;
            }
            prev = rem;
            n /= 10;
        }
        return true;

    }

    int steppingNumbersBrute(int n, int m)
    {
        // Code Here
        int count = 0;
        for (int i = n; i <= m; i++) {
            if (isSteppingNumber(i))
                count++;
        }
        return count;
    }
    int bfs(int n, int m, int num) {
        int cnt = 0;
        queue<int> q;
        q.push(num);
        while (!q.empty()) {
            int stepNum = q.front();
            q.pop();
            if (stepNum >= n and stepNum <= m)
                cnt++;
            if (num == 0 or stepNum > m)
                continue;
            int lastDigit = stepNum % 10;
            int stepNumA = stepNum * 10 + (lastDigit - 1);
            int stepNumB = stepNum * 10 + (lastDigit + 1);
            if (lastDigit == 0)
                q.push(stepNumB);
            else if (lastDigit == 9)
                q.push(stepNumA);
            else {
                q.push(stepNumA);
                q.push(stepNumB);
            }
        }
        return cnt;
    }
    int dfs(int n, int m, int stepNum) {
        int cnt = 0;
        if (stepNum >= n and stepNum <= m)
            cnt++;
        if (stepNum == 0 or stepNum > m)
            return 0;
        int lastDigit = stepNum % 10;
        int stepNumA = stepNum * 10 + (lastDigit - 1);
        int stepNumB = stepNum * 10 + (lastDigit + 1);
        if (lastDigit == 0)
            cnt += dfs(n, m, stepNumB);
        else if (lastDigit == 9)
            cnt += dfs(n, m, stepNumA);
        else {
            cnt += dfs(n, m, stepNumA);
            cnt += dfs(n, m, stepNumB);
        }
        return cnt;
    }

    int steppingNumbers(int n, int m)
    {
        // Code Here
        int cnt = 0;
        for (int i = 0; i <= 9; i++)
            //cnt += bfs(n, m, i);
            cnt += dfs(n, m, i);
        return cnt;
    }
};

void dfs(int n, int m, int stepNum, vector<int> &res) {
    if (stepNum == 0 or stepNum > m) {
        if (stepNum == n)
            res.push_back(stepNum);
        return;
    }

    if (stepNum >= n and stepNum <= m)
        res.push_back(stepNum);
    int lastDigit = stepNum % 10;
    int stepNumA = stepNum * 10 + (lastDigit - 1);
    int stepNumB = stepNum * 10 + (lastDigit + 1);
    if (lastDigit == 0)
        dfs(n, m, stepNumB, res);
    else if (lastDigit == 9)
        dfs(n, m, stepNumA, res);
    else {
        dfs(n, m, stepNumA, res);
        dfs(n, m, stepNumB, res);
    }
}

vector<int> Solution::stepnum(int A, int B) {

    vector<int> res;
    for (int i = 0; i <= 9; i++)
        dfs(A, B, i, res);
    sort(res.begin(), res.end());
    return res;
}



// { Driver Code Starts.

int main()
{
    Solution obj;
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        cout << obj.steppingNumbers(n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends