#include <stdio.h>
#include <time.h>

int halfTernarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
    		int mid = l + (r - l)/3;
    		if (arr[mid] == x) return mid;
    		if (arr[mid] > x) return halfTernarySearch(arr, l, mid-1, x);
    		return halfTernarySearch(arr, mid+1, r, x);
    }
    printf("Element NOT found \n");
    return -1;
}

int main() {
    clock_t start_t, end_t, total_t;    
    int n=1000;
    printf("Enter a element to search : \n");
    scanf("%d",&n);
    int a[n];
    int i;
    for(i=0;i<n;i++) {
        a[i]=i+1;
    }    
    i=n+1;
    start_t = clock();
    int at = halfTernarySearch(a,0,n-1,i);
    end_t = clock();    
    if(at>=0)
        printf("Element found at %d \n",at+1);
    total_t = ((double)(end_t - start_t) / CLOCKS_PER_SEC)*CLOCKS_PER_SEC;
    printf("Total time taken by CPU: %f\n", (double)total_t/(double)CLOCKS_PER_SEC );
}
