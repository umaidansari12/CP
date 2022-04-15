

vector<int> printClosest(int arr[], int brr[], int n, int m, int x);


int main()
{
    int t;
    cin >> t;
    int m, n, x;
    while (t--)
    {
        cin >> n >> m;
        int a[n], b[m];

        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < m; i++)
            cin >> b[i];

        sort(a, a + n);
        sort(b, b + m);
        cin >> x;

        vector<int> ans;
        ans = printClosest(a, b, n, m, x);
        cout << ans[0] << " " << ans[1] << endl;

    }
    return 0;
}
// } Driver Code Ends


vector<int> printClosest(int arr[], int brr[], int n, int m, int x)
{
    // Complete the function
    int answer1 = -1, answer2 = -1, diff = INT_MAX;
    // we are going to pick the elements one by one from the first array and then pair them
    // with elements of second array to make their sum closest to the required sum
    //time complexity - O(n^2)
    //space complexity - O(1)
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (diff > abs(x - (arr[i] + brr[j])))
            {
                diff = abs(x - (arr[i] + brr[j]));
                answer1 = arr[i];
                answer2 = brr[j];
            }
        }
    }
    int ans = INT_MAX, left = 0, right = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int sum = arr[i] + brr[j];
            if (abs(x - sum) < abs(x - ans))
            {
                left = arr[i];
                right = brr[j];
                ans = sum;
            }
            else if (abs(x - sum) == abs(x - ans))
            {
                left = min(arr[i], left);
                right = max(brr[j], right);
                ans = sum;
            }
        }
    }
    vector<int> res;
    res.push_back(left);
    res.push_back(right);
    return res;
    return {answer1, answer2};
}

vector<int> printClosestOptimal(int arr[], int brr[], int n, int m, int x)
{
    // Complete the function
    int answer1 = -1, answer2 = -1, diff = INT_MAX;
    //firstly we are going to use the approach of 2 sum if the sum is less we increase the sum otherwise decrease the sum
    int i = 0, j = m - 1;
    while (i<n and j >= 0)
    {
        int sum = arr[i] + brr[j];
        if (sum == x)
        {
            return {arr[i], brr[j]};
        }
        if (sum < x)
        {
            if (diff > abs(x - sum))
            {
                diff = abs(x - sum);
                answer1 = arr[i];
                answer2 = brr[j];
            }
            i++;

        }
        else
        {
            if (diff > abs(x - sum))
            {
                diff = abs(x - sum);
                answer1 = arr[i];
                answer2 = brr[j];
            }
            j--;
        }
    }
    return {answer1, answer2};
}