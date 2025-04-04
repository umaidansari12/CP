void reverse(int index, int n, string &str) {
    if (index >= (n / 2))
        return;
    swap(str[index], str[n - index - 1]);
    reverse(index + 1, n, str);
}

string reverseWord(string str) {

    //Your code here
    int n = str.size();

    reverse(0, n, str);
    return str;
}