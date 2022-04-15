/*
Approach: The approach is based on the concept of dynamic programming.

countWays(arr, m, N)
        Declare and initialize count[N + 1] = {0}
        count[0] = 1
        for i = 1 to N
            for j = 0 to m - 1
                if i >= arr[j]
                   count[i] += count[i - arr[j]]
        return count[N]

Given a set of m distinct positive integers and a value ‘N’. The problem is to count the total number of ways we can form ‘N’ by doing sum of the array elements. Repetitions and different arrangements are allowed.
*/
class Solution
{
public:
    // function to count the total
    // number of ways to sum up to 'N'
    void combinationSum1(int a[], int sum, int  &res, vector<int>&r, int m)
    {
        if (sum < 0)
            return;
        if (sum == 0)
        {
            //res.push_back(r);
            res++;
            return;
        }
        for (int i = 0; i < m; i++)
        {
            if (sum - a[i] >= 0)
            {
                r.push_back(a[i]);
                combinationSum1(a, sum - a[i], res, r, m);
                r.pop_back();
            }
        }
    }

    int countWays(int arr[], int m, int N)
    {
        //code here.
        int count[N + 1] = {0}, p = 1e9 + 7;
        count[0] = 1;

        // count ways for all values up
        // to 'N' and store the result
        for (int i = 1; i <= N; i++)
            for (int j = 0; j < m; j++)

                // if i >= arr[j] then
                // accumulate count for value 'i' as
                // ways to form value 'i-arr[j]'
                if (i >= arr[j])
                    count[i] = ((count[i] % p) + (count[i - arr[j]] % p) % p);

        // required number of ways
        return count[N];
    }

};