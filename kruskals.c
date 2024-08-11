#include<stdio.h>
int ne = 1 , min_cost = 0;
void main()
{
    int n, i , j , min , a , b , u , v , cost[20][20] , parent[20];
    printf("Enter the number of nodes : ");
    scanf("%d" , &n);
    printf("Enter the cost matrix : ");
    for ( i = 1; i <= n; i++)
    {
        for ( j = 1; j <= n; j++)
        {
            scanf("%d" , &cost[i][j]);
        }
        
    }

    for ( i = 1; i <= n; i++)
    {
        parent[i] = 0;
    }

    printf("The edges of the spanning tree : ");
    while (ne<n)
    {
        min = 999;
        for ( i = 1; i <= n; i++)
        {
            for ( j = 1; j <= n; j++)
            {
                if (cost[i][j]<min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
                
            }
            
        }
        while (parent[u])
        {
            u = parent[u];
            printf("The value of u is : %d" , u);
        }

        while (parent[v])
        {
            v = parent[v];
            printf("The value of v is : %d" , v);
        }
        if(u!=v){
            printf("\nEdge %d\t(%d->%d) = %d\n" , ne++ , a , b , min);
            min_cost = min_cost + min;
            parent[v] = u;
        }
        cost[a][b] = cost[b][a] = 999;
        
    }
    printf("\nMinimum Cost  = %d" , min_cost);


}