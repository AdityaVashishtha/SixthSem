#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//SELECTION
int main() {
	clock_t start_t, end_t, total_t;
	printf("ENTER NUBMER OF ELEMENTS \t");
	int n;
	scanf("%d",&n);
	int a[n];	
	int i,j,flag,temp;
	flag=1;
	for(i=0;i<n;i++) {
		a[i] = (rand()%n*10) +1;
	}
	start_t = clock();
	int swapCount=0;
	
	for (i = 0; i < n-1; i++) 
	{		
		int iMin = i;
		for (j = i+1; j < n; j++) {
			if (a[j] < a[iMin]) {
					iMin = j;
			}
		}
		if(iMin != i) 
		{
			temp = a[iMin];
			a[iMin]=a[j];
			a[j]=temp;			
			swapCount++;			
		}
	}


	end_t = clock();    
	for(i=0;i<n;i++) {
		printf("%d \n",a[i]);
	}
	printf("Total Swapped in Selection: %d \n",swapCount++);	
	total_t = ((double)(end_t - start_t) / CLOCKS_PER_SEC)*CLOCKS_PER_SEC;
    printf("Total time taken by CPU: %f\n", (double)total_t/(double)CLOCKS_PER_SEC );
}
