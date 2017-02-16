#include <stdio.h>

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

int main()
{
    int n=1000;
    int a[n];
    int i;
    for(i=0;i<n;i++) {
        a[i]=i+1;
    }
    printf("Enter a element to search : \n");
    scanf("%d",&i);
    int at = halfTernarySearch(a,0,n-1,i);
    if(at>=0)
        printf("Element found at %d \n",at+1);
}
