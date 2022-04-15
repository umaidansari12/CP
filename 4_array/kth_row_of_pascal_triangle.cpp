vector<int> Solution::getRow(int A) {
    vector<int> pascal(A + 1, 1);
    int res = 1;
    for (int i = 1; i < A; i++)
    {
        res *= (A - i + 1);
        res /= i;
        pascal[i] = res;
    }
    return pascal;
}
