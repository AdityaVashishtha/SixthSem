#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int countsort(int a[],int n,int max) {
    int count[max];
    int i=0;
    int output[n];
    for(i=0;i<max;i++) {
        output[i]=count[i]=0;
    }
    for(i=0;i<n;i++) {
        count[a[i]]++; 
    }        

    int total=0;
    int oldtotal=0;
    for(i=0;i<max;i++) {
        oldtotal = count[i];
        count[i] = total;
        total += oldtotal;
    }

    for(i=0;i<n;i++) {
        output[count[a[i]]]=a[i];
        count[a[i]]++; 
    }

    for(i=0;i<n;i++) {
        a[i] = output[i];
    }

}

int main() {
    clock_t start_t, end_t, total_t;
    int i,n;    
    printf("Enter number of element to test : \n");
    scanf("%d",&n);
    int a[n];
    int max = n*10;
    for(i=0;i<n;i++) {
        a[i]= n-i;//rand()%n*10+1;
    }
    start_t = clock();
    countsort(a,n,max);  
    end_t = clock();
    for(i=0;i<n;i++) {
        printf("%d \n",a[i]);
    }    
    total_t = ((double)(end_t - start_t) / CLOCKS_PER_SEC)*CLOCKS_PER_SEC;
    printf("Total time taken by CPU in: %f\n", (double)total_t/(double)CLOCKS_PER_SEC );
}