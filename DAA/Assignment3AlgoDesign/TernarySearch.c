#include <stdio.h>

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
    int n=1000;
    int a[n];
    int i;
    for(i=0;i<n;i++) {
        a[i]=i;
    }
    printf("Enter a element to search : \n");
    scanf("%d",&i);
    ternarySearch(a,i,0,n-1);
}