#include <stdio.h>
#include <time.h>

void ternarySearch(int a[],int x,int l,int r) {
    if(l<=r) {
        int ot = l + (r-l)/3;
        int tt = l + 2*(r-l)/3;
        //printf("%d  %d %d\n",ot,tt,a[ot]);
        if(a[ot]==x)
            printf("Found %d\n",x);        
        else if(a[ot]>x)
            ternarySearch(a,x,l,ot-1);            
        else if(a[tt]==x)
            printf("Found %d\n",x);        
        else if(a[tt]>x)
            ternarySearch(a,x,ot+1,tt-1);
        else
            ternarySearch(a,x,tt+1,r);
    } else {
        printf("Not Found");
    }
}


int main() {
    clock_t start_t, end_t, total_t;    
    int n=100;
    printf("Enter a element to search : \n");
    scanf("%d",&n);
    int a[n];
    int i;
    for(i=0;i<n;i++) {
        a[i]=i;
    }    
    start_t = clock();
    ternarySearch(a,n/2,0,n-1);
    end_t = clock();    
    total_t = ((double)(end_t - start_t) / CLOCKS_PER_SEC)*CLOCKS_PER_SEC;
    printf("Total time taken by CPU: %f\n", (double)total_t/(double)CLOCKS_PER_SEC );
}