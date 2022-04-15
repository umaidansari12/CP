

// } Driver Code Ends
class Solution
{
public:
    vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
    {
        //code here.
        unordered_map<int, int> m1, m2;
        vector<int> res;
        for (int i = 0; i < n1; i++)
        {
            m1[A[i]]++;
        }
        for (int i = 0; i < n2; i++)
        {
            m2[B[i]]++;
        }
        for (int i = 0; i < n3; i++)
        {
            if (C[i] != C[i + 1] && m1.find(C[i]) != m1.end() && m2.find(C[i]) != m2.end())
                res.push_back(C[i]);
        }
        return res;
    }

};

vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
{
    //code here.
    vector<int> r;
    for (int i = 0; i < n1; i++)
    {
        if (A[i] != A[i + 1])
            if ((binary_search(B, B + n2, A[i])) & (binary_search(C, C + n3, A[i])))
                r.push_back(A[i]);
    }
    return r;
}

// { Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];

        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];

        Solution ob;

        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0)
            cout << -1;
        for (int i = 0; i < res.size (); i++)
            cout << res[i] << " ";
        cout << endl;
    }
}  // } Driver Code Ends