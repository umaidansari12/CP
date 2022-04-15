int Solution::isPalindrome(string A) {
    transform(A.begin(), A.end(), A.begin(), ::tolower);
    string res;
    for (int i = 0; i < A.size(); i++)
        if (isalpha(A[i]) or isdigit(A[i]))
            res += A[i];
    int n = res.size();
    for (int i = 0; i < (n / 2); i++)
    {
        if (res[i] != res[n - i - 1])
            return 0;
    }
    return 1;
}

int Solution::isPalindrome(string A) {
    int i = 0, j = A.size() - 1;
    while (i < j)
    {
        while (i < j and !isalnum(A[i]))
            i++;
        while (i < j and !isalnum(A[j]))
            j--;
        if (tolower(A[i]) != tolower(A[j]))
            return 0;
        i++;
        j--;
    }
    return 1;
}
