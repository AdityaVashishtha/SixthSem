#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int arr[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;
        
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}

//INSERTION
int main() {
	clock_t start_t, end_t, total_t;
	printf("Enter total numbers \t");
	int n;
	scanf("%d",&n);
	int a[n];	
	int i,j,flag,temp;
	flag=1;
	for(i=0;i<n;i++) {
		a[i] = n-i;//(rand()%n*10) +1;
	}
	start_t = clock();
	int swapCount=0;
	insertionSort(a,n);
	
	end_t = clock();    
	for(i=0;i<n;i++) {
		printf("%d \n",a[i]);
	}
	printf("Total Swapped in INSERTION: %d \n",swapCount++);		
	total_t = ((double)(end_t - start_t) / CLOCKS_PER_SEC)*CLOCKS_PER_SEC;
    printf("Total time taken by CPU: %f\n", (double)total_t/(double)CLOCKS_PER_SEC );
}
