#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
	for(i=0;i<n-1;i++) {
		for(j=i+1;j>0;j--) {
			if(a[j] <= a[j-1]) {
				temp=a[j];
				a[j] = a[j-1];
				a[j-1]=temp;
				swapCount++;
			} else break;	
		}
	}
	end_t = clock();    
	for(i=0;i<n;i++) {
		printf("%d \n",a[i]);
	}
	printf("Total Swapped in INSERTION: %d \n",swapCount++);		
	total_t = ((double)(end_t - start_t) / CLOCKS_PER_SEC)*CLOCKS_PER_SEC;
    printf("Total time taken by CPU: %f\n", (double)total_t/(double)CLOCKS_PER_SEC );
}