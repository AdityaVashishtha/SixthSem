#include <stdio.h>
#include <stdlib.h>

#define MAX 100000
int count=0;

int main() {
	int n,i;
	printf("Enter Number of elements\n");
	scanf("%d",&n);
	int x=n;
	int hash[x];
	for(i=0;i<x;i++) {
		hash[i]=0;
	}
	int a[n];
	for(i=0;i<n;i++) {
		scanf("%d",&a[i]);		
		hash[a[i]]++;
	}
	int m=0;
	int index=0;
	for(i=0;i<x;i++) {
		if(m < hash[i])
		{
			m=hash[i];
			index=i;
		}
	}
	if(m>(n/2))
		printf("%d IS MAJORITY ELEMENT\n",index);
	else 
		printf("No MAJORITY ELEMENT\n");
}
