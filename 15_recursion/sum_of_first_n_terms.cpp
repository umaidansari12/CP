long long sumOfSeries(long long N) {
    // code here
    if (N == 1)
        return 1;
    return (N * N * N) + sumOfSeries(N - 1);

}