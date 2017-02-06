#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int swapCount=0;

int merge_list(int a[],int l,int m,int h);

int merge_sort(int a[],int l,int h) {    
    if(l<h){
        int mid = (l+h)/2;
        merge_sort(a,l,mid);
        merge_sort(a,mid+1,h);
        merge_list(a,l,mid,h);
    }
}

int merge_list(int a[],int lo,int m,int hi) {
    int i,j,k,ln,rn;
    ln = m-lo+1;
    rn = hi-m;
    int l[ln],r[rn];
    i=j=0;
    k=lo;
    for(i=0;i<ln;i++) 
        l[i]=a[lo+i];
    for(i=0;i<rn;i++)
        r[i]=a[m+1+i];
    i=j=0;
    while( i<ln && j<rn) {
        if(l[i]<=r[j]) {
            a[k]=l[i];
            i++;
        } else {
            a[k]=r[j];
            j++;
        }
        swapCount++;
        k++;
    }

    while(i<ln) {
        a[k]=l[i];
        k++;
        i++;
    }
    while(j<rn) {
        a[k]=r[j];
        k++;
        j++;
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
    merge_sort(a,0,n-1);  
    end_t = clock();
    for(i=0;i<n;i++) {
        printf("%d \n",a[i]);
    }

    printf("Total Swapped in MergeSort: %d \n",swapCount++);	
    total_t = ((double)(end_t - start_t) / CLOCKS_PER_SEC)*CLOCKS_PER_SEC;
    printf("Total time taken by CPU: %f\n", (double)total_t/(double)CLOCKS_PER_SEC );
}