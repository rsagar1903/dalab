#include<stdio.h>

void warshall(int p[10][10] , int n){
    for (int k = 1; k <= n; k++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int i = 1; i <= n; i++)
            {
                if ((p[i][j] == 0) && (p[i][k] == 1) && (p[k][j]==1))
                {
                    p[i][j] = 1;
                }
                
            }
            
        }
        
    }
    
    printf("The path matrix\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%d\t" , p[i][j]);
        }
        printf("\n");
    }
    

}
int main()
{
    int a[10][10] , n ;
    printf("Enter the number of nodes : ");
    scanf("%d" , &n);
    printf("\nEnter adjacency matrix : \n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d" , &a[i][j]);
        }
        
    }
    printf("The adjacency matrix : \n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%d " , a[i][j]);
        }
        printf("\n");
    }
    warshall(a , n);

return 0;
}