#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector <int> a, int item, int low, int high) 
{ 
    if (high <= low) 
        return (item > a[low])?  (low + 1): low; 
  
    int mid = (low + high)/2; 
  
    if(item == a[mid]) 
        return mid+1; 
  
    if(item > a[mid]) 
        return binarySearch(a, item, mid+1, high); 
    return binarySearch(a, item, low, mid-1); 
} 
  
// Function to sort an array a[] of size 'n' 
void insertionSort_binary(int n,vector<int> a) 
{ 
    int i, loc, j, k, selected; 
  
    for (i = 1; i < n; ++i) 
    { 
        j = i - 1; 
        selected = a[i]; 
        cout<<"Selected : "<<selected;
        // find location where selected sould be inseretd 
        loc = binarySearch(a, selected, 0, j); 
        cout<<"Location : "<<loc<<" ";

  
        // Move all elements after location to create space 
        while (j >= loc) 
        { 
            a[j+1] = a[j]; 
            j--; 
        } 
        a[j+1] = selected; 
        cout<<i<<"Pass : ";
        for(auto j:a)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    } 
    cout<<"Sorted Array :";
    for(auto j:a)
    {
        cout<<j<<" ";
    }
    cout<<endl;
} 

void insertionSort(int n,vector<int> arr)  
{  
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
  
        /* Move elements of arr[0..i-1], that are  
        greater than key, to one position ahead  
        of their current position */
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
        cout<<i<<"Pass : ";
        for(auto j:arr)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }  
     cout<<"Sorted Array :";
    for(auto j:arr)
    {
        cout<<j<<" ";
    }
    cout<<endl;
    
}  

void insertion(int n,vector<int> arr)
{
    for(int i=n-1;i>=0;i--)
    {
        int j=i;
        while(j>0 && arr[j]<arr[j-1])
        {
            int temp=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=temp;
            j--;
        }
        cout<<i-n+1<<"Pass : ";
        for(auto j:arr)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<"Sorted Array :";
    for(auto j:arr)
    {
        cout<<j<<" ";
    }
    cout<<endl;
}

void insertion_sort(int n,vector<int> arr)
{
    for(int i=1;i<n;i++)
    {
        int j=i-1;
        while(j>=0 && arr[j]>arr[j+1])
        {
            int temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
            j--;
        }
        cout<<i<<"Pass : ";
        for(auto j:arr)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<"Sorted Array :";
    for(auto j:arr)
    {
        cout<<j<<" ";
    }
    cout<<endl;
}

void insert_sorted(int n,vector <int> arr)
{
    int temp=arr[n-1];//picks up the rightmost element and place it in its appropriate position because the array is sorted 
    int i=n-1;
    while(i>=0 && arr[i]<arr[i-1])
    {
        arr[i]=arr[i-1];
        arr[i-1]=temp;
        i--;
    }
    cout<<"Sorted Array :";
    for(auto j:arr)
    {
        cout<<j<<" ";
    }
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int item;
    cin>>item;
    int loc=binarySearch(a,item,0,a.size());
    cout<<loc;
}