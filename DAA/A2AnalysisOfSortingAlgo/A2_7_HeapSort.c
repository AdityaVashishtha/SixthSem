#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void heapify(int a[],int n,int i) {
    int max = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left < n && a[left] > a[max])
        max = left;
    if(right < n && a[right] > a[max])
        max = right;
    
    if(max != i) {
        int temp;
        temp = a[i];
        a[i] = a[max];
        a[max] = temp;
        heapify(a,n,max);
    }        
}

void heapsort(int a[],int n) {
    int h = n/2-1;
    int i=0;
    for(i=h; i>=0 ; i--)
        heapify(a,n,i);
    for(i=n-1;i>=0;i--) {
        int temp;
        temp = a[i];
        a[i] = a[0];
        a[0] = temp;
        heapify(a,i,0);
    }
}

int main() {
    clock_t start_t, end_t, total_t;
    int i,n;    
    printf("Enter number of element to test : \n");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++) {
        a[i]= n-i;//(rand()%n*10) +1;
    }
    start_t = clock();
    heapsort(a,n);  
    end_t = clock();
    for(i=0;i<n;i++) {
        printf("%d \n",a[i]);
    }

    //printf("Total Swapped in MergeSort: %d \n",swapCount++);	
    total_t = ((double)(end_t - start_t) / CLOCKS_PER_SEC)*CLOCKS_PER_SEC;
    printf("Total time taken by CPU in: %f\n", (double)total_t/(double)CLOCKS_PER_SEC );
}