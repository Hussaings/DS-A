//Complexity O(nlogn)

#include<stdio.h>
#include<stdlib.h>

void merge(int a[],int l,int m,int r)
{
int i,j,k;
int n1=m-l+1;
int n2=r-m;

int Left[n1],Right[n2];

for (i = 0; i < n1; i++)
        Left[i] = a[l + i];
for (j = 0; j < n2; j++)
        Right[j] = a[m + 1+ j];

        i=0;
        j=0;
        k=l;

    while(i<n1 && j<n2)
    {
    if (Left[i] <= Right[j])
        {
            a[k] = Left[i];
            i++;
        }
        else
        {
            a[k] = Right[j];
            j++;
        }
        k++;

    }

     while (i < n1)
    {
        a[k] = Left[i];
        i++;
        k++;
    }


    while (j < n2)
    {
        a[k] = Right[j];
        j++;
        k++;
    }
}


void MergeSort(int a[],int l,int r)
{
int m;
if(l<r)
{
m=l+(r-l)/2;
MergeSort(a,l,m);
MergeSort(a,m+1,r);

merge(a,l,m,r);
}

}

void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, arr_size);

    MergeSort(arr, 0, arr_size - 1);

    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}





