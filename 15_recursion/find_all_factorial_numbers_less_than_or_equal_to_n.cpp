void solve(long long fact, long long index, long long N, vector<long long> &factorial) {
    if (fact > N) {
        return;
    }
    factorial.push_back(fact);
    solve(fact * (index + 1), index + 1, N, factorial);
}
vector<long long> factorialNumbers(long long N)
{
    // Write Your Code here
    vector<long long> factorial;
    long long fact = 1, index = 1;
    solve(fact, index, N, factorial);
    return factorial;
}