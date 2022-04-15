class Solution {
public:
    int mod = 100000007;
    int solve(int n, string r)
    {
        if (r.size() == n)
        {
            return 1;
        }
        char ch = r[r.size() - 1];
        if (ch == 'a')
            return (solve(n, r + "e") % mod);
        else if (ch == 'e')
            return ((solve(n, r + "a") % mod) + (solve(n, r + "i") % mod)) % mod;
        else if (ch == 'i')
            return ((solve(n, r + "a") % mod) + (solve(n, r + "e") % mod) + (solve(n, r + "o") % mod) + (solve(n, r + "u") % mod)) % mod;
        else if (ch == 'o')
            return ((solve(n, r + "i") % mod) + (solve(n, r + "u") % mod)) % mod;
        else if (ch == 'u')
            return (solve(n, r + "a") % mod);
        return 0;
    }
    int countVowelPermutation(int n) {
        return ((solve(n, "a") % mod) + (solve(n, "e") % mod) + (solve(n, "i") % mod) + (solve(n, "o") % mod) + (solve(n, "u") % mod)) % mod;
    }
};

//Intuition
//Let us visualize this as a graph problem. From the above rules, we can create a directed graph
//where an edge between characters first and second imply that it is permissible to write
//second immediately after first. Hence, the question converts to, Given a directed graph,
//how many paths of length n are there?

/*
Now, Let us say that dp[n][char] denotes the number of directed paths of length n
which end at a particular vertex char. Then, we know that the last vertex in our path
was char. However, let's focus on the last second vertex. It could have been any of the
vertex which has a direct edge to char. Hence, if we can find the number of paths of length
n-1 ending at these vertices, then we can append char at the end of every path and we would
have exhausted all possibilites.

Hence, dp[n+1][x] = sum of all dp[n][y] such that there is a directed edge from y to x.

*/

class Solution {
public:
    int mod = 1e9 + 7;
    int countVowelPermutation(int n) {
        vector<vector<long long>> dp(n + 1, vector<long long>(5, 0));
        for (int i = 0; i < 5; i++)
        {
            dp[1][i] = 1;
        }
        /* dp[i][j] denotes the number of valid strings of length i */
        for (int i = 1; i < n; i++)
        {
            dp[i + 1][0] = (dp[i][1] + dp[i][2] + dp[i][4]) % mod;
            dp[i + 1][1] = (dp[i][0] + dp[i][2]) % mod;
            dp[i + 1][2] = (dp[i][1] + dp[i][3]) % mod;
            dp[i + 1][3] = (dp[i][2]) % mod;
            dp[i + 1][4] = (dp[i][2] + dp[i][3]) % mod;
        }
        int res = 0;
        for (int i = 0; i < 5; i++)
            res = (res + dp[n][i]) % mod;

        return res;


    }
};

/*
It also works if we consider from the start to the end, e.g. dp[n][char] denotes the
number of strings of length n which start (not end) with a char.
The only difference is in the second for loop:*/

class Solution {
public:
    int mod = 1e9 + 7;
    int countVowelPermutation(int n) {
        vector<vector<long long>> dp(n + 1, vector<long long>(5, 0));
        for (int i = 0; i < 5; i++)
        {
            dp[1][i] = 1;
        }
        for (int i = 1; i < n; i++)
        {
            dp[i + 1][0] = (dp[i][1]) % mod;
            dp[i + 1][1] = (dp[i][0] + dp[i][2]) % mod;
            dp[i + 1][2] = (dp[i][0] + dp[i][1] + dp[i][3] + dp[i][4]) % mod;
            dp[i + 1][3] = (dp[i][2] + dp[i][4]) % mod;
            dp[i + 1][4] = (dp[i][0]) % mod;
        }
        int res = 0;
        for (int i = 0; i < 5; i++)
            res = (res + dp[n][i]) % mod;

        return res;


    }
};

//I used the similar approach but instead of dp I use variables to store values;

class Solution {
    private static final int MOD = 1_000_000_007;
    public int countVowelPermutation(int n) {

        int a = 1;
        int e = 1;
        int i = 1;
        int o = 1;
        int u = 1;

        for (int j = 2; j <= n; j++) {
            int newA = ((e + i) % MOD + u) % MOD;
            int newE = (a + i) % MOD;
            int newI = (e + o) % MOD;
            int newO = (i) % MOD;
            int newU = (i + o) % MOD;

            a = newA;
            e = newE;
            i = newI;
            o = newO;
            u = newU;
        }

        int ans = 0;
        ans = ((((a + e) % MOD + i) % MOD + o) % MOD + u) % MOD;

        return ans;
    }
}