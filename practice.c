#include<stdio.h>
#define INF 999
void printMatrix(int n,int matrix[n][n]){
    printf("The matrix is given by: ");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",matrix[i][j]);
        }printf("\n");
}
    }
int min(int a,int b){
    if(a<b){
        return a;
    }else{
        return b;
    }
}
int tsp(int n,int graph[n][n],int visited,int pos,int count,int cost){
    if(count==n && graph[pos][0]){
        return cost+graph[pos][0];
    }
    int min_cost=INF;
    for(int i=0;i<n;i++){
         if((visited &(1<<i))==0 && graph[pos][i]){
            min_cost=min(min_cost,tsp(n,graph,visited |(1<<i),i,count+1,cost+graph[pos][i]));
         }
    }
    return min_cost;
}
int main(){
    int n;
    printf("Enter the number od nodes in the graph: ");
    scanf("%d",&n);
    int graph[n][n];
    printf("\nEnter the cost adjacency matrix:");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    printMatrix(n,graph);
    int visited=1<<0;
    int min_cost=tsp(n,graph,visited,0,1,0);
    printf("\nThe minimum cost is given by: %d",min_cost);
    return 0;
}