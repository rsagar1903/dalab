#include<stdio.h>

int s[10] , x[10] , d;
void sumofsubset(int , int , int);
void main()
{
    int n,sum = 0;
    printf("Enter the size of the set : ");
    scanf("%d" , &n);
    printf("\n Enter the set in increasing order : \n");
    for (int i = 1; i <= n; i++)
    {
        scanf("%d" , &s[i]);
    }
    printf("Enter the value of d : ");
    scanf("%d" , &d);
    for (int i = 1; i <= n; i++)
    {
        sum = sum+s[i];
    }
    if (sum<d || s[1] > d)
    {
        printf("No Subset possible");
    }
    else{
        sumofsubset(0 , 1 , sum);
    }
    
}

void sumofsubset(int m , int k , int r){
    int i = 1;
    x[k] = 1;
    if((m+s[k]) == d){
        printf("Subset : ");
        for ( i = 1; i <= k; i++)
        {
            if(x[i]==1){
                printf("\t%d" , s[i]);
            }
        }
        printf("\n");
    }
    else{
        if(m+s[k] + s[k+1]<=d){
            sumofsubset(m+s[k] , k+1 , r-s[k]);
        }
        if((m+r-s[k]>=d) && (m+s[k+1]<=d)){
            x[k]=0;
            sumofsubset(m , k+1 , r-s[k]);
        }
    }
}

