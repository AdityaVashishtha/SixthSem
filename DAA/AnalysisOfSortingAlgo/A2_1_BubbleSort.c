#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//BUBBLE
int main() {
	clock_t start_t, end_t, total_t;
	printf("Enter total numbers \t");
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
	for(i=1;i<n && flag == 1;i++) {
		flag =0;
		for(j=0;j<n-i;j++) {		
			if(a[j]>a[j+1]) {
				temp=a[j];
				a[j] = a[j+1];
				a[j+1]=temp;
				flag = 1;
				swapCount++;
			}
		}		
	}
	end_t = clock();    
	for(i=0;i<n;i++) {
		printf("%d \n",a[i]);
	}
	printf("Total Swapped: %d \n",swapCount++);	
	total_t = ((double)(end_t - start_t) / CLOCKS_PER_SEC)*CLOCKS_PER_SEC;
    printf("Total time taken by CPU: %f\n", (double)total_t/(double)CLOCKS_PER_SEC );
}