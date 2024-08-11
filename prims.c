#include<stdio.h>

void myprims(int adj[][10],int N ){
    int i , j , min , u = 0 , v = 0 , nv , min_cost = 0;
    int visit[10] = {0};
    visit[0] = 1;
    nv = 1;
    while (nv<N)
    {
        min = 999;
        for ( i = 0; i < N; i++)
        {
            if(visit[i] == 1){
                for ( j = 0; j < N; j++)
                {
                    if(adj[i][j]<min){
                        min = adj[i][j];
                        adj[i][j] = 999;
                        u = i;
                        v = j;
                    }
                }
                
            }
        }
        if(visit[u] == 1 && visit[v] == 0){
            visit[v] = 1;
            min_cost+=min;
            nv++;
            printf("Edge %d - %d : (%d)\n" , u , v , min);
        }
        
    }
    
}

int main()
{
    int adj[10][10] , N , i , j;
    printf("Enter the number of nodes in the graph : ");
    scanf("%d" , &N);
    printf("Enter the adjacency matrix : ");
    printf("Enter 0 for no connection and 1 for connection : ");
    for ( i = 0; i < N; i++)
    {
        for ( j = 0; j < N; j++)
        {
            scanf("%d" , &adj[i][j]);
            if (adj[i][j]==0)
            {
                adj[i][j] = 999;
            }
            
        }
        
    }
    myprims(adj , N);
    
return 0;
}