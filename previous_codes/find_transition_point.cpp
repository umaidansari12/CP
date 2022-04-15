#include <bits/stdc++.h>
using namespace std;

int transitionPoint(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], i;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << transitionPoint(a, n) << endl;
    }
    return 0;
}// } Driver Code Ends


int transitionPoint(int arr[], int n) {
    // code here
    //int index = lower_bound(arr,arr+n,1);
    int low=0,high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]==1)
        {
            int j=mid;
            while(arr[j]==1 && j>=0)
            j--;
            return j+1;
        }
        else if(arr[mid]<1)
        low=mid+1;
        else
        high=mid-1;
    }
    return -1;
    
}