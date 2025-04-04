void bubbleSort(int arr[], int n)
{
    // Your code here
    // start from first and push max element to last by doing adjacent swaps
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 0; j <= i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// TC -> O(N^2) -> worst, average

// TC -> O(N) -> best case complexity -> when the array is already in order so no swaps are performed so at that very moment we can say that array is in order and we can stop now

void bubbleSort(int arr[], int n)
{
    // Your code here
    // start from first and push max element to last by doing adjacent swaps
    for (int i = n - 1; i >= 1; i--) {
        int didSwap = 0;
        for (int j = 0; j <= i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                didSwap = 1;
            }
        }
        if (didSwap == 0)
            break;
    }
}