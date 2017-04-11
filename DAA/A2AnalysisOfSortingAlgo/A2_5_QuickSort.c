#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int swapCount=0;

void quickSort(int arr[], int left, int right) {
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];

      /* partition */
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
                  swapCount++;
            }
      };

      if (left < j)
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);
}

int main() {
    clock_t start_t, end_t, total_t;
    int i,n;    
    printf("Enter number of element to test : \n");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++) {
        a[i]= (rand()%n*10) +1;
    }
    start_t = clock();
    quickSort(a,0,n-1);  
    end_t = clock();
    for(i=0;i<n;i++) {
        printf("%d \n",a[i]);
    }


    printf("Total Swapped in QuickSort: %d \n",swapCount++);	
    total_t = ((double)(end_t - start_t) / CLOCKS_PER_SEC)*CLOCKS_PER_SEC;
    printf("Total time taken by CPU: %f\n", (double)total_t/(double)CLOCKS_PER_SEC );
}