
void insert(int arr[], int i)
{
    //code here
}
public:
//Function to sort the array using insertion sort algorithm.
void insertionSort(int arr[], int n)
{
    //code here
    // takes an element and put it to its correct position
    for (int i = 0; i <= n - 1; i++) {
        // int element = arr[i];
        // for (int j = i; j > 0; j--) {
        //     if (arr[j - 1] > arr[j]) {
        //         int temp = arr[j];
        //         arr[j] = arr[j - 1];
        //         arr[j - 1] = temp;
        //     }
        // }
        int j = i;
        while (j > 0 and arr[j - 1] > arr[j]) {
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--;
        }
    }
}

/*
TC -> O(N^2) worst and avg case
      O(N) -> best , when array is sorted and no swaps are performed and all the elements are in its correct position
*/