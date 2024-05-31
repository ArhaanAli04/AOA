#include<stdio.h>
#define MAX 9999
int minKey(int n,int key[],int mstSet[]){
    int min=MAX;
    int min_index;
    for(int i=0;i<n;i++){
        if(mstSet[i]==0 && key[i]<min){
            min=key[i];
            min_index=i;
        }
    }
    return min_index;
}
void printMST(int n,int parent[],int graph[n][n]){
    printf("Edge   Weight\n");
    for(int i=0;i<n;i++){
        printf("%d - %d  %d\n",parent[i],i,graph[i][parent[i]]);
    }
}
void primMST(int n,int graph[n][n]){
    int parent[MAX];
    int key[MAX];
    int mstSet[MAX];
    //all vertices are not yet included in the MST
    for(int i=0;i<n;i++){
        key[i]=MAX;
        mstSet[i]=0;
    }
    key[0]=0;
    parent[0]=-1;

    for(int count=0;count<n-1;count++){
        int u=minKey(n,key,mstSet);
        mstSet[u]=1;
        for(int v=0;v<n;v++){
            if(graph[u][v] && mstSet[v]==0 && graph[u][v]<key[v]){
                parent[v]=u;
                key[v]=graph[u][v];
            }
        }
    }
    printMST(n,parent,graph);

}



int main(){
    int n;
    printf("Enter the number of vertices in the graph:");
    scanf("%d",&n);
    int graph[n][n];
    printf("\nEnter the matrix:");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           scanf("%d",&graph[i][j]);
        }
        
    }
    return 0;
}