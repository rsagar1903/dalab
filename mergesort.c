#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int arr[] , int l , int m , int r){
    int i , j , k;
    int n1 = m - l + 1;
    int n2 = r-m;
    int L[n1] , R[n2];
    for ( i = 0; i < n1; i++)
    {
        L[i] = arr[l+i];
    }
    for ( j = 0; j < n2; j++)
    {
        R[j] = arr[m+1+j];
    }
    i = 0 , j = 0 , k = 1;
    while (i<n1 && j<n2)
    {
        if(L[i]<=R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i<n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j<n2)
    {
        arr[k] =R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[] , int l , int r){
    if(l<r){
        int m = l + (r - l) / 2;
        mergeSort(arr , l , m);
        mergeSort(arr , m + 1, r);

        merge(arr , l , m , r);
    }
}

int main()
{
    int n;
    clock_t start, end;
    double cpu_time_used;
    printf("Enter the value of n : ");
    scanf("%d" , &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand()%1000;
        printf("%d ",arr[i]);
    }
    start = clock();
    mergeSort(arr , 0 , n-1);
    end = clock();
    cpu_time_used = ((double)(end-start))/CLOCKS_PER_SEC;

    printf("\nSorted array : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d " , arr[i]);
    }
    
    printf("\nExecution time : %f" , cpu_time_used);

return 0;
}