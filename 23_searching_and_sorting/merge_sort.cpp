class Solution
{
public:
    void merge(int arr[], int l, int m, int r)
    {
        // Your code here
        int first_ptr = l, second_ptr = m + 1, temp[r - l + 1], idx = 0;
        while (first_ptr <= m and second_ptr <= r) {
            if (arr[first_ptr] < arr[second_ptr]) {
                temp[idx] = arr[first_ptr];
                first_ptr++;
            }
            else {
                temp[idx] = arr[second_ptr];
                second_ptr++;
            }
            idx++;
        }
        while (first_ptr <= m) {
            temp[idx] = arr[first_ptr];
            idx++;
            first_ptr++;
        }
        while (second_ptr <= r) {
            temp[idx] = arr[second_ptr];
            idx++;
            second_ptr++;
        }
        idx = 0;
        for (int i = l; i <= r; i++) {
            arr[i] = temp[idx];
            idx++;
        }
    }
public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if (l >= r)
            return;
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
};

void merge(vector<int> &arr, int low, int mid, int high) {
    int left = low;
    int right = mid + 1;
    vector<int> temp;
    while (left <= mid and right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left++]);
        }
        else {
            temp.push_back(arr[right++]);
        }
    }
    while (left <= mid)
        temp.push_back(arr[left++]);
    while (right <= high)
        temp.push_back(arr[right++]);
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}
void merge_sort(vector<int> &arr, int low, int high) {
    if (low >= high) {
        return;
    }
    int mid = (low + high) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

void mergeSort(vector < int > & arr, int n) {
    // Write your code here.
    int _size = arr.size() - 1;
    merge_sort(arr, 0, _size);
}