#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getMax(int arr[], int n)
{
    int mx = arr[0];
    int i;
    for (i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
int countsort(int a[],int n,int exp) {    
    int count[10];
    int i=0;
    int output[n];
    for(i=0;i<10;i++) {
        count[i]=0;
    }

    for(i=0;i<n;i++) {
        count[ (a[i]/exp)%10 ]++; 
    }        

    int total=0;
    int oldtotal=0;
    for(i=0;i<10;i++) {
        oldtotal = count[i];
        count[i] = total;
        total += oldtotal;
    }

    for(i=0;i<n;i++) {
        output[count[ (a[i]/exp)%10 ]]=a[i];
        count[  (a[i]/exp)%10 ]++; 
    }

    for(i=0;i<n;i++) {
        a[i] = output[i];
    }

}
void radixsort(int a[],int n) {
    int max = getMax(a, n);
    int exp;
    for (exp = 1; max/exp > 0; exp *= 10)
        countsort(a, n, exp);
}

int main() {
    clock_t start_t, end_t, total_t;
    int i,n;    
    printf("Enter number of element to test : \n");
    scanf("%d",&n);
    int a[n];
    int max = n*10;
    for(i=0;i<n;i++) {
        a[i]= n-i;// rand()%n*10 +1;
    }
    start_t = clock();
    radixsort(a,n);  
    end_t = clock(); 
    total_t = ((double)(end_t - start_t) / CLOCKS_PER_SEC)*CLOCKS_PER_SEC;
    printf("Total time taken by CPU in: %f\n", (double)total_t/(double)CLOCKS_PER_SEC );
}
