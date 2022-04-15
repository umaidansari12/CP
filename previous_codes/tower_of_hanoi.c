#include <stdio.h>

void tower_of_hanoi(int n, int from, int to, int aux)
{
	if (n == 1)
	{
		printf("Move disk 1 from rod %d to rod %d\n",from,to);
		return;
	}
	tower_of_hanoi(n - 1, from, aux, to);
	printf("Move disk %d from rod %d to rod %d\n",n,from,to);
	tower_of_hanoi(n - 1, aux, to, from);
}

void main()
{
	int n;
	printf("Enter Number of Disks : ");
	scanf("%d",&n);
	tower_of_hanoi(n, 1, 3, 2);
}
