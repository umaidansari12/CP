int count_students_with_pages(vector<int> &arr, int n, int pages) {
    int students = 1;
    long long max_pages = 0;
    for (int i = 0; i < n; i++) {
        if (max_pages + arr[i] <= pages) {
            max_pages += arr[i];
        }
        else {
            max_pages = arr[i];
            students++;
        }
    }
    return students;
}


int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    if (m > n) {
        return -1;
    }
    long long low = *max_element(arr.begin(), arr.end());
    long long high = accumulate(arr.begin(), arr.end(), 0);

    // pages is maximum pages in a book a student can hold, and we need to accomodate m students following maximum no of pages to be pages
    for (long long pages = low; pages <= high; pages++) {
        int students = count_students_with_pages(arr, n, pages);
        if (students == m)
            return pages;
    }
    return low;
}

// TC - O(sum-max+1)*n
// SC - O(1)

int count_students_with_pages(vector<int> &arr, int n, int pages) {
    int students = 1;
    long long max_pages = 0;
    for (int i = 0; i < n; i++) {
        if (max_pages + arr[i] <= pages) {
            max_pages += arr[i];
        }
        else {
            max_pages = arr[i];
            students++;
        }
    }
    return students;
}


int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    if (m > n) {
        return -1;
    }
    long long low = *max_element(arr.begin(), arr.end());
    long long high = accumulate(arr.begin(), arr.end(), 0);

    // pages is maximum pages in a book a student can hold, and we need to accomodate m students following maximum no of pages to be pages
    while (low <= high) {
        int mid = (low + high) / 2;
        int students = count_students_with_pages(arr, n, mid);
        if (students > m)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

// TC - O(log2(sum-max+1))*n
// SC - O(1)
