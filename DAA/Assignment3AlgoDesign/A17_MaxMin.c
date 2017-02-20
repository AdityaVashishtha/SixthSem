#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void MaxMin(int a[],int l,int r,int * m,int * mi) {
	int max=*m;
	int min = *mi;
	if(l==r)
		max=min=a[l];
	else if(l==r-1) {
		if(a[l]>a[r]) {
			max=a[l];
			min=a[r];			
		} else {
			min=a[l];
			max=a[r];
		}
	}
	else {
		int max1,min1;
		int mid = l + (r-l)/2;
		MaxMin(a,l,mid,&max,&min);
		MaxMin(a,mid+1,r,&max1,&min1);
		if(min1<min)
			min=min1;
		if(max1>max)
			max=max1;

	}	
	*m=max;
	*mi=min;
}

int main() {
	clock_t start_t, end_t, total_t;    
	printf("Enter Number of Input\n");
	int n,i;	
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++) {
		a[i]= rand()%n+1;
	}
	for(i=0;i<n;i++) {
		printf(" %d ",a[i]);
	}
	printf("\n");
	int max;
	int min;
	start_t = clock();
	MaxMin(a,0,n-1,&max,&min);
	end_t = clock();    
	printf("Max %d, Min %d \n",max,min);
	total_t = ((double)(end_t - start_t) / CLOCKS_PER_SEC)*CLOCKS_PER_SEC;
    printf("Total time taken by CPU: %f\n", (double)total_t/(double)CLOCKS_PER_SEC );
}
