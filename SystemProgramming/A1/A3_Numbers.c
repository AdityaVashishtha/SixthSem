#include <stdio.h>
#include <stdlib.h>

/*Global array declare for sorting and each line numbers*/
int X[10],Y[10],k=0,arr[100];


void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    i = 0;
    j = 0;
    k = l;
    while(i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}

/*delete line using temporary file*/
void deleteLine(int lineNo){
    FILE *fileptr1, *fileptr2;
    char ch;
    int temp = 1;
    fileptr1 = fopen("data.txt", "r");
    fileptr2 = fopen("temp.txt", "w");
    while((ch=getc(fileptr1))!=EOF)
    {
        if (ch=='\n')
            temp++;
            if(temp!=lineNo)
            {
                putc(ch,fileptr2);
            }
    }
    fclose(fileptr1);
    fclose(fileptr2);
    remove("data.txt");
    rename("temp.txt", "data.txt");
}


int main(){
	char ch;
	int data,i=0,c,x,flag=0;
	FILE *fp=fopen("numbers.txt","r");
	FILE *fptr=fopen("data.txt","w");
	while(fscanf(fp,"%d%c",&data,&ch)!=EOF){		
		if(i==10){
			i=0;
			fprintf(fptr, "\n");
		}
		fprintf(fptr, "%d ",data);
		i++;
	}

	printf("Enter a number to search");
	scanf("%d",&x);
	i=0,c=1;
	fseek(fptr, 0, SEEK_SET);
	fptr=fopen("data.txt","r+");
	
	while(fscanf(fptr,"%d",&data)!=EOF){
		if(i==10){
			c++,i=0;
		}
		if(data==x){
			printf("Number found at: \n");
			printf("Line  :- %d\n",c);
			printf("Position :- %d\n",i+1);
			flag=1;
	        fseek(fptr, -2, SEEK_CUR);
		   	fprintf(fptr, "%d",x+1);
		   	X[k]=c;
		   	Y[k]=i+1;
		   	k++;
		}
		i++;
	}
	if(!flag)
		printf("Number not found in file\n");	


	if(flag) {
		printf("Do you want to delete the line containing, %d (1/0)\n",x);
		scanf("%d",&c);
		if(c==1){
			for(int i=0;i<k;i++){
				deleteLine(X[i]-i);
			}
		}
	}

	printf("sort numbers (result in numbers2.txt)(1/0)\n");
	scanf("%d",&c);
	if(c==1){
		rewind(fptr);
 	fptr=fopen("data.txt","r");

	k=0;
	while(fscanf(fptr,"%d",&arr[k++])!=EOF);
	mergeSort(arr, 0, k - 1);
	fp=fopen("numbers2.txt","w");
	rewind(fp);
	c=0;
		while(c<k){
			if(i==10){
				i=0;
				fprintf(fp, "\n");
			}
			fprintf(fp, "%d ",arr[c]);
			i++;
			c++;
		}
	}
	return 0;
}

