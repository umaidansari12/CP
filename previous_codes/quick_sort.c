#include <stdio.h>
#include <malloc.h>

int partition(int arr[],int low,int high)
{
	int pivot=arr[high],i=low-1,j=low;
	for(j=low;j<=high;j++)
	{
		if(arr[j]<pivot)
		{
			i++;
			int temp=arr[j];
			arr[j]=arr[i];
			arr[i]=temp;
		}
	}
	int temp=arr[high];
	arr[high]=arr[i+1];
	arr[i+1]=temp;
	return i+1;
}

void quickSort(int arr[],int low,int high)
{
	if(low<high)
	{
		int p=partition(arr,low,high);
		quickSort(arr,low,p-1);
		quickSort(arr,p+1,high);
	}
}


void main()
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
	quickSort(a,0,n-1);
	printf("\nElements After Sorting  :\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
}

