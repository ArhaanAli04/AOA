#include<stdio.h>
#define INF 999
void printMatrix(int n,int matrix[][n]){
    printf("\nThe matrix is given by:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==INF){
                printf("%4s","INF");
            }else{
                printf("%4d ",matrix[i][j]);
            }
        }printf("\n");
    }
}

void FloydWarshal(int n,int graph[][n]){
    int matrix[n][n],i,j,k;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            matrix[i][j]=graph[i][j];
        }
    }

    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(matrix[i][k]+matrix[k][j]<matrix[i][j]){
                    matrix[i][j]=matrix[i][k]+matrix[k][j];
                }
            }
        }
    }
    printMatrix(n,matrix);
}
int main(){
    int n;
    printf("Enter the number of vertices in the graph:");
    scanf("%d",&n);
    int graph[n][n];
    printf("Enter the elements :");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    printMatrix(n,graph);
    FloydWarshal(n,graph);
    

    return 0;
}