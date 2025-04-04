long long gcd(long long A, long long B) {
    if (B == 0)
        return A;
    return gcd(B, A % B);
}
vector<long long> lcmAndGcd(long long A , long long B) {
    // code here
    long long _gcd = gcd(A, B);
    return {(A * B) / (long long)_gcd, _gcd};
}