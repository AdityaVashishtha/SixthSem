#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int MaxJump(int a[],int l,int r,int * m,int * mi) {
    int max = *m;
	int min = *mi;
    //printf("%d %d\n",max,min);
    int diff=0;
    if(l==r) {
        max=min=a[l];
        diff=0;
    } else if (l == (r-1)) {
        diff = a[r]-a[l];
        if(a[l]>a[r]) {
			max=a[l];
			min=a[r];			
		} else {
			min=a[l];
			max=a[r];
		}
    } else {
        int max1,min1;
        int mid = l + (r-l)/2;
        int diff1,diff2,diff3;
        diff1=MaxJump(a,l,mid,&max,&min);
        diff2=MaxJump(a,mid+1,r,&max1,&min1);
        diff3=max1-min;
        if(diff1>diff2) {
            if(diff1>diff3) {
                diff=diff1;                
            } else {
                diff=diff3;
                max=max1;                
            }
        } else {
            if(diff2>diff3) {
                diff=diff2;
                max=max1;
                min=min1;
            } else {
                diff=diff3;
                max=max1;                
            }
        }        
    }
    *m = max;
    *mi = min;
    return diff;
}

int main() {
    clock_t start_t, end_t, total_t;    
    printf("Enter Number of Input\n");
	int n,i;	
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++) {
		a[i]= rand()%n+1;
        //scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++) {
		printf(" %d ",a[i]);
	}
	printf("\n");
	int max;
	int min;
    start_t = clock();
	int diff = MaxJump(a,0,n-1,&max,&min);
    end_t = clock();    
	printf("Max %d, Min %d,diff %d \n",max,min,diff);
    total_t = ((double)(end_t - start_t) / CLOCKS_PER_SEC)*CLOCKS_PER_SEC;
    printf("Total time taken by CPU: %f\n", (double)total_t/(double)CLOCKS_PER_SEC );
}