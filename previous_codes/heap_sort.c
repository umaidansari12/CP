#include <stdio.h>
#include <malloc.h>
  
void heapify(int arr[], int n, int i) 
{ 
    int largest = i,temp; 
    int l = 2*i + 1; 
    int r = 2*i + 2;   
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
    if (largest != i) 
    { 
    	temp=arr[i];
    	arr[i]=arr[largest];
    	arr[largest]=temp;
        heapify(arr, n, largest); 
    } 
} 
  
void heapSort(int arr[], int n) 
{ 
	int i,temp;
    for (i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    for (i=n-1; i>0; i--) 
    { 
       	temp=arr[0];
       	arr[0]=arr[i];
       	arr[i]=temp;
        heapify(arr, i, 0); 
    } 
} 
  
int main() 
{ 
    int *a,n,i;
	printf("Enter Size of the Array : ");
	scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Elements Before Sorting  :\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	heapSort(a, n); 
	printf("\nElements After Sorting  :\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
} 
