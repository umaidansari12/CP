int lowerBound(vector<int> arr, int n, int x) {
    // Write your code here
    int start = 0, mid, end = arr.size() - 1, lower_bound = n;
    while (start <= end) {
        mid = (start + end) / 2;
        if (arr[mid] < x) {
            start = mid + 1;
        }
        else {
            lower_bound = mid;
            end = mid - 1;
        }
    }

    return lower_bound;
}
