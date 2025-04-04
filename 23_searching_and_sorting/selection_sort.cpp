int select(int arr[], int i, int n)
{
    // code here such that selectionSort() sorts arr[]
    int min_index = i;
    for (int index = i; i < n; i++) {
        if (arr[index] < arr[min_index]) {
            min_index = index;
        }
    }
    return min_index;
}

void selectionSort(int arr[], int n)
{
    //code here
    for (int i = 0; i < n - 1; i++) {
        //   int select_index = select(arr,i,n);
        int mini = i;
        for (int j = i; j < n; j++) {
            if (arr[j] < arr[mini]) {
                mini = j;
            }
        }
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    }
}

/*

Selects minimum element from the range[0..n-1] and swap with 0th element
selects minimum element from the range[1..n-1] and swap with 1st element
.
.
.
selects minimum element from the range[n-2..n-1] and swap with n-1th element

TC -> O(N^2) -> avg, best and worst
*/